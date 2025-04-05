// UltraNumberCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "../UltraNumber/UltraNumber/UltraNumber.h"
#include "../Austins Helper Class/Helper.h"
//#include "Austins helper class"

using namespace std;

vector<string> choices = { "Add", "Subtract", "Multiply", "Divide", "Modulo", "Exit Program"};
UltraNumber base(0);
Helper AHC;

UltraNumber uniformDisplay(string function);

int main()
{
    //UltraNumber test(15);

    std::cout << "WARNING: ULTRANUMBER IS EXPERIMENTAL. IT IS STILL IN TESTING. VERY FEW SAFEGUARDS ARE IN PLACE. PLEASE USE WITH CAUTION.\nIF YOU ARE DEALING WITH OCTILLIONS OR SMALLER YOU SHOULD BE FINE.\n\n ";

    std::cout << "Note: Because ultranumbers are composed of a vector of integers, sections will omit proceeding zeros. For example 1 | 000,000,002 will be represented as 1 | 2. Fixing this is on my todo list\n";
    std::cout << "As of this point in time, the program cannot handle negative numbers or decimal places. (Negatives may not crash the system, but it will give bad results)\n\n\n";

    int input = 0;
    //Main Loop
    do {
        cout << "Current number is: ";
        base.displayValue();
        cout << endl << endl;

        input = AHC.displayChoiceVector(choices);

        switch (input) {
        case 1: {
            UltraNumber adder = uniformDisplay("add to");
            base.add(adder);
            break;
        }
        case 2: {
            UltraNumber adder = uniformDisplay("subtract from");
            base.subtract(adder);
            break;
        }
        case 3: {
            UltraNumber adder = uniformDisplay("multiply by");
            base.multiply(adder);
            break;
        }
        case 4: {
            UltraNumber adder = uniformDisplay("divide by");
            base.divide(adder);
            break;
        }
        case 5: {
            UltraNumber adder = uniformDisplay("Modulo");
            base.mod(adder);
            break;
            }
        }

    } while (input != 6);
}

UltraNumber uniformDisplay(string function) {
    cout << "Type a number, (no commas) to " << function << " current number" << endl;
    string str;
    cin >> str;
    UltraNumber UN(str);
    return UN;
}
