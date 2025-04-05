// UltraNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*


*/

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <corecrt_math.h>
#include <algorithm>
#include "UltraNumber.h"

using namespace std;

//==============================
/*
A big part of the reason we're doing this for project Calypso. 

As such we will also need a log/ exponent function;
Exponent depends on mult - mult depends on add;

We will also need a converter, function. Maybe with a seperate class. i.e. decimal to hex

*/
//=============================

class Node {
public:
    vector<int> value;
    int pos;
    Node* left;
    Node* right;

    Node() {
    }

    Node(vector<int> v) {
        value = v;
    }
};




void UltraNumber::add(int x) {
    //if x > 1 bill divide into two integers
    //  then place one in bottom add to the second

    UltraNumber UNinput(x);
    this->add(UNinput);
}

void UltraNumber::internalAdd(int r) {

    //int l = 0;
    if (r >= 1000000000) {
        int y = r / 1000000000;

        //We did it x mod x so that regardless we can just add x to the value;
        //int z = x % 1000000;
        r = r % 1000000000;

        //if our number >= 1 Bill then we need to add an aditional int to the vector. However I think this is doing it in the wrong order;
        if (1 == fullNumber.size()) {
            fullNumber.push_back(0);
        }
        fullNumber.at(1) += y;
    }

    fullNumber.at(0) += r;
    
    displayValue();
    //first one just adds, doesn't necessarily correct
    //Why this next part is necessary

    int counter = 0;
    while (counter < fullNumber.size()) {


        //checking to see if we need correction, if we don't then just skip.
        if (fullNumber.at(counter) < 1000000000) {
            counter++;
            continue;
        }

        
        int x = fullNumber.at(counter); 
        int y = x / 1000000000;

        //We did it x mod x so that regardless we can just add x to the value;
        //int z = x % 1000000;

        if (x >= 1000000000) {
            x = x % 1000000000;

            fullNumber.at(counter) = x;

            //if counter = size-1; push a new int.
            if (counter == fullNumber.size() - 1 && y > 0) {
                fullNumber.push_back(y);
            }
            else {
                fullNumber.at(counter) += y;
            }
        }

        counter++;

    }
    cout << "Vector size = " << fullNumber.size() << endl;;
}

void UltraNumber::displayValue() {
    cout << "Numbers are:\n";
    
    //Displays backwards
    for (int i = 0; i <fullNumber.size(); i++) {
       // cout << displayZeros(fullNumber.at(i)) <<fullNumber.at(i) << ",\t"
        cout << fullNumber.at(i) << " | ";
    }
}

string UltraNumber::displayZeros(int x) {
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        if ((x / pow(10, i)) >= 1) {
            counter++;
            continue;
            cout << "UltraNumber::displayZeros :: for loop 1";
        }
        else {
            break;
        }
     
    }
    //cout << "Counter.size  = " << counter << endl;

    string s = "";

    for (int i = 0; i < 9-counter; i++) {
        s += "0";
        cout << "UltraNumber::displayZeros :: for loop 2";
    }

    s += x;
    string sA;
    string sB;
    
    for (int i = 1,counter2 = 1; i < s.size()-1;i++) {
        
        if (i == 3 || i== 7 || i == 11) {
            s.insert(i, 1, ',');
            i++;
        }
        cout << "UltraNumber::displayZeros :: for loop 3";
    }

    /*
    for (int i = 0; i < counter; i++) {
        s += "0";
        if (i%3 == 0) {
            s += ",";
        }
    }
    */
    return s;
}

