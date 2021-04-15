//  main.cpp
// Vincent Distefanis
// SCS 212 01
// April 15, 2021
/* This program will read input from the input file
 and determine the number of days spent within four
 temperature categories of May 2015 as well as
 determine the number of days that had detectable
 amounts of precipitation */

#include <iostream>
#include<fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    int precipitation = 0;
    ifstream fin;                       // Input File
    ofstream fout;                      // Output file
    string filename = "WeatherData.dat";
    const int HEADERLINES(5);
    
    // Open input file to read input data
    fin.open(filename);
    if(fin.fail()){
            cout << "error opening file..." << endl;
            exit(1);
    }
    //successful open
    //read and print header
    char ch, newline('\n');
    for(int i=0; i<HEADERLINES; ++i){
        fin.get(ch);
        while(!fin.eof() && ch != newline)
        {
            cout << ch;
            fin.get(ch);
        }
        if(fin.eof())
            exit(1);  //unexpected end of data
        else
            cout << ch;  //print newline
    }//get next header
    //read and discard all non numeric data
    fin.get(ch);
    while(!fin.eof() && !isdigit(ch)){
        fin.get(ch);
    }
    //Check for unexpected end of file
    if(fin.eof()) exit(1);
    
    //Not eof, ch must be a digit
    //put the digit back on the input stream
    fin.putback(ch);
    //get numeric data
    int day, above75(0), below0(0), value0to32(0), value33to75(0);
    double wMax, wMin, wAvg;
    string rain, snow;
    fin >> day >> wMax >> wMin >> wAvg >> rain >> snow;
    
    // Read data from input file to count days spent in temperature categories
    while (!fin.eof()) {
        // Verify if avg temperature is < 0
        if (wAvg < 0)
            // Increment "below0" var
            ++below0;
        // Verify if average temperature between (0-32)
        if (wAvg >= 0 && wAvg <= 32)
            // Increment "value0to32" var
            ++value0to32;
        // Verify if average temperature between (33-75)
        if (wAvg >= 33 && wAvg <= 75)
            // Increment "value33to75" var
            ++value33to75;
        // Verify if average temperature is > 75
        if (wAvg > 75)
            // Increment "above75" var
            ++above75;
        // Verify number of days with trace precipitation
        if (rain == "T" || snow == "T")
            // Increment "precipitation" var
            ++precipitation;
        fin >> day >> wMax >> wMin >> wAvg >> rain >> snow;
    }
    // Output four temperature categories
    // Print number of days for below 0 temperature category
    cout << below0 << " days had an average temperature below 0" << endl;
    // Print number of days for 0 to 32 temperature category
    cout << value0to32 << " days had temperature between 0 and 32" << endl;
    // Print number of days for 33 to 75 temperature category
    cout << value33to75 << " days had temperature between 33 and 75" << endl;
    // Print number of days for above 75 temperature category
    cout << above75 << " days had temperature above 75\n" << endl;
    // Print number of days that had Precipitation
    cout << precipitation << " days had only trace amounts of precipitation\n" << endl;


        return 0;
}
