constexpr double svol = 0.5;
constexpr double vol = 0.7;
constexpr double bvol = 0.9;

#define REN3(s1, s2, s3)          \
    for (int i = 0; i < 3; i++) { \
        b(s1, L8, vol);           \
        if (i != 2) {             \
            b(s2, L8, vol);       \
        }                         \
        b(s3, L8, vol);           \
    }

#define WAON(s1, s2, s3)            \
    append_from_anchor(head, []() { \
        print_sound_type(2);        \
        b(s1, L1, vol);             \
    });                             \
    append_from_anchor(head, []() { \
        print_sound_type(2);        \
        b(s2, L1, vol);             \
    });                             \
    append_from_anchor(head, []() { \
        print_sound_type(2);        \
        b(s3, L1, vol);             \
    })


#define Gu()                      \
    for (int i = 0; i < 4; i++) { \
        b(SOuLL, L8, vol);        \
        b(REuL, L8, vol);         \
    }

#define E()                       \
    for (int i = 0; i < 4; i++) { \
        b(MILL, L8, vol);         \
        b(SILL, L8, vol);         \
    }

#define Fu()                      \
    for (int i = 0; i < 4; i++) { \
        b(FAuLL, L8, vol);        \
        b(DOuL, L8, vol);         \
    }

#define BtoFaug()                 \
    for (int i = 0; i < 2; i++) { \
        b(SILL, L8, vol);         \
        b(FAuL, L8, vol);         \
    }                             \
    for (int i = 0; i < 2; i++) { \
        b(SIdLL, L8, vol);        \
        b(FAuL, L8, vol);         \
    }

#define Cu()                      \
    for (int i = 0; i < 4; i++) { \
        b(DOuLL, L8, vol);        \
        b(SOuLL, L8, vol);        \
    }

#define Du()                      \
    for (int i = 0; i < 4; i++) { \
        b(REuLL, L8, vol);        \
        b(RAuLL, L8, vol);        \
    }

#define EtoFu()                   \
    for (int i = 0; i < 2; i++) { \
        b(MILL, L8, vol);         \
        b(SILL, L8, vol);         \
    }                             \
    for (int i = 0; i < 2; i++) { \
        b(FAuLL, L8, vol);        \
        b(DOuL, L8, vol);         \
    }
