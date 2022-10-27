#include <iostream>
#include <sstream>
#include <string>
#include <algorithm> // std::sort
using namespace std;
int main()
{
	int testcase; //Number of test cases
	string aLine;
	stringstream ssLine;
	int dist[500]={0}; // Storing distance
	int t = 0;
	int i = 0;
	//cin>>testcase;
	//getline(cin, aLine); // completing reading the first line
	while(getline(cin, aLine)) {
		int h = 0; //Number of houses
		int addr[30000]; //Storing addresses
		int bestLoc=0; // Best location
		//getline(cin, aLine); // getting a test case
		ssLine << aLine; // writing aLine into ssLine;
		// Read the input data of each test cases
		while (ssLine >> addr[h])
			h++;
		sort(addr,addr+h); // Sort all the addresses
		bestLoc=addr[(int)h/2]; // Take median
		for(int j=0; j<h; j++)
			dist[i]+=abs(addr[j]-bestLoc);
			//cout<<"Optimal : "<< bestLoc <<endl;
			//cout<<"Distance : "<<dist[i]<<endl;
		ssLine.str(string()); // reset ssLine to an empty string
		ssLine.clear(); // reset flag ¡§eof¡¨ to 0
		t++;
		i++;
}
for (int i=0;i<t;i++)
	cout<<dist[i]<<endl;
return 0;
}
