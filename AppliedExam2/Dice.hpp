// Vincent Distefanis
//  Dice.hpp
//  AppliedExam2
//
//  Class for the die
//

#ifndef Dice_h
#define Dice_h

#include <stdio.h>

int randInt(int min, int max);


class Dice {
// Declare member variables
private:
    int valueOfSide;
public:
    static const int sideOne = 1;
    static const int sideTwo = 2;
    static const int sideThree = 3;
    static const int sideFour = 4;
    static const int sideFive = 5;
    static const int sideSix = 6;
   
    // Default constructor
    Dice() {
        // Generating random value
        int randomInt = randInt(1,6);
        // Assigning values to correct variable
        if (randomInt == 1)
            valueOfSide = sideOne;
        else if (randomInt == 2)
            valueOfSide = sideTwo;
        else if (randomInt == 3)
            valueOfSide = sideThree;
        else if (randomInt == 4)
            valueOfSide = sideFour;
        else if (randomInt == 5)
            valueOfSide = sideFive;
        else if (randomInt == 6)
            valueOfSide = sideSix;
    }
    int getValueOfSide() {
        return valueOfSide;
    }
    
   
    
        
    
};


#endif /* Dice_h */
