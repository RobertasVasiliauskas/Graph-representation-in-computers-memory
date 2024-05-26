#include "Timer.h"

// Define the static member variables
std::chrono::time_point<std::chrono::steady_clock> Timer::startTime;
std::chrono::time_point<std::chrono::steady_clock> Timer::endTime;

void Timer::checkStartTime() {
    startTime = std::chrono::steady_clock::now();
}

void Timer::checkEndTime() {
    endTime = std::chrono::steady_clock::now();
}

const std::chrono::time_point<std::chrono::steady_clock>& Timer::getStartTime() {
    return startTime;
}

const std::chrono::time_point<std::chrono::steady_clock>& Timer::getEndTime() {
    return endTime;
}
