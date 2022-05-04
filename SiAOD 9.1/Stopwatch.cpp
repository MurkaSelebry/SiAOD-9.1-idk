#include "Stopwatch.h"
void Stopwatch::start_countdown() {
    point = std::chrono::steady_clock::now();
}
double Stopwatch::get_milliseconds() {
    dim = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - point);
    return (double)dim.count() / 1'000'000;
}