import numpy as np
import scipy
from scipy.io import wavfile
import sys

# 設定
sys.path.append(".")
if len(sys.argv) < 2:
    print("No output file name.")
    exit()
outputfile = sys.argv[1]
rate = 44100
bpm = 143
cuttime = 0.02

# 音生成器
def sin_sound(phases):
    return np.sin(phases)

def kukei_sound(phases):
    return np.sign(np.sin(phases))

def small_pulce(thresh, phases):
    return np.sign(np.sin(phases)-thresh)

def gen_small_pulce(duty):
    if duty <= 0.5:
        p = duty / 0.5
        thresh = np.sin(0.5*np.pi + 0.5 * p * np.pi)
    return (lambda x:small_pulce(thresh,x))

def triangle(phases):
    return abs((phases/(2.0*np.pi))%1-0.5)*(-4.0)+1.0

def triangle_8bit(phases):
    return ((2**8-1) * (2*abs((phases/4)%1-0.5))).astype('uint8')/(2**8-1) * (-2.0)+1

sound_players = [
    gen_small_pulce(0.5),
    gen_small_pulce(0.25),
    gen_small_pulce(0.125),
    triangle,
    triangle #TODO
    ]
play_sound = sound_players[0]

# 音楽生成
music = np.array([])
is_append_mode = False
anchor_library = []
pointer = 0

def cat(a,b):
    return np.concatenate([a,b])

def sound(freq, length, volume, cut):
    global music, pointer
    seconds = (length / 4.0) / bpm * 60
    if cut:
        seconds -= cuttime
    wav_len = int(rate*seconds)
    phases = np.cumsum(2.0 * np.pi * freq / rate * np.ones(wav_len))
    if freq == 0.0:
        wav = np.zeros(wav_len)
    else:
        wav = volume * play_sound(phases)
    if cut:
        nothing = np.zeros(int(rate * cuttime))
        wav = cat(wav, nothing)
    if is_append_mode:
        l = len(wav)
        music[pointer:pointer+l] += wav
        pointer += l
    else:
        music = cat(music, wav)

# 音楽生成に関わるcppコードからの指令
def set_sound_type(s):
    global play_sound
    play_sound = sound_players[s]

def set_anchor(stamp):
    global anchor_library
    anchor_library.append([stamp, length(music)])

def start_append_mode(anchor_stamp):
    global is_append_mode, pointer
    is_append_mode = True
    pinter = -1
    for [stamp, anchor] in anchor_library:
        if anchor_stamp == stamp:
            pointer = anchor
            break
    if pointer < 0:
        print('Error: anchor not found', file=sys.stderr)
        exit()

def end_append_mode():
    global is_append_mode
    is_append_mode = False

# 実行
from written_score import *

play_music(sound, set_sound_type, start_append_mode, end_append_mode)

print("end play sound")
print(music.shape)
music = (float(2**10 - 1) * music).astype(np.int16)
wavfile.write(outputfile, rate, music)