void UltraNumber::parseInput(string s) {
    vector<string> vS;
    vector<int> vI = {};

    //length of the string
    int lengthVar = s.size();

    //difference of greatest int, between it's size and 9.
    int remainder = lengthVar % 9;

    //string of largest set of 9
    string biggest = s.substr(0, lengthVar);

    //cout << "ParseInput: obtained biggest number" << endl;;

    int i = 0;
    int counter = 0;

    //I believe I use this later. Don't worry about it. Don't delete it.
    std::string::size_type pos;

   // cout << "ParseInput: pos created" << endl;;
    
    /*
        try
        {
            fullNumber.at(0) = std::stoi(s, &pos, 10);
            int shortTermVar = std::stoi(s, &pos, 10);
            UltraNumber UN2(shortTermVar);
            fullNumber = UN2.fullNumber;
            return;
        }
        catch (std::out_of_range const& ex)
        {
            std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
            const long long ll{ std::stoll(s, &pos) };
            std::cout << "std::stoll(" << "" << "): " <<
                "; pos: " << pos << '\n' << endl << endl;;
            string s2 = s.substr(0, remainder);
            vS.push_back(s2);

        }

     */
    //Try catch stoi notes

    //if input creates a vector of size 2 or greater.
    if (s.size() >= 10) {
        //========================================================== Does this need to be a loop?

        //we don't need to do anything fancy because if there are any billions, it automatically goes to the next digit.
        if (remainder != 0) {
            string s3 = s.substr(i, remainder);
            vS.push_back(s3);
        }
        
        i = remainder;

    }
    
    int iterator = 0;
        do {

            // if there are at least a full 9 digits left
            if (i + 9 <= s.size() - 1) {
                string s2 = s.substr(i, 9);
                //cout << "substring s2 = " << s2 << endl;
                vS.push_back(s2);
                //cout << "counter: " << vS.at(counter) << endl;
                counter++;
            }else {
                string s2 = s.substr(i, 9);
                //cout << "substring s2 = " << s2 << endl;
                vS.push_back(s2);
            }
            iterator++;
           // cout << "Iterator: " << iterator << endl;
            i += 9;
        } while (i < s.size());
    
    
    //we know small numbers like 27 work
    //vS.at(0) = "27";
    //vS.at(0) = "-27";
    //vS.at(0) = "9876543210";
    //cout << "ParseInput: obtained all substrings" << endl;;



    //cout << "ParseInput: vS.size = " << vS.size() << endl;;
    for (int i = 0; i < vS.size(); i++) {
       // cout << vS.at(i) << ": is the value of vs at " <<i<<"\n";
    }
    
    /*
    try
    {

        fullNumber.at(0) = std::stoi(vS.at(0), &pos, 10)
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
    }
    catch (std::out_of_range const& ex)
    {
        std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
        const long long ll{ std::stoll(s, &pos) };
        std::cout << "std::stoll(" << "" << "): " << 
            "; pos: " << pos << '\n';
    }
    */




    

    //std::cout << "ParseInput: stoi success" << endl;;

    //std::cout << "ParseInput: added first set of string as int" << endl;;

    
    //if (vS.size() - 2 >= 0) {
        
        for (int i = 0; i < vS.size(); i++) {
            fullNumber.push_back(std::stoi(vS.at(i),&pos,10));
        }
    //}
}

