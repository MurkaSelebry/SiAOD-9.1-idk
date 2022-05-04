#pragma once
#include <chrono>
class Stopwatch {
    std::chrono::steady_clock::time_point point;
    std::chrono::nanoseconds dim;
public:
    void start_countdown();
    double get_milliseconds();
};