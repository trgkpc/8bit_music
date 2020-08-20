#include "music_lib.hpp"

int main()
{
    init(2);
    // ここに譜面を書く
    int head = -1;
    default_volume = 20;

    for(int i=0;i<3;i++){
        b(DO, L8);
        b(Rest, L8);
    }
    b(DOH, L4_);

    fin();
}

