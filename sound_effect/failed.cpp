#include "music_lib.hpp"

int main()
{
    init(2);
    // ここに譜面を書く
    int head = -1;
    default_volume = 20;
    //print_bpm(200);
    set_rate(16000);

    b(FAuLL, L4);
    b(Rest, L8);
    b(FAuLL, L4);

    fin();
}

