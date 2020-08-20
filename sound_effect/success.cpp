#include "music_lib.hpp"

int main()
{
    init(3);
    // ここに譜面を書く
    int head = -1;
    default_volume = 20;

    auto high = MIHH;
    auto low = high + (RAdH-DOHH);
    b(high, L16);
    b(low, L16);
    b(high, L16);
    b(low, L16);
    b(high, L16);
    b(low, L16);
    b(high, L16);
    b(low, L8_);

    fin();
}

