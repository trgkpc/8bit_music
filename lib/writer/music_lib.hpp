#pragma once
#include "dict.hpp"
#include <array>
#include <cmath>
#include <functional>
#include <iostream>

struct Sound {
    int freq;
    int length;
    double volume;
    bool cut;
};

extern std::array<double, 12> freq_dict;
double frequency(const int& f);

void set_sound_type(int n);

int get_total_length();
void append_from_anchor(int anchor, std::function<void()> f);

extern Sound last_sound;

void b(const int& f, const int& l, const double& volume = 1.0);
void bu(const int& f, const int& l, const double& volume = 1.0);
void cut(const int& f, const int& l, const double& volume = 1.0);

void fin();
