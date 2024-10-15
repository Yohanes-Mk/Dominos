#include "CTable.h"
#include <random> // For std::random_device and std::mt19937

// Constructor to initialize pieces
CTable::CTable() : availableCount(28), head(-1), tail(-1) {
    // Initialize all domino pieces
    int index = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            availablePieces[index++] = CDomino(i, j);
        }
    }

    // Shuffle the available pieces for random distribution
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::shuffle(availablePieces, availablePieces + 28, eng); // Shuffle the pieces

    // Set head and tail to an invalid state
    head = -1;
    tail = -1;
}

// Destructor
CTable::~CTable() {
    // Destructor logic if needed (currently not using dynamic memory)
}

// Places a domino on the table
void CTable::placeDomino(const CDomino& domino) {
    dominoes.push_back(domino); // Add the domino to the table
    // Update head and tail based on the newly placed domino
    if (head == -1 && tail == -1) { // First domino placed
        head = domino.getSide1();
        tail = domino.getSide2();
    } else {
        // Update the head and tail logic based on the current domino placement
        if (domino.getSide1() == head) {
            // Side 1 matches the head, update head to side 2
            head = domino.getSide2();
        } else if (domino.getSide2() == head) {
            // Side 2 matches the head, update head to side 1
            head = domino.getSide1();
        } else if (domino.getSide1() == tail) {
            // Side 1 matches the tail, update tail to side 2
            tail = domino.getSide2();
        } else if (domino.getSide2() == tail) {
            // Side 2 matches the tail, update tail to side 1
            tail = domino.getSide1();
        }
    }
}

// Displays the current state of the table including head and tail
void CTable::displayTable() const {
    std::cout << "Table (Left End: " << head << ", Right End: " << tail << "): ";
    for (const auto& domino : dominoes) {
        domino.display(); // Display each domino on the table
    }
    std::cout << std::endl; // New line for better formatting
}

// Check if there are available pieces
bool CTable::isAvailable() const {
    return availableCount > 0;
}

// Draw a piece from the available pieces
CDomino CTable::drawPiece() {
    if (availableCount > 0) {
        return availablePieces[--availableCount]; // Return the last available piece
    }
    return CDomino(); // Return a default domino if none available
}
