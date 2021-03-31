// Vincent Distefanis
//  SCS 212 01
//  Applied Exam Chapter 4 Program 19
//  Created by Vincent Distefanis on 3/30/21.

#include <iostream>

using namespace std;

const double centimeterPerInch = 2.54;

int main(int argc, const char * argv[]) {
    
    // Declaring and Initializing Variables
    double centimeter = 0.0, inchValue = 0.0, count = 0.5;
    
    
    // Show Decimal Notation
    cout.setf(ios::fixed);
    
    // Show Decimal point
    cout.setf(ios::showpoint);
    
    // Display 4 Decimal Places
    cout.precision(4);
    
    
    // Table Title
    cout << "Conversion table for inches to centimeters (starting at 0.0 inches)\n";
    
    
    while (inchValue <= 20.0) {
        centimeter = inchValue * centimeterPerInch;
        cout << inchValue << " " << centimeter << endl;
        
        inchValue += count;
        
    }
    
    // Exit Program
    return 0;
    
 
}
