
#ifndef ULTRANUMBER_H
#define ULTRANUMBER_H

#include <string>
#include <vector>

using namespace std;

class UltraNumber {
private:
    string displayZeros(int x);
    void parseInput(string s);
    void add2Front(int x);
public:
    //NOTE: fullNumber goes biggest to smallest. Like the order you would read it in.
    vector<int> fullNumber = {};
    vector<vector<int>> multiples{ {0} };
    UltraNumber() {
        //cout << "Ultra Number Created!";
    }
    UltraNumber(int input) {
        quickCreate(input);
        //cout << "Ultra Number Created!\n";
        //cout << "Vector size = " << fullNumber.size() << endl;;
        //displayValue();
    }
    UltraNumber(string s) {
        //cout << "Ultra Number Created!\n";
        parseInput(s);
        //cout << "Vector size = " << fullNumber.size() << endl;;
        //cout << "initial number is: " << fullNumber.at(0) << endl;
        //cout << "\t(Note: This is not the full ultra Number)" << endl;
    }
    UltraNumber(vector<int> v) {
        //cout << "Ultra Number Created!";
        fullNumber = v;
    }


    static bool lessThanComparison(UltraNumber small, UltraNumber large);
    static bool lessThanOrEqualTo(UltraNumber small, UltraNumber large);
    static bool equalTo(UltraNumber A, UltraNumber B);

    void add(int);
    void add(UltraNumber);

    void multiply(int);
    void multiply(UltraNumber);

    void subtract(int);
    void subtractFrom(int, int pos);
    void subtract(UltraNumber);
    //int checkLeft(int i, vector<int>& v);
    void cleanUp();

    void divide(int);
    void mod(int);
    void divide(UltraNumber, bool mod = false);
    void mod(UltraNumber);
    int grabDigit(vector<int>, int posL2R);
    long long add2End(int begin, int end);
    vector<int> add2End(vector<int>& begin, int end);
    void generateMultiples();
    void binarySearchTreeSort();
    int binarySearchTreeSearch(UltraNumber);


    void displayValue();
    vector<int> getValue();

    static vector<int> interpretValue(vector<int> getValue);
    static UltraNumber getLarger(UltraNumber UN1, UltraNumber UN2, UltraNumber& UNsmall);
    static int getSize(int);

    void internalAdd(int r);
    void quickCreate(int r);
    void shift(int x);

    int binarySearchTreeSearchGenerator(vector<vector<int>> v, int minPos, int maxPos);

    //return the element for the quotient
    int getBestMultiple(UltraNumber UN);

    int getNumOfDigits();
};

int grabDigitInt(int mainNumber, int posL2R);
int grabDigitUN(UltraNumber mainNumber, int posL2R);

void displayVector(vector<int>);

#endif