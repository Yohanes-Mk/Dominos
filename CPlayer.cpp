#include "CPlayer.h"

// Adds a domino to the player's hand
void CPlayer::addDomino(CDomino domino) {
    hand.push_back(domino);
}

// Plays a domino from the player's hand randomly
CDomino CPlayer::playDomino() {
    int index = random.generateRandom(0, hand.size() - 1);
    CDomino selectedDomino = hand[index];
    hand.erase(hand.begin() + index);
    return selectedDomino;
}

// Checks if the player has no dominoes left
bool CPlayer::hasNoDominoes() {
    return hand.empty();
}

// Returns the number of dominoes in hand
std::size_t CPlayer::getHandSize() const {
    return hand.size();
}

// Returns the domino at the specified index
CDomino CPlayer::getDomino(std::size_t index) const {
    return hand[index];
}

// Removes the domino at the specified index from the hand
void CPlayer::removeDomino(std::size_t index) {
    if (index < hand.size()) {
        hand.erase(hand.begin() + index);
    }
}
