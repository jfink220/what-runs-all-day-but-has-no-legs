#include "src/timer.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    Timer timer;
    
    std::cout << "Starting timer..." << std::endl;
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    std::chrono::time_point<std::chrono::steady_clock> end_time;
    start_time = std::chrono::steady_clock::now();
    timer.start();
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    timer.stop();
    std::cout << "Timer stopped." << std::endl;
    end_time = std::chrono::steady_clock::now();
    int timer_elapsed_int = timer.elapsed();
    std::cout << "Timer measured: " << timer.elapsed() << " (" << timer_elapsed_int << ")" << " seconds" << std::endl;
    std::chrono::duration<double> system_elapsed = end_time - start_time;
    double system_time = system_elapsed.count();
    int system_time_int = system_elapsed.count();
    std::cout << "System clock measured: " << system_time << " (" << system_time_int << ")" << " seconds" << std::endl;
    double difference = std::abs(timer.elapsed() - system_time);
    if (difference < 0.001){ // check if timer and system clock are in 0.001 seconds of each other (tolerance)
      std::cout << "Timer and System Clock match." << std::endl;
    }
    else{
      std::cout << "Timer and System Clock are different." << std::endl;
    }
    return 0;
}
