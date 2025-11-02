#include <string>
#include <chrono>
#pragma once
class Timer{
    private:
        bool running;
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::time_point<std::chrono::steady_clock> end_time;
        bool hasRun;
    public:
        Timer();
        void start();
        void stop();
        double elapsed();
};