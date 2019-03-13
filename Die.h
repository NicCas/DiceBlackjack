//
// Specification file for the Die class
// Modified from textbook (page 178)

#ifndef HW_4_DIE_H
#define HW_4_DIE_H
class Die {
private:
    int sides; // Number of sides
    int value; // The die's value
public:
    Die(int = 6); // Constructor
    void roll(); // Rolls the die
    int getValue(); // Returns the die's value
};

#endif //HW_4_DIE_H
