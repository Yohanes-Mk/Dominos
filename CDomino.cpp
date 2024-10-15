#include "CDomino.h"
#include <iostream>

// Default constructor
CDomino::CDomino() : side1(0), side2(0) {}

// Constructor that takes two integers
CDomino::CDomino(int s1, int s2) : side1(s1), side2(s2) {}

// Display function
void CDomino::display() const {
    std::cout << "[" << side1 << "|" << side2 << "] "; // Display format
}
