#ifndef CPLAYER_H
#define CPLAYER_H

#include "CDomino.h"
#include "CRandom.h"
#include <vector>
#include <cstddef> // Include for std::size_t

class CPlayer {
private:
    std::vector<CDomino> hand; // Player's hand of dominoes
    CRandom random; // Random number generator

public:
    // Constructors
    CPlayer() = default; // Default constructor
    ~CPlayer() = default; // Default destructor

    void addDomino(CDomino domino);
    CDomino playDomino();
    bool hasNoDominoes();

    std::size_t getHandSize() const;
    CDomino getDomino(std::size_t index) const;
    void removeDomino(std::size_t index);
};

#endif // CPLAYER_H
