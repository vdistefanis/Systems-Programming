// Vincent Distefanis
//  main.cpp
//  AppliedExam2
//
//  This program simulates rolling a die and displays the results
//

#include <iostream>
#include "Dice.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
   
    // Declare/Initialize Vars
    int randInt(int min, int max);
    int seed;
    int nOne = 0;
    int nTwo = 0;
    int nThree = 0;
    int nFour = 0;
    int nFive = 0;
    int nSix = 0;
    int numOfRolls = 0;
    int userInput = 0;
    
    // Get Input for Number of Rolls
    cout << "\nEnter the number of die rolls to simulate: ";
    cin >> userInput;
    
    // Prompt User to give valid input for number of rolls if first entry was not valid
    while (userInput <= 0) {
        cout << "Number of simulated rolls must be greater than zero\n";
        cout << "Enter desired number of simulated rolls: ";
        cin >> userInput;
    }
    
    // Prompt user for seed value
    cout << "Enter the value of seed: ";
    cin >> seed;
    srand(seed);
    
    // Complete all rolls, while properly incrementing based on value
    for (numOfRolls=0; numOfRolls<userInput; ++numOfRolls) {
        Dice d;
        if (d.getValueOfSide() == Dice::sideOne)
            nOne++;
        else if (d.getValueOfSide() == Dice::sideTwo)
            nTwo++;
        else if (d.getValueOfSide() == Dice::sideThree)
            nThree++;
        else if (d.getValueOfSide() == Dice::sideFour)
            nFour++;
        else if (d.getValueOfSide() == Dice::sideFive)
            nFive++;
        else if (d.getValueOfSide() == Dice::sideSix)
            nSix++;
    }
    
    
    cout << "\nTotal number of rolls: " << numOfRolls << "\n" << endl;
    // Calculate and display the total for each value rolled and its percentage for each side of the die
    printf("Total of rolled ones: %i percentage: (%2.2f)\n", nOne, (float)nOne/numOfRolls * 100);
    printf("Total of rolled ones: %i percentage: (%2.2f)\n", nTwo, (float)nTwo/numOfRolls * 100);
    printf("Total of rolled ones: %i percentage: (%2.2f)\n", nThree, (float)nThree/numOfRolls * 100);
    printf("Total of rolled ones: %i percentage: (%2.2f)\n", nFour, (float)nFour/numOfRolls * 100);
    printf("Total of rolled ones: %i percentage: (%2.2f)\n", nFive, (float)nFive/numOfRolls * 100);
    printf("Total of rolled ones: %i percentage: (%2.2f)\n\n", nSix, (float)nSix/numOfRolls * 100);
    
    return 0;
}
// random integer range
int randInt(int min, int max) {
    return rand()% 6 + 1;
}

