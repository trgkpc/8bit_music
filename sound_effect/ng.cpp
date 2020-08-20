#include "music_lib.hpp"

int main()
{
    init(2);
    // ここに譜面を書く
    int head = -1;

    print_bpm(200);

    b(SOuL, L16);
    b(Rest, L16);
    b(SOuL, L4);

    fin();
}

