#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

using namespace std;

class Helper {
private:
public:

	static int displayYN();
	static int displayChoice(string s, string s2);
	static int displayChoiceVector(vector<string>);
	
	
	//Use this one if you always want to display a cycle option. i.e. "5. More Options"
	static int displayChoiceVectorCycle(vector<string>, int SavePos = 4);
	
	
	// In progress;
	//static int displayChoiceVectorLarge(vector<string> list, int startPos, vector<string> alwaysShow);


};

#endif
