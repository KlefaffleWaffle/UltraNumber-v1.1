
#include "Helper.h";
#include <iostream>
using namespace std;


int Helper::displayYN() {
	cout << "1. Yes\n2. No\n\n";
	int x;
	cin >> x;
	return x;
}

int Helper::displayChoice(string s1, string s2) {
	cout << "1. " << s1 << "\n2. " << s2 << "\n\n";;
	int x;
	cin >> x;
	return x;
}

int Helper::displayChoiceVector(vector<string> v) {

	for (int i = 0; i < v.size(); i++) {
		cout << (i + 1) << ". " << v.at(i) << "\n";
	}
	cout << "\n";

	int x;
	cin >> x;
	return x;
}



int Helper::displayChoiceVectorCycle(vector<string> v, int pos){
		//Trying to make this iterative not recursive, ergo, no starting pos.
		
		//display four items at a time.
		//skip the parameter item. Default fifth.
		
		//this do is just saying keep calling display until you get exit code.
		
	
	
	/*
	int startingPos = 0;
		
		bool endOfVector = false;
		do{
			//this is the sub routine that actually displays
			//we use +4 b/c 5th is reserved.
			if(endOfVector == true){
				startingPos = 0;
				endOfVector = false;
			}else{
			
				for(int i = startingPos; i < startingPos+4; i++){
					if(startingPos == pos){
					startingPos++;
					break;	
					}
				
					if(i < v.size()){
						cout << i+1 <<". " <<v.at(i)<<endl;
					}else{
					cout << endl;
					endOfVector = true;	
					}
				}
				cout << pos+1 <<". " << v.at(pos)<<endl;
			}
			int r=-27;
			cin >> r;
		}while(r != pos+1);

		*/
		return -27;
}

/* IN PROGRESS
int Helper::displayChoiceVectorLarge(vector<string> list, int startPos, vector<int> alwaysShow){
		
		
		//error handling
		if(alwaysShow.size()> list.size()){
			cout << "Check 1: Size issue\n";
			cout << "AJD ERROR:\n\t\"always show\" parameter cannot exceed list in size.\nRecommended terminate program and correct. Returning -27\n";
			return -27; 
		}
		
		//scan for duplicates;
		sort(alwaysShow.begin(), alwaysShow.end());
		bool alreadyAsked = false;
		for(int i = 1; i < alwaysShow.size(); i++){
			if(alwaysShow.at(i) == alwaysShow.at(i-1) && alreadyAsked == false){
				cout << "Check 2: No duplicates\n";
			cout << "AJD ERROR:\n\t\"always show\" duplicates found.\n";
			cout << "Would you like to have program correct or terminate?\n";
			int i = displayChoice("Correct for me", "Terminate Program");
				if( i == 2){
				return -27;
				}else{
				alreadyAsked = true;
				}	
			}
		}
		
		//This implies at least one duplicate. 
		if(alreadyAsked == true){
		vector<int> noDupe = {alwaysShow.at(0)};	
			for(int i = 1; i < alwaysShow.size(); i++){
				
				if(alwaysShow.at(i) == alwaysShow.at(i-1)){
					continue;
				}else{
					noDupe.push_back(i);
				}
			}
			alwaysShow = noDupe;
		}
		//Just skip always show to big for list. 
		bool append = false;
		int diff = 5;
		if (alwaysShow.size() >= 5){
			append = true;
		}else{
		diff = 5 - alwaysShow.size();	
		}
		
		int input = 0;
		
		
		while(input%diff == 0){
			
		}
		
	

}
*/
