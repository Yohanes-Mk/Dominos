#include "CRandom.h"
#include <cstdlib>
#include <ctime>

CRandom::CRandom() {
    std::srand(static_cast<unsigned int>(std::time(0)));
}

int CRandom::generateRandom(int min, int max) {
    return min + std::rand() % ((max + 1) - min);
}
