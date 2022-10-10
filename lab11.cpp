#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void createRecord(ofstream &fptr, const char *fileN, string firstN, string lastN, double actBal);
void removeDuplicateRecords(fstream &fptr, const char *fileN);
void displayFile(ifstream &fptr, const char *fileN);

int main(){
	ofstream ofptr;
	ifstream infptr;
	string firstN[1000];
	string lastN[1000]; 
	double actBal[1000];
	string nfirstN;
	string nlastN;
	double nactBal;
	int count;
	time_t transTime[1000];
	
	infptr.open("clientFile.txt", ios :: in); 
	if (!infptr){
        cout << "Creating a new file :" << endl;
    }
    else{
    	cout << "Exist content :" << endl;
        for(count = 0; count < 1000; count++){
    	    if(!(infptr >> firstN[count] >> lastN[count] >> actBal[count] >> transTime[count])){
    		    break;
		    }
	    }
    }
	displayFile(infptr, "clientfile.txt");
	infptr.close();
	
    ofptr.open("clientFile.txt", ios :: out);
    for(int i = 0; i < count; i++){
    	ofptr << firstN[i] << ' ' << lastN[i] << ' ' << actBal[i] << ' ' << transTime[i];
    } 
	
	/*infptr.open("clientFile.txt", ios :: in);
	displayFile(infptr, "clientfile.txt");
	infptr.close();*/
	
    if (!ofptr){
    	cerr << "file could not be opened" << endl;
        exit(1);
    }
	cout << "Enter the firstname , lastname and balance :" << endl;
    while (cin >> nfirstN >> nlastN >> nactBal){
        createRecord(ofptr,"clientfile.txt" , nfirstN, nlastN, nactBal) ;
    }
	ofptr.close();
	
	ifstream ifptr("clientfile.txt", ios::in);
    if (!ifptr){
        cerr << "file could not be opened" << endl;
        exit(1);
    }
    ifptr.close();    // double check. 
	
	fstream cfptr ("clientfile.txt", ios::in|ios::out|ios::app);
    removeDuplicateRecords(cfptr, "clientfile.txt");
	
	ifstream ifptr1("clientfile.txt", ios::in);
	
    if (!ifptr1){
        cerr << "file could not be opened" << endl;
        exit(1);
    }
	
    displayFile(ifptr1, "clientfile.txt");
    ifptr1.close();
    
    return 0;
}
void createRecord(ofstream &fptr, const char *fileN, string firstN, string lastN, double actBal){
    fileN = "clientFile.txt";
    time_t transTime;
    time (&transTime);
    fptr << firstN << ' ' << lastN << ' ' << actBal << ' ' << transTime; 
}

void removeDuplicateRecords(fstream &fptr, const char *fileN){
	string firstN[1000] = {};
    string lastN[1000] = {};
    double actBal[1000] = {};
	time_t transTime[1000] = {};
	int n = 0;
	
    while(fptr >> firstN[n] >> lastN[n] >> actBal[n] >> transTime[n]){
    	n++;
	}
	ofstream rfptr;
	rfptr.open ("clientFile.txt", ios::trunc);
    for(int i = 0; i < n; i++){
        bool record = false;
        for(int j = 0; j < n; j++){
           if (i != j){
               if(firstN[i] == firstN[j] && lastN[i] == lastN[j] && actBal[i] < actBal[j]){
                   record = true;
                   break;
                }
            }
        }
        if(!record){
            rfptr << firstN[i] << ' ' << lastN[i] << ' ' << actBal[i] << ' ' << transTime[i];
        }
    }
    
    rfptr.close();
}

void displayFile(ifstream &fptr, const char *fileN){
	string str1;
    string str2;
    double balance;
    int numAct = 0;
    time_t transTime;
    fptr.clear();
    fptr.seekg(0);
    
    while(fptr >> str1 >> str2 >> balance >> transTime) {
        cout << setw(15) << str1 << ' ' << setw(15) << str2 << ' '
        << setw(7) << balance << " " << ctime(&transTime);
        numAct++;
    }
        cout << "Number of records in the file " << fileN << ": " << numAct << endl;
}
