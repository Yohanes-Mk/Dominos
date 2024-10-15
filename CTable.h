#ifndef CTABLE_H
#define CTABLE_H

#include "CDomino.h"
#include <vector>
#include <iostream>
#include <algorithm> // For std::random_shuffle
#include <random>    // For std::mt19937 and std::shuffle

class CTable {
private:
    std::vector<CDomino> dominoes; // Holds the dominoes on the table
    CDomino availablePieces[28]; // Holds all available domino pieces
    int availableCount; // Number of available pieces
    int head; // Current head of the domino train
    int tail; // Current tail of the domino train

public:
    CTable(); // Constructor to initialize pieces
    ~CTable(); // Destructor

    void placeDomino(const CDomino& domino); // Places a domino on the table
    void displayTable() const; // Displays the current state of the table with ends
    bool isAvailable() const; // Check if there are available pieces
    CDomino drawPiece(); // Draw a piece from the available pieces
    int getHead() const { return head; } // Getter for head
    int getTail() const { return tail; } // Getter for tail
};

#endif // CTABLE_H
