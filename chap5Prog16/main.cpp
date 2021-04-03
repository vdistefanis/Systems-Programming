// Vincent Distefanis
// SCS 212 01
// Chapter 5 Homework:
// Chapter 5 Program 16
//
//

#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, const char * argv[]) {
    const int FILENAME_LEN = 128;
    char infile[FILENAME_LEN];                      // Input filename
    char outfile[FILENAME_LEN];                     // Output filename
    ifstream input;                                 // Input file object
    ofstream output;                                // Output file object
    char ch;
    bool negative_state = false;
    
    cout << "Enter the input filename: ";
    cin >> infile;
    input.open(infile);
    // Test for failure of opening input file
    if (input.fail()) {
        cerr << "error opening file " << infile << endl;
        exit(1);
    }
    // Base output filename as the input filename with .filtered added to itt
    strcpy(outfile,infile);                         // Copies 2nd char string to 1st
    strcat(outfile,"filtered");                    // Appends 2nd char string to 1st

    cout << "writing output to " << outfile << endl;
    output.open(outfile);
    // Test for failure of opening output file
    if (output.fail()) {
        cerr << "error opening file " << outfile << endl;
        exit(1);
    }
    
    // Read first symbol
    ch = input.get();                                 // Reads whitespace and non-whitespace
    while (input.eof() == false)
    {
        if (ch == '(' )
        {
            // Verify that we are not expecting a right parenthesis at this time
            if (negative_state == true)
            {
                output << " Expected ), there is a parenthesis mismatch or error\n";
                output.close();
                exit(1);
            }
            negative_state = true;                      // Change to a negative state, are                                              reading a negative number
            output << " Entering a negative state\n";
            output << '-';
            
        }
        else if (ch == ')')
        {
            if (ch == ')' )
            {
                // Verify that we are not missing a left parenthesis
                if (negative_state == false )
                {
                    output << " - ERROR - Expected (, there is a parenthesis mismatch or error\n";
                    output.close();
                    exit(1);
                }
                
            output << "\nLeaving a negative state";
            negative_state = false;                 // Finished reading a negative number,                                          no longer in negative state
            }
        
        
            
        }
        
        
        else if (ch != ',' && ch != '$' )
            output << ch;                       // Filter out commas
        
        
        // If a ( is read, change that to a - in the output
        ch = input.get();                            // Reads whitespace and non-whitespace
    }
    
    cout << "end of data file" << endl;
    // Read a number and output it to the screen
    
    output.close();
    input.close();
    
    return 0;
}
