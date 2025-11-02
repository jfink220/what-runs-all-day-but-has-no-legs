#include <string>
#include <chrono>
#include "timer.hpp"
#include <iostream>
Timer::Timer() : running(false), hasRun(false) {
    // no-op
}

void Timer::start() {
    start_time = std::chrono::steady_clock::now();
    running = true;
    hasRun = true;
}

void Timer::stop() {
    if (running) {
        end_time = std::chrono::steady_clock::now();
        running = false;
    }
}

double Timer::elapsed() {
    if (!hasRun) {
        return 0;
    }
    
    auto endPoint = running ? std::chrono::steady_clock::now() : end_time;
    std::chrono::duration<double> elapsed = endPoint - start_time;
    return elapsed.count();
}
