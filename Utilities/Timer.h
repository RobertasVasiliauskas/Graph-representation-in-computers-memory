#ifndef AIZO_2_WITH_STL_TIMER_H
#define AIZO_2_WITH_STL_TIMER_H

#include <chrono>

class Timer {
public:
    static void checkStartTime();
    static void checkEndTime();

    [[nodiscard]] static const std::chrono::time_point<std::chrono::steady_clock> &getStartTime();
    [[nodiscard]] static const std::chrono::time_point<std::chrono::steady_clock> &getEndTime();

private:
    static std::chrono::time_point<std::chrono::steady_clock> startTime;
    static std::chrono::time_point<std::chrono::steady_clock> endTime;
};

#endif //AIZO_2_WITH_STL_TIMER_H
