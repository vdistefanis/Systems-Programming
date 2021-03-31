// Vincent Distefanis
//  SCS 212 01
//  Applied Exam Chapter 4 Program 26
//  Created by Vincent Distefanis on 3/30/21

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
   
    // Declaring and Initializing Variables
    int fahrenheitValue = 0, count = 5;
    double celsiusValue;
    
    // Title of Table
    cout << "Convert the value of Fahrenheit to Celsius\n";
    
    // Display Decimal notation, Decimal Point/Number of Decimal Places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    
    while (fahrenheitValue <= 100) {
        
        // Calculate the Celcius Value
        celsiusValue = (5.0/9.0) * ((double) fahrenheitValue - 32);
        
        // Display the Celsius and Fahrenheit values
        cout << fahrenheitValue << " F " << celsiusValue << " C \n";
        
        fahrenheitValue += count;
        
    }
    
    // Exit Program
    return 0;
}
