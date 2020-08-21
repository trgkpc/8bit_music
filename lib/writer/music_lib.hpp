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

void init(int sound);

void set_sound_type(int n);
void print_sound_type(int sound_type);
void print_bpm(double bpm);
void set_rate(double r);

int get_anchor_address();
void set_anchor(int anchor);

void append_from_anchor(int anchor, std::function<void()> f);

extern Sound last_sound;
extern double default_volume;

void b(const int& f, const int& l, double volume = default_volume);
void bu(const int& f, const int& l, double volume = default_volume);
void cut(const int& f, const int& l, double volume = default_volume);

void fin();
