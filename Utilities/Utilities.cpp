#include "Utilities.h"

int Utilities::generateRandomNumber(int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start, end);

    return dis(gen);
}
