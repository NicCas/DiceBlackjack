//
// Specification file for the Die class
// Taken directly from text (page 178)

#ifndef HW_4_DIE_H
#define HW_4_DIE_H
class Die {
private:
    int sides;
    int value;
public:
    Die(int = 6);
    void roll(); int getSides(); int getValue();
};

#endif //HW_4_DIE_H