void UltraNumber::add(UltraNumber UN2) {
 

    //What if we just added to the greatest number, then replaced old with new.

    UltraNumber UNs;
    //cout << "Got to add \n";
    UltraNumber UNL = UltraNumber::getLarger(*this, UN2, UNs);
    
    //UltraNumber
    int billions = 0;
    
   
    
    //int i = 0;
    int UNLIterator = UNL.fullNumber.size() - 1;
    int UNsIterator = UNs.fullNumber.size() - 1;

    //cout << "full number . size = " << fullNumber.size() << endl;;
    //cout << "UNL full number . size = " << UNL.fullNumber.size() << endl;;
    //cout << "UNs full number . size = " << UNs.fullNumber.size() << endl;;

    if (UNLIterator < UNsIterator) {
       // cout << "Houston we have a problem\n";
    }
    do {
        //cout << "top of do while. Billions = " << billions << endl;

        // Sum = value of int at last position for both UltraNumbers + carryover (billions).
        int sum = UNL.fullNumber.at(UNLIterator) + UNs.fullNumber.at(UNsIterator) + billions;
        
        //Billions is the sum / billion. should always be 1 or zero.
        billions = sum / 1000000000;

        //cout << "Billions = " << billions << endl;
        sum %= 1000000000;
        UNL.fullNumber.at(UNLIterator) = sum;

        UNLIterator--;
        UNsIterator--;

        //I may have f'ed this up. Need to verify.
        //If we are at the highest position and billions is greater than 0, then we add to the vector 
        if (UNLIterator < 0 && billions > 0) {
            //cout << "See line in UltraNumber.add - may be causing problems.\n";
            UNL.add2Front(billions);
            UNLIterator++;
            //This line is just for testing
            //UNL.displayValue();
            break;
        }

        //This may be the reason it's adding twice. will comment out and analyze.
        //This was the reason it was adding twice, but it also was adding to top.
        
        
        /*
        if (UNLIterator >= 0 && billions > 0) {
            UNL.fullNumber.at(UNLIterator) += billions;
        }
        */

        //cout << "i (end)= " << i <<endl;
        //seems to be a problem with the while
        if (UNsIterator < 0 && billions >0) {
            UNL.fullNumber.at(UNLIterator) += billions;
        }

    } while (UNLIterator >= 0 && UNsIterator >= 0);

    if (billions != 0) {
       // UNL.fullNumber.at(UNLIterator) += billions;
    }

    fullNumber = UNL.fullNumber;
}

 UltraNumber UltraNumber::getLarger(UltraNumber UN1, UltraNumber UN2, UltraNumber& UNsmall) {
    if (UN1.fullNumber.size() >= UN2.fullNumber.size()) {
        UNsmall = UN2;
        return UN1;
    }
    else {
        UNsmall = UN1;
        return UN2;
    }
}

 void UltraNumber::add2Front(int x) {
     std::reverse(fullNumber.begin(), fullNumber.end());
     fullNumber.push_back(x);
     std::reverse(fullNumber.begin(), fullNumber.end());
 }

 void UltraNumber::multiply(int input) {
    //UltraNumber originalNumber = *this;
    /*
    While multiplication is generally seen as an express way of adding, after testing, it was discovered that this method is not feasible due to the time complexity.
    
    //we start with 1 b/c with 0 we add input times, then we'd have to subract 1. For example 111*3 = 111 + (333)
    OLD METHOD:
    for (int i = 1; i < input; i++) {
        add(originalNumber);
        displayValue();
    }
    */

    long long l = 0;
    int remainderVar = 0;
    for (int i = fullNumber.size()-1; i >= 0 ; i--) {
        l = static_cast<long long>(input) * static_cast<long long>(fullNumber.at(i)) + static_cast<long long>(remainderVar);

        int newVal = (int)(l % 1000000000);
        remainderVar = (int)(l / 1000000000);

        fullNumber.at(i) = newVal;
    }
    if (remainderVar != 0) {
        add2Front(remainderVar);
    }

    //displayValue();


 }

 void UltraNumber::multiply(UltraNumber input) {
     //cout << "\n================\n\tAJD ERROR: for loop in multiply is broken. Most likely issue with \"lessThanComparison\"\nAJD (Continued) Auto Terminating function\n================\n";
     //return;

     /*
     UltraNumber originalNumber = *this;
     UltraNumber small(10000);
     UltraNumber mid(10000000);
     UltraNumber large("1000000000000");

     bool smallComplete = false;

     cout << " input full number size = " << fullNumber.size() << endl;;
     cout << "Calculating. Please Wait. \n";
     //we start with 1 b/c with 0 we add input times, then we'd have to subract 1. For example 111*3 = 111 + (333)
     for (UltraNumber i(1); UltraNumber::lessThanComparison(i, input); i.add(1)) {
         add(originalNumber);
         //displayValue();
         //cout << "i = ";
         //i.displayValue();
         //0 means equal
         
         if (UltraNumber::lessThanComparison(i, mid) == false && smallComplete == false) {
             cout << "We've iterated 10,000,000 times\n";
             smallComplete = true;
         }
         if ((UltraNumber::lessThanComparison(i, large) == false)&& (smallComplete == true) ) {
             cout << "We've iterated 1,000,000,000,000 times\n";
             cout << "Terminating for safety\n";
             break;
         }
     }
     */

     UltraNumber CONSTANT = *this;

     long long l = 0;
     int remainderVar = 0;
     vector<UltraNumber> UNList = {};
     
     //should multiply by int return UltraNumber or edit UltraNumber?

     
     //for every integer in fullNumber.size() of input.
     cout << "Full number.size expected = 2, actual =" << input.fullNumber.size() << endl;;



     for (int i = 0; i < input.fullNumber.size(); i++) {
         CONSTANT.multiply(input.fullNumber.at(i));
         UltraNumber UNx = CONSTANT;

         cout << "i = " << i << endl;
         int diff = (input.fullNumber.size() - 1) - i;
         
         //diff*9 is correct. if you have 719B, 22M,etc. You are creating an ultranumber of 719 x UN, shifted one int.
         diff = diff * 9;
         cout << "Diff expected = 9, diff actual = " << diff << endl;
         UNx.shift(diff);

         CONSTANT = *this;

         cout << "in for loop of multiply. Unx = ";
         UNx.displayValue();
         UNList.push_back(UNx);
     }

     UltraNumber UNsum(0);

     for (int i = 0; i < UNList.size();i++) {
         UNsum.add(UNList.at(i));
         
         cout << "UNList at i = " << endl;
         UNList.at(i);
         cout << "UN sum for value at i = " << endl; 
         UNsum.displayValue();
         
     }

     *this = UNsum;
     

 }

 bool UltraNumber::lessThanComparison(UltraNumber expectedSmall, UltraNumber large) {
     //Could we just check numOfDigits && first digit?
     if (expectedSmall.fullNumber.size() > large.fullNumber.size()) {
         return false;
     }
     if (expectedSmall.fullNumber.size() < large.fullNumber.size()) {
         return true;
     }
     //if the quantity of integers in the vector are equal, then we do further testing.
     else if (expectedSmall.fullNumber.size() == large.fullNumber.size()) {

         //if the first value is smaller 97 | xxx < 98 | xxx
         if (expectedSmall.fullNumber.at(0) < large.fullNumber.at(0)) {
             return true;
         }
         else if(expectedSmall.fullNumber.at(0) == large.fullNumber.at(0)) {
             //cout << "Returned, true with the following numbers ";
             //cout << endl << endl << endl;

             //expectedSmall.displayValue();
             //large.displayValue();
             //cout << endl;
             int i = 1;
             while (i < expectedSmall.fullNumber.size()) {
                 if (expectedSmall.fullNumber.at(i) < large.fullNumber.at(i)) {
                     return true;
                 }else if (expectedSmall.fullNumber.at(i) > large.fullNumber.at(i)) {
                     return false;
                 }
                 else {
                    //Because == shouldn't do anything but continue.
                 }
                 i++;
             }

             return false;

         }
         else {
             return false;
         }
     }
     //if the expected small has significantly more digits
     else {
         false;
     }
     
 }

 void UltraNumber::quickCreate(int r) {
     int b;
     if (r >= 1000000000) {
         b = r / 1000000000;
         r = r % 1000000000;
         fullNumber.push_back(b);
     }
     fullNumber.push_back(r);

 }

 void UltraNumber::shift(int x) {
    // x is the number of digits to shift, ususally a multiple of 9;
     //seeing how an int can hold a billion, and that tranlsates to a billion units,
     //     I don't feel it's appropriate to make an ultraNumber version of this.
     // 

     if ( x < 0) {
         while (x < 0 && abs(x) >= 9) {
             fullNumber.pop_back();
             x += 9;
         }

         while (x < 0) {
             for (int i = 0; i < fullNumber.size(); i++) {
                
             }
         }
     }
     else {

         while (x >= 9) {
             fullNumber.push_back(0);
             x -= 9;
         }

         int z = (int)pow(10, x);

         multiply(z);
     }
 }

 void UltraNumber::subtract(int subtrahend) {
     //assume ultraNumber is bigger

     //this next line may be redundant.
     bool mightBeNegative = false;
     //NO additional comparators b/c sub fullNumber can only be size of one, b/c int NOT UN.
     if (this->fullNumber.size() == 1) {
         //cout << "We are entering subtract (int). Bigger num is = ";
         //this->displayValue();
         //cout << endl;

         this->fullNumber.at(0) -= subtrahend;

         //cout << "We are leaving subtract (int). Bigger num is = ";
         //this->displayValue();
         //cout << endl;
         return;
     }

     if (subtrahend >= 1000000000) {
         cout << "AJD ERROR: Subtrahend is too big. Function needs updating.\n";
     }

     int pos = this->fullNumber.size() - 1;

     int initialVal = fullNumber.at(pos) - subtrahend;
     fullNumber.at(pos) -= subtrahend;
            //after subtracting from initial

            
            //lets make this recursive
            
           // int i = (fullNumber.size()-1)-1;
             



            //let's make this iterative
                while (initialVal < 0){
                    
                    fullNumber.at(pos) += 1000000000;
                        
                        // where we take away from higher
                        pos--;
                        initialVal = fullNumber.at(pos) -1;
                        fullNumber.at(pos) = initialVal;

                }

                cleanUp();
    }
     
 void UltraNumber::subtract(UltraNumber subtrahend) {
     UltraNumber copyMain = *this;
     vector<int> toBuild = {};
     //vector<int> copyMain = this->fullNumber;

     //Maybe make a subtract function with an ignore iterator, like, you've already subtracted x
     for (int i = subtrahend.fullNumber.size() - 1; i >= 0; i--) {
        
         //take the number, and subtract the lowest subtrahend value.
         copyMain.subtract(subtrahend.fullNumber.at(i));
         //cout << "In loop\n";
         //takes the value at lowest part and puts it into copymain.
         toBuild.push_back(copyMain.fullNumber.at(copyMain.fullNumber.size() - 1));
         copyMain.fullNumber.pop_back();
         
     }
     //cout << "Completed for loop\n";

     for (int i = toBuild.size() - 1; i >= 0 ; i--) {
         copyMain.fullNumber.push_back(toBuild.at(i));
     }

     //cout << "copyMain = ";
     //copyMain.displayValue();
     //cout << endl;

     *this = copyMain;
     cleanUp();
 }
     
 // The way our subtraction method works
 void UltraNumber::cleanUp() {
     while (fullNumber.at(0) == 0 && fullNumber.size() != 1) {
         fullNumber.erase(fullNumber.begin());
     }
 }

 void UltraNumber::divide(int divisor) {
 
     UltraNumber* labelPtr = this;
     UltraNumber Nult;

    //may need to resubdivide
        //vector<int> v -> every result
    int mod = 0;
    for (int i = 0; i < labelPtr->fullNumber.size(); i++){
        
        long long dividend = add2End(mod,fullNumber.at(i));
        
        /*
        if(dividend >= 1000000000){
            cout << "AJD WARNING: Check dividend value\n";
            cout << "AJD WARNING: May be too big\n";
            cout << "Dividend = " << dividend <<endl;

            cout << "Press any key to continue" <<endl;
            cin.ignore();
        }
        */

        int quotient = dividend/divisor;
        mod = dividend % divisor;
        //Nult.fullNumber.push_back(quotient);
        Nult.fullNumber.push_back(quotient);
    }
    //verify
    Nult.displayValue();
    *this = Nult;

 }
 

 void UltraNumber::mod(int divisor) {

     UltraNumber* labelPtr = this;
     UltraNumber Nult;

     //may need to resubdivide
         //vector<int> v -> every result
     int mod = 0;
     for (int i = 0; i < labelPtr->fullNumber.size(); i++) {

         long long dividend = add2End(mod, labelPtr->fullNumber.at(i));

         /*
         if(dividend >= 1000000000){
             cout << "AJD WARNING: Check dividend value\n";
             cout << "AJD WARNING: May be too big\n";
             cout << "Dividend = " << dividend <<endl;

             cout << "Press any key to continue" <<endl;
             cin.ignore();
         }
         */

         int quotient = dividend / divisor;
         mod = dividend % divisor;
         //Nult.fullNumber.push_back(quotient);
         Nult.fullNumber.push_back(quotient);
     }
     //verify
     UltraNumber l(mod);
     l.displayValue();
     *this = l;

 }


 void UltraNumber::divide(UltraNumber divisor, bool mod) {


    

     /*
        //Doesn't necessarily solve our issue, but what we can do is flip, ^-1, break apart numberator, then divide;
        Let's try this again. -> may work granted, we would have to get decimals figured out first.

     */
     UltraNumber un0(0);
     if (divisor.equalTo(divisor,un0)) {
         cout << "Divide by zero error. Please Try Again" << endl;
         return;
     }

     //Set Multiples of UltraNumber beforeDividing
     divisor.generateMultiples();
     
     //small divide is the number that we are subtracting from (right?)
     UltraNumber smallDivide(0);
     UltraNumber quotient(0);
     //cout << "small divide has been created" << endl;;

     int posL2R = 0;

     //cout << "About to enter while loop" << endl;;
     // 
     //for the following line, we'd have to calculate total digits.
     //We could optimize by not running function every time.
     while (posL2R < this->getNumOfDigits()) {


         //grab digit of dividend and add2End UltraNumber smallDivide.

         //cout << "posL2R = " << posL2R << endl;;
         int toAdd2SmallDivide = grabDigitUN(*this, posL2R);
         //cout << "toAdd2SmallDivide = " << toAdd2SmallDivide << endl;;




         //I don't remember what smallDivide was. Right Right Right, small divide was dividing the current digit, by the divisor. mmmm see about 23 lines ago. 
         smallDivide.add2End(smallDivide.fullNumber, toAdd2SmallDivide);
         //cout << "SmallDivide = ";
         //smallDivide.displayValue();
         //cout << endl;
         // 
         // find closest multiple to small divide without going over.
         //         We'll optimize this later.
         int toAdd2Quotient = divisor.getBestMultiple(smallDivide);
         //cout << "toAdd2Quotient = " << toAdd2Quotient << endl;;
         // 
         // subtract multiple from smallNumber
         UltraNumber temp(divisor.multiples.at(toAdd2Quotient));
         //cout << "temp = ";
         //temp.displayValue();
         //cout << endl;

         quotient.add2End(quotient.fullNumber, toAdd2Quotient);

         //cout << "quotient = ";
         //quotient.displayValue();
         //cout << endl;

         //cout << "----- about to subtract here" << endl;
         //small divide may be the issue, no no no, that's not the issue, temp is wrong value. temp should be 0 (in the test of 3333/3 = 0001
         smallDivide.subtract(temp);

         //cout << "smallDivide = ";
         //smallDivide.displayValue();
         //cout << endl;

         //cout << endl << endl << endl;

         posL2R++;
         // 
         // SmallNumber new value = difference.
         //quotient add2End multiple.

         //repeat until no more numbers left to grab.
     }
     if (mod == false) {
         *this = quotient;
     }
     else {
         *this = smallDivide;
     }

 }

 long long UltraNumber::add2End(int beginP, int endP) {
     int i = 1;
     while( (endP / (int)pow(10, i) ) > 0) {
         i++;
     }
     long long BigNum = (long long) beginP;
     BigNum *= (int)pow(10, i);
     BigNum += endP;
     return BigNum;
 }

 void UltraNumber::generateMultiples() {
     UltraNumber UNOriginal = *this;
      
     multiples.clear();
     vector<int> z = { 0 };
     multiples.push_back(z);


     //NOTE: This needs to be eleven. It causes an error where the expected value should be 9.
     for (int i = 1; i < 11; i++) {
         UNOriginal.multiply(i);
         //we have to use a copy b/c otherwise we keep reseting the multiples thing.
         multiples.push_back(UNOriginal.fullNumber);
         UNOriginal = *this;
     }

     /*
     cout << "AJD Test: making sure multiples are accurate\n";
     for (int i = 0; i < 11; i++) {
         displayVector(multiples.at(i));
         cout << endl;
     }
     */

 }
 
 void displayVector(vector<int> v) {
     for (int i = 0; i < v.size(); i++) {
         cout << v.at(i) << " | ";
     }
 }


 void UltraNumber::binarySearchTreeSort() {
    //Because we know the multiples will always have a length of 10 we can hardcode it.
     
     if (multiples.at(0) > multiples.at(1)) {
        //already sorted
         return;
     }
     vector<vector<int>> newOrder;
     newOrder.push_back(multiples.at(4));
     newOrder.push_back(multiples.at(2));
     newOrder.push_back(multiples.at(7));
     newOrder.push_back(multiples.at(1));
     newOrder.push_back(multiples.at(3));
     newOrder.push_back(multiples.at(5));
     newOrder.push_back(multiples.at(8));
     newOrder.push_back(multiples.at(0));
     newOrder.push_back(multiples.at(6));
     newOrder.push_back(multiples.at(9));

     multiples = newOrder;
 }
 
 //returns position in vector
 int UltraNumber::binarySearchTreeSearch(UltraNumber UNParam) {
 //Price is right, get as close as possible without going over.
     for (int i = 0; i < multiples.size();) {
         if (multiples.at(i) == UNParam.fullNumber) {
             return i;
         }
         if (multiples.at(i) < UNParam.fullNumber) {
            //go right;
         }
     }
 }

 int UltraNumber::binarySearchTreeSearchGenerator(vector<vector<int>> v, int minPos, int maxPos) {
     int average = (minPos + maxPos) / 2;
     return -27;
 }


 /*
 ============================================================
 Don't Use this Grab Digit. We made a better function outside of UltraNumber.
 ===========================================================
 */


 /*
 int UltraNumber::grabDigit(vector<int> v, int posL2R) {
     
     //I believe getSize() gets 10^x;
     //if that is the case we may have to add 9x other digits.
     int size = getSize(v.at(0));


     int d = 0;
     int iteratorOfFullNumber = 0;

     //this may be each individual integer in the list.
     int iterator = 0;

     while (iterator < posL2R) {
         //While first iteration AND UN.fullnumber > 1;
         if (iteratorOfFullNumber == 0 && size < posL2R) {
             iteratorOfFullNumber++;
             iterator += size;
             continue;
         }

         //either my recollection of iterator was wrong or i did this incorrectly.
         else if (iterator + 9 < posL2R ) {
             iteratorOfFullNumber++;
             iterator += 9;
             continue;
         }
         else {
            //Grab digit from this int
             int l = fullNumber.at(iteratorOfFullNumber);
             if (getSize(l) <= 8) {
                 //d is how many 0's there are before number starts
                 d = 9 - getSize(l) ;
                 
                 if (posL2R - iterator < d) {
                     return 0;
                 }
                 else {
                     cout << "AJD NOTE: There should probably be a diff in here somewhere. Otherwise only grabbing first digit of number\n";
                     iterator += d;
                     while (iterator < posL2R) {
                        //iterator++;
                     }
                    l = fullNumber.at(iteratorOfFullNumber);
                    l %= (int)pow(10, (getSize(l)));
                    l /= (int)pow(10, (getSize(l)-1));

                 }
             }
         }

     }
 }
 */


 /*
 carry full system

 find first non-zero
 reduce by 1, then add 10 to the next one. 
    //for simplicity don't do the 0-9 thing.

 
 */
 vector<int> UltraNumber::add2End(vector<int>& begin, int end) {
     
     //cout << "AJD QC: Make sure end is a single digit. Otherwise we need to use shift or something.\n";
     
     UltraNumber newUN(begin);
     newUN.multiply(10);
     newUN.add(end);
     begin = newUN.fullNumber;
     return newUN.fullNumber;
 }

 //gets size of specific int. Like first in the set of fullNumber
 int UltraNumber::getSize(int x) {
     //This feels problematic, either increase i or decrease x, but don't do both. 
     int i = 0;
     while(x / ((int)pow(10, i)) > 0){
         i++;
     }
     return i;
 }

 int grabDigitInt(int mainNumber, int posL2R) {

     cout << "Note, this is a test function. It only works with integers, not UltraNumbers.\n";
     cout << "Note, this function counts in human language. if your number is 123456, the third digit is '3'.\n";

    //Here's an idea, what if we converted back to string, grabbed the digit, I guess that's all that really matters. 
     string s = to_string(mainNumber);
     char c = s.at(posL2R-1);
     s = c;
     int value = stoi(s);
     return value;
 }

 int grabDigitUN(UltraNumber mainNumber, int posL2R) {
     //cout << "Note, this function counts in computer language. if your number is 123456, the third digit is '4'.\n";
     vector<string> vs = { "" };

     string s;

     //converts all ints into strings;
     for (int i = 0; i < mainNumber.fullNumber.size(); i++) {
         
         //First we need to check getSize and add 0's accordingly;
         int sizeOfInt = mainNumber.getSize(mainNumber.fullNumber.at(i));
         int diff = -27;
         bool addZeros = false;
         
         if (sizeOfInt <= 7 && i != 0) {
             diff = 9 - sizeOfInt;
             addZeros = true;
         }

         s = to_string(mainNumber.fullNumber.at(i));
         if (addZeros == true) {
             for (int j = 0; j < diff; j++) {
                 string s2 = "0";
                 s2 += s;
                 s = s2;
             }
         }

         vs.push_back(s);
     }
     
     string big = "";

     //puts all strings into one big string;
     for (int i = 0; i < vs.size(); i++) {
         big += vs.at(i);
     }
     char c = big.at(posL2R);
     big = c;
     int value = stoi(big);;

     return value;

 }

 int UltraNumber::getBestMultiple(UltraNumber greaterUltra) {
    //check to make sure that getMultiples has been ran. Actually maybe just do it anyway. 
     
     this->generateMultiples();
     
     int i = 0;
     
     while (true) {
         //cout << "We are in while loop of getBestMultiple. i = " << i << endl;
         UltraNumber UN2(this->multiples.at(i));
        
         if (lessThanComparison(UN2, greaterUltra)) {
             i++;
             continue;
         }
         else {

             if (equalTo(UN2, greaterUltra)) {
                 return i;
             }
             break;
         }

     }

     i--;
     return i;
 }

 int UltraNumber::getNumOfDigits() {
     
     //we would use size, but we don't want to include the first one. 
     int numOfD = this->fullNumber.size() - 1;
     numOfD *= 9;
     numOfD += this->getSize(this->fullNumber.at(0));
     return numOfD;

 }

 bool UltraNumber::lessThanOrEqualTo(UltraNumber small, UltraNumber large) {
     if (lessThanComparison(small, large) == true) {
         return true;
     }
     // check to see if equal.
     else {
         if (equalTo(small, large) == true) {
             return true;
         }
     }
 }

 bool UltraNumber::equalTo(UltraNumber A, UltraNumber B) {
     
     int size2 = A.getSize(A.fullNumber.at(0));
     
     if (A.fullNumber.size() != B.fullNumber.size()) {
         return false;
     }
     else if (size2 != B.getSize(B.fullNumber.at(0)) ) {
         return false;
     }
     else {
         int size = (A.fullNumber.size() - 1) * 9;
         size += size2;
         for (int i = 0; i < A.fullNumber.size(); i++) {
             if (A.fullNumber.at(i) != B.fullNumber.at(i)) {
                 return false;
             }
         }
     }

     return true;

 }

 void UltraNumber::mod(UltraNumber A) {
     this->divide(A, true);
 }