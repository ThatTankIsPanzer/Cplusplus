#include <iostream>
#include <fstream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//void readGrades(ifstream &inFile, int studentGrades[][tests], int &numStudents, int &numTests);
int main() {
	/*string fileN;
	cout << "input file name: " << endl;
	cin >> fileN;
	ifstream ifptr;
	ifptr.open(fileN);
	if(!fileN){
		cout << "File name could be incorrect." << endl;
		exist(1);
	}
	//void readGrades(ifstream &inFile, int studentGrades[][tests], int &numStudents, int &numTests);*/
	
	string fileName;
	ifstream myPtr;
	cin >> fileName;
	myPtr.open(,ios::in);
	if ( !myPtr.is_open()){
		cout << "Error opening file";
		exit(1);
	}
	
	
	return 0;
}
/*void readGrades(ifstream &inFile, int studentGrades[][tests], int &numStudents, int &numTests) {
	for()
    }
}*/
