#pragma once
#include "dict.hpp"
#include <array>
#include <cmath>
#include <iostream>

struct Sound {
    int freq;
    int length;
    bool cut;
};

extern std::array<double, 12> freq_dict;

double frequency(const int& f);

extern Sound last_sound;

void nextSound(const int& f, const int& l);

void b(const int& f, const int& l);
void bu(const int& f, const int& l);
void cut(const int& f, const int& l);

void fin();
