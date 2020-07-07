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

Sound last_sound{INIT, 0, 1.0, false};
int total_length = 0;

int get_total_length()
{
    std::cout << "    set_anchor( " << total_length << " )" << std::endl;
    return total_length;
}

int sound_type = 0;
void set_sound_type(int n)
{
    std::cout << "    set_sound_type( " << n << " )" << std::endl;
}

void append_from_anchor(int anchor, std::function<void()> f)
{
    Sound memo = last_sound;
    int pos_memo = total_length;
    int sound_type_memo = sound_type;

    last_sound = Sound{INIT, 0, false};
    total_length = anchor;
    std::cout << "    append_mode(" << anchor << ")" << std::endl;
    f();
    bu(FIN, 0);
    std::cout << "    end_append_mode()" << std::endl;

    if (total_length > pos_memo) {
        std::cerr << "append mode over flow occured." << std::endl;
    }

    last_sound = memo;
    total_length = pos_memo;
    set_sound_type(sound_type_memo);
}


void nextSound(const int& f, const int& l, const double& volume)
{
    if (last_sound.freq != INIT) {
        std::cout << "    playsound( " << frequency(last_sound.freq) << " , " << last_sound.length << " , " << volume << " , ";
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
    total_length += l;
}

void b(const int& f, const int& l, const double& volume)
{
    if (f == last_sound.freq) {
        last_sound.cut = true;
    }
    nextSound(f, l, volume);
}

void bu(const int& f, const int& l, const double& volume)
{
    if (f == last_sound.freq) {
        last_sound.length += l;
    } else {
        nextSound(f, l, volume);
    }
}

void cut(const int& f, const int& l, const double& volume)
{
    last_sound.cut = true;
    nextSound(f, l, volume);
}

void fin()
{
    bu(FIN, 0);
}
