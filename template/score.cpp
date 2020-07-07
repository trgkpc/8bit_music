#include "code.hpp"
#include "music_lib.hpp"

#define H() \
    head = get_anchor_address()

#define I(x) \
    append_from_anchor(head, []() { \
    print_sound_type(2);\
    x(); })

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
    static int intro_time = -1;
intro:
    intro_time++;
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    H();
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    I(Gu);

    H();
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(E);

    H();
    b(RAu, L4);
    b(FAu, L4);
    b(MIH, L4);
    b(DOuH, L4);
    I(Fu);

    H();
    cut(DOuH, L8_);
    cut(DOuH, L8_);
    b(REuH, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);
    I(BtoFaug);

    H();
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    I(Gu);


    H();
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(E);

    H();
    b(SOu, L2);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(Cu);

    H();
    b(RAu, L4);
    b(FAu, L4);
    b(REu, L4);
    b(FAu, L4);
    I(Du);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L16);
    b(REu, L8_);
    b(FAu, L8);
    I(EtoFu);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L2 + L4 + L16);
    append_from_anchor(head, []() {
        print_sound_type(2);
        Gu();
        Gu();
    });

    bu(SOu, L1);

    b(Rest, L1);

Amero:
    H();
    b(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(FALL, L8, vol);
        b(DOL, L8, vol);
        b(FAL, L8, vol);
        b(SOL, L8, vol);
        b(RAdL, L2, vol);
    });

    H();
    b(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(MIdLL, L8, vol);
        b(SIdLL, L8, vol);
        b(FAL, L8, vol);
        b(SOL, L8, vol);
        b(RAdL, L2, vol);
    });

    H();
    b(DOH, L2);
    cut(DOH, L8);
    b(DOuH, L8);
    b(DOH, L8);
    b(RAu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(REdLL, L8, vol);
        b(RAdLL, L8, vol);
        b(DOL, L8, vol);
        b(REdL, L8 + L2, vol);
    });

    H();
    b(DOH, L8);
    b(RAu, L8);
    b(SOu, L8);
    b(REuH, L8);
    b(DOH, L2);
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(MIdLL, L8, vol);
        b(RAdLL, L8, vol);
        b(SIdLL, L4, vol);
        b(RAdLL, L4);
        b(SOLL, L4);
    });
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(Rest, L2);
        b(RAdL, L4);
        b(SOL, L4);
    });


    // 気持ちブレス入れる感じ
    H();
    cut(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(FALL, L4, vol);
        b(DOL, L4, bvol);
        b(REdL, L2, bvol);
    });
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(FAL, L4, vol);
    });

    H();
    b(SOu, L2);
    cut(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    b(RAu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(MIdL, L4, vol);
        b(SIdLL, L4, bvol);
        b(DOL, L2, bvol);
    });
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(SOL, L4, vol);
    });

    H();
    b(DOH, L4);
    b(FA, L4);
    b(RAu, L8);
    b(SOu, L8);
    b(SO, L8);
    b(SOu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(SIdLL, L4_, vol);
        b(SIdLL, L8, bvol);
        b(DOL, L4_, vol);
        b(DOL, L8, bvol);
    });
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(REdL, L4_, vol);
        b(Rest, L8);
        b(MIdL, L4_, vol);
        b(Rest, L8);
    });


    H();
    b(SO, L4_);
    b(FA, L8);
    cut(FA, L2);
    append_from_anchor(head, []() {
        b(FAL, L4, vol);
        b(DOL, L4, bvol);
        b(FAL, L4, vol);
        b(DOL, L4, bvol);
    });
    append_from_anchor(head, []() {
        b(SIdL, L4, vol);
        b(Rest, L4);
        b(RAL, L4, vol);
        b(Rest, L4);
    });

    // 気持ちブレス入れる感じ
    H();
    cut(DOH, L8);
    cut(DOH, L16);
    cut(DOH, L8);
    cut(DOH, L16);
    cut(DOH, L4);
    cut(DOH, L8);
    b(RAu, L8);
    b(SOu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        REN3(RAdLL, REdL, FAL);
    });


    H();
    b(SO, L4);
    cut(SO, L8);
    b(REuH, L16);
    cut(REuH, L4 + L16 + L8);
    cut(REuH, L16);
    cut(REuH, L16);
    append_from_anchor(head, []() {
        print_sound_type(2);
        REN3(SIdLL, MIdL, SOL)
    });

    H();
    cut(REuH, L8);
    b(DOuH, L8);
    b(DOH, L8);
    b(RAu, L8);
    b(DOuH, L16);
    b(DOH, L8);
    b(RAu, L8_);
    b(SOu, L8);
    append_from_anchor(head, []() {
        print_sound_type(2);
        REN3(DOL, MIdL, SOL);
    });

    H();
    b(SO, L8_);
    cut(SO, L8_);
    b(FA, L8);
    b(SOu, L2);
    append_from_anchor(head, []() {
        b(FALL, L4);
        b(FALL, L4);
        b(SOLL, L4);
        b(RAdLL, L4);
    });


    // 気持ちブレス入れる感じ
    H();
    cut(SOu, L8);
    cut(SOu, L16);
    cut(SOu, L8);
    cut(SOu, L16);
    cut(SOu, L4);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    WAON(MILL, SOuL, SILL);

    H();
    b(RAu, L4);
    cut(RAu, L8);
    b(FAu, L16);
    cut(FAu, L4 + L16);
    b(Rest, L8);
    b(FAu, L8);
    WAON(FAuLL, RAuLL, DOuL);

    H();
    b(FA, L4);
    cut(FA, L8);
    b(REu, L8);
    b(FA, L8);
    b(SO, L16);
    b(SOu, L8_);
    cut(SOu, L8);
    WAON(DOuLL, FALL, SOuL);

    H();
    cut(SOu, L4_);
    b(SO, L16);
    b(FA, L16);
    b(SO, L2);
    WAON(REuLL, SOLL, RAuL);

    H();
    std::function<std::function<void()>(int, int, double)> tmp_gen = [](int s1, int s2, double volume) {
        return [=]() {
            cut(s1, L8, volume);
            b(Rest, L16);
            cut(s2, L8, volume);
            b(Rest, L16);
            cut(s1, L8, volume);
            b(Rest, L8);
        };
    };
    std::function<void()> f = tmp_gen(REu, MI, 1.0);
    f();
    f = tmp_gen(REuL, MIL, 0.7);
    append_from_anchor(head, [=]() {
        print_sound_type(2);
        f();
    });
    f = tmp_gen(REuLL, MILL, 0.7);
    append_from_anchor(head, [=]() {
        print_sound_type(2);
        f();
    });
    f = tmp_gen(RAuL, SIL, 0.7);
    append_from_anchor(head, [=]() {
        print_sound_type(2);
        f();
    });


