#ifndef CDOMINO_H
#define CDOMINO_H

class CDomino {
private:
    int side1;  // First side of the domino
    int side2;  // Second side of the domino

public:
    // Constructors
    CDomino(); 
    CDomino(int s1, int s2);  
    
    // Destructor
    ~CDomino() = default;

    // Display function
    void display() const;

    // Getter methods
    int getSide1() const { return side1; }
    int getSide2() const { return side2; }
};

#endif // CDOMINO_H
