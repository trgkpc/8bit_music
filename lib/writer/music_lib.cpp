#include "music_lib.hpp"
#include <vector>

std::array<double, 12> freq_dict{261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440.000, 466.164, 493.883};

double frequency(const int& f)
{
    if (f == Rest) {
        return 0.0;
    } else {
        int p = f - DO;
        int a = p / 12;
        int b = p % 12;
        if (b < 0) {
            b += 12;
            a--;
        }
        return freq_dict[b] * pow(2.0, a);
    }
}

Sound last_sound{INIT, 0, 1.0, false};
double default_volume = 1.0;
int total_length = 0;

void init(int sound)
{
    std::cout << "def play_music(playsound, set_sound_type, set_bpm, set_rate, set_anchor, start_append_mode, end_append_mode):" << std::endl;
    print_sound_type(sound);
}

int anchor = 0;
bool anchor_flag = false;
void set_anchor(int anchor)
{
    std::cout << "    set_anchor( " << anchor << " )" << std::endl;
}

int get_anchor_address()
{
    anchor = total_length;
    anchor_flag = true;
    return total_length;
}

int sound_type = 0;
bool sound_flag = false;
void set_sound_type(int n)
{
    sound_flag = true;
    sound_type = n;
}
void print_sound_type(int sound_type)
{
    std::cout << "    set_sound_type( " << sound_type << " )" << std::endl;
}
void print_bpm(double bpm)
{
    std::cout << "    set_bpm( " << bpm << " )" << std::endl;
}
void set_rate(double r)
{
    std::cout << "    set_rate( " << r << " )" << std::endl;
}

std::vector<std::pair<int, std::function<void()>>> appended_musics;
void append_from_anchor(int anchor, std::function<void()> f)
{
    appended_musics.push_back(
        std::pair<int, std::function<void()>>(anchor, f));
}


void nextSound(const int& f, const int& l, double volume)
{
    if (last_sound.freq != INIT) {
        std::cout << "    playsound( " << frequency(last_sound.freq) << " , " << last_sound.length << " , " << volume << " , ";
        if (last_sound.cut) {
            std::cout << "True";
        } else {
            std::cout << "False";
        }
        std::cout << " )" << std::endl;
    }
    if (sound_flag) {
        print_sound_type(sound_type);
        sound_flag = false;
    }
    if (anchor_flag) {
        set_anchor(anchor);
        anchor_flag = false;
    }

    last_sound = Sound{f, l, 1.0, false};
    total_length += l;
}

void b(const int& f, const int& l, double volume)
{
    if (f == last_sound.freq) {
        last_sound.cut = true;
    }
    nextSound(f, l, volume);
}

void bu(const int& f, const int& l, double volume)
{
    if (f == last_sound.freq) {
        last_sound.length += l;
    } else {
        nextSound(f, l, volume);
    }
}

void cut(const int& f, const int& l, double volume)
{
    last_sound.cut = true;
    nextSound(f, l, volume);
}

void fin()
{
    bu(FIN, 0);
    std::cout << "    # 終了" << std::endl;
    for (auto [anchor, function] : appended_musics) {
        last_sound = Sound{INIT, 0, 1.0, false};
        std::cout << "    start_append_mode(" << anchor << ")" << std::endl;
        function();
        bu(FIN, 0);
        std::cout << "    end_append_mode()" << std::endl;
    }
}
