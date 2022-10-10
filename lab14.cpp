#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void displayAccount(vector<int> &accNum, vector<string> &fName, vector<string> &lName, vector<double> &actBal,
vector<string> &dateV, vector<string> &timeV, vector<string> &validV, vector<string> &acTV, vector<bool> &kept);
int main(int argc, char** argv) {
	vector<int> accNum(11), accNum1(11);
	vector<string> fName(11), fName1(11);
	vector<string> lName(11), lName1(11);
	vector<double> actBal(11), actBal1(11);
	vector<string> dateV(11), dateV1(11);
	vector<string> timeV(11), timeV1(11);
	vector<string> validV(11), validV1(11);
	vector<string> acTV(11), acTV1(11);
	vector<bool> kept(11);
	ifstream ifptr;
	ifstream ifptr1;
	ifptr.open(argv[1], ios::in);
	if(!ifptr){
        cerr << "please input file!";
        exit(1);
	}
	ifptr1.open(argv[2], ios::in);
	if(!ifptr){
        cerr << "please input file!";
        exit(1);
	}
	if(argc < 2){
        cout << "ERROR: no input file is given!" << endl;
        exit (2);
    }
    
	for(int n = 0; n < 999; n++){
        if (ifptr >> accNum[n] >> fName[n] >> lName[n] >> actBal[n] >>  dateV[n] >> timeV[n] >> validV[n] >> acTV[n]){
            cout << accNum[n] << fName[n] << lName[n] << actBal[n] <<  dateV[n] << timeV[n] << validV[n] << acTV[n] << endl;
        }
        else{
            break;
        }
	}
	for(int n = 0; n < 999; n++){
        if (ifptr1 >> accNum1[n] >> fName1[n] >> lName1[n] >> actBal1[n] >>  dateV1[n] >> timeV1[n] >> validV1[n] >> acTV1[n]){
            cout << accNum1[n] << fName1[n] << lName1[n] << actBal1[n] <<  dateV1[n] << timeV1[n] << validV1[n] << acTV1[n] << endl;
        }
        else{
            break;
        }
	}
    //displayAccount(accNum, fName, lName, actBal, dateV, timeV, validV, acTV, kept);
	ifptr.close();
	ifptr1.close();

	return 0;
}
/*void displayAccount(vector <int> &accNum, vector <string> &fName, vector <string> &lName, vector <double> &actBal, vector <string>
&dateV, vector <string> &timeV, vector <string> &validV, vector <string> &acTV, vector <bool> &kept) {
    ifstream inFile("mergedAcount.txt", ios::in);
    if(!inFile){
        cout << "Error: File does not exit. " << endl;
        exit(1);
    }
    else inFile.close();
    int numActualAct = 0;
    for(int i=0; i < accNum.size(); i++){
        if(kept[i]==true){
            cout << setw(8) << setfill('0') << accNum[i] << setfill(' ') << setw(10) << fName[i] << setw(10) << lName[i] << " " << setw(8) << actBal[i] << " " << setw(10) << acTV[i] << " " << dateV[i] << " " << timeV[i] << " " << setw(8) << validV[i] << endl;
            numActualAct++;
        }
    }
    cout << "Number of accounts: " << numActualAct << endl;
}*/
