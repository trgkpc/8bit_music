#include "music_lib.hpp"

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

Sound last_sound{INIT, 0, false};

void nextSound(const int& f, const int& l)
{
    if (last_sound.freq != INIT) {
        std::cout << "    playsound( " << frequency(last_sound.freq) << " , " << last_sound.length << " , ";
        if (last_sound.cut) {
            std::cout << "True";
        } else {
            std::cout << "False";
        }
        std::cout << " )" << std::endl;
    } else {
        std::cout << "def play_music(playsound):" << std::endl;
    }
    last_sound = Sound{f, l, false};
}

void b(const int& f, const int& l)
{
    if (f == last_sound.freq) {
        last_sound.cut = true;
    }
    nextSound(f, l);
}

void bu(const int& f, const int& l)
{
    if (f == last_sound.freq) {
        last_sound.length += l;
    } else {
        nextSound(f, l);
    }
}

void cut(const int& f, const int& l)
{
    last_sound.cut = true;
    nextSound(f, l);
}

void fin()
{
    bu(FIN, 1);
}