sabi:
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);

    H();
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    I(Gu);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(E);

    H();
    b(RAu, L4);
    b(FAu, L4);
    b(MIH, L4);
    b(DOuH, L4);
    I(Fu);

    H();
    b(DOuH, L8_);
    cut(DOuH, L8_);
    b(REuH, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);
    I(BtoFaug);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    I(Gu);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(E);

    H();
    b(SOu, L2);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(Cu);

    H();
    b(RAu, L8_);
    b(FAu, L8_);
    b(REu, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);
    I(Du);

    H();
    b(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    I(Gu);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(E);

    H();
    b(RAu, L4);
    b(FAu, L4);
    b(MIH, L4);
    b(DOuH, L4);
    I(Fu);

    H();
    b(DOuH, L8_);
    cut(DOuH, L8_);
    b(REuH, L8);
    b(Rest, L8);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L8);
    I(BtoFaug);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(FAu, L8);
    I(Gu);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    cut(SOu, L8);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(E);

    H();
    b(SOu, L2);
    cut(SOu, L8);
    b(RAu, L8);
    b(SI, L8);
    b(DOuH, L8);
    I(Cu);

    H();
    b(RAu, L4);
    b(FAu, L4);
    b(REu, L4);
    b(FAu, L4);
    I(Du);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, L8_);
    b(SI, L8);
    b(RAu, L8);
    b(FAu, L16);
    b(REu, L8_);
    b(FAu, L8);
    I(EtoFu);

    H();
    cut(FAu, L8);
    b(SOu, L16);
    cut(SOu, (L16 + L2_));
    bu(SOu, L1);
    append_from_anchor(head, []() {
        print_sound_type(2);
        Gu();
        b(SOuLL, L1, svol);
    });
    append_from_anchor(head, []() {
        print_sound_type(2);
        b(Rest, L1);
        b(REuL, L1, svol);
    });


    bu(Rest, L1 * 2);

    // 終わらせる関数を呼ぶ
    fin();

    // re_init();
}
