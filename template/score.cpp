#include "music_lib.hpp"

int main()
{
    init(2);
    // ここに譜面を書く
    int head = -1;
zensou:
    set_sound_type(1);
    for (int i = 0; i < 0; i++) {
        b(Rest, L8);
        b(SOuL, L8);
        b(SOuL, L8);
        b(FAuL, L16);
        b(SOuL, L16);
        b(Rest, L8);
        b(SOuL, L8);
        b(FAuL, L8);
        b(FAuL, L16);
        b(SOuL, L16);
    }

    b(Rest, L2);
intro:
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    head = get_anchor_address();
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        for (int i = 0; i < 4; i++) {
            b(SOuLL, L8);
            b(REuL, L8);
        }
    });

    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(RAu, L4);
    b(FAu, L4);
    b(MIH, L4);
    b(DOuH, L4);

    cut(DOuH, L8_);
    cut(DOuH, L8_);
    b(REuH, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);

    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(SOu, L2);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(RAu, L4);
    b(FAu, L4);
    b(REu, L4);
    b(FAu, L4);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L16);
    b(REu, L8_);
    b(FAu, L8);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L2 + L4 + L16);

    bu(SOu, L1);

    b(Rest, L1);

Amero:
    b(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);

    b(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);

    b(DOH, L2);
    cut(DOH, L8);
    b(DOuH, L8);
    b(DOH, L8);
    b(RAu, L8);

    b(DOH, L8);
    b(RAu, L8);
    b(SOu, L8);
    b(REuH, L8);
    b(DOH, L2);

    // 気持ちブレス入れる感じ
    cut(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);

    b(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);

    b(DOH, L4);
    b(FA, L4);
    b(RAu, L8);
    b(SOu, L8);
    b(SO, L8);
    b(SOu, L8);

    b(SO, L4_);
    b(FA, L8);
    cut(FA, L2);

    // 気持ちブレス入れる感じ
    cut(DOH, L8);
    cut(DOH, L16);
    cut(DOH, L8);
    cut(DOH, L16);
    cut(DOH, L4);
    cut(DOH, L8);
    b(RAu, L8);
    b(SOu, L8);

    b(SO, L4);
    cut(SO, L8);
    b(REuH, L16);
    cut(REuH, L4 + L16 + L8);
    cut(REuH, L16);
    cut(REuH, L16);

    cut(REuH, L8);
    b(DOuH, L8);
    b(DOH, L8);
    b(RAu, L8);
    b(DOuH, L16);
    b(DOH, L8);
    b(RAu, L8_);
    b(SOu, L8);

    b(SO, L8_);
    cut(SO, L8_);
    b(FA, L8);
    b(SOu, L2);

    // 気持ちブレス入れる感じ
    cut(SOu, L8);
    cut(SOu, L16);
    cut(SOu, L8);
    cut(SOu, L16);
    cut(SOu, L4);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);

    b(RAu, L4);
    cut(RAu, L8);
    b(FAu, L16);
    cut(FAu, L4 + L16);
    b(Rest, L8);
    b(FAu, L8);

    b(FA, L4);
    cut(FA, L8);
    b(REu, L8);
    b(FA, L8);
    b(SO, L16);
    b(SOu, L8_);
    cut(SOu, L8);

    cut(SOu, L4_);
    b(SO, L16);
    b(FA, L16);
    b(SO, L2);

    b(REu, L8);
    b(Rest, L16);
    b(MI, L8);
    b(Rest, L16);
    b(REu, L8);
    b(Rest, L8);
sabi:
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(RAu, L4);
    b(FAu, L4);
    b(MIH, L4);
    b(DOuH, L4);

    b(DOuH, L8_);
    cut(DOuH, L8_);
    b(REuH, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(SOu, L2);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(RAu, L8_);
    b(FAu, L8_);
    b(REu, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(RAu, L4);
    b(FAu, L4);
    b(MIH, L4);
    b(DOuH, L4);

    b(DOuH, L8_);
    cut(DOuH, L8_);
    b(REuH, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(SOu, L2);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);

    b(RAu, L4);
    b(FAu, L4);
    b(REu, L4);
    b(FAu, L4);

    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L16);
    b(REu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, (L16 + L2_));
    bu(SOu, L1);

    bu(Rest, L1 * 2);

    // 終わらせる関数を呼ぶ
    fin();

    // re_init();
}
