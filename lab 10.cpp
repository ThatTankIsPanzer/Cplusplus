#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
enum status {TH, TL, RT}; 
void generatePassWd(string &passWd, int &passLen); 
void guess (status &guessing, string p, int pLen);
int main() {
	char play = 'y';
	status nows = TH;// nowStatus.
    string passWd, passwd;
	int pwLen = passWd.length();
	int j =1;
    cout << "Guessing a password at most having four lower-cases letters. My guess is as follow:" << endl;
    generatePassWd(passWd,pwLen);
    passwd = passWd;
    while (nows != RT || play == 'y' || play == 'Y'){
	    passWd = passwd;
    	cout << passwd << endl;
        if (j == 1){
		    cout << "1-nd guess = ";
		    j++;
		}
		else if (j == 2){
		    cout << "2-nd guess = ";
		    j++;
	    }
		else if (j == 3){
		    cout << "3-rd guess = ";
		    j++;
	    }
	    else {
	    	cout << j << "-th guess = ";
	    	j++;
		}
	    guess(nows, passwd, pwLen);
    
        if (nows == TH){
            cout << "too high.  Try again" << endl;
	    }
	    else if (nows == TL){
            cout << "too low.  Try again" << endl;
	    }
	    else if (nows == RT){
            cout << "Bravo, you guess it right!" << endl;
            if(j > log2(double(pwLen))){
                cout << "You know the secret!" << endl;
                cout << "Play the game again ? (y or Y for yes): " << endl;
	            cin  >> play;
	            j = 1;
	            generatePassWd(passWd, pwLen);
                passwd = passWd;
            }
		    else{
		        cout << "You should be able to do better." << endl;
		        cout << "Play the game again ? (y or Y for yes): " << endl;
	            cin  >> play;
	            j = 1;
	            generatePassWd(passWd,pwLen);
                passwd = passWd;
		    }
		}
    }
}
void guess (status &guessing, string p, int pLen){
	string myguess;
	cin >> myguess;
	int mygLen = myguess.length();
    
        if (myguess > p && mygLen >= pLen){
    	    guessing = TH;
	    }
	    else if (myguess < p && mygLen <= pLen){
    	    guessing = TL;
	    }
	    else if (myguess == p && mygLen == pLen){
    	    guessing = RT;
	    }
}
void generatePassWd(string &passWd, int &passLen){
    srand(time(0));
    passLen = rand()%4+1;
    if (passLen == 1){
    	passWd = "a";
        for (int i = 0; i < passLen; i++){
            passWd[i] = 'a' + rand() % 26;
        }
    }
    if (passLen == 2){
    	passWd = "aa";
        for (int i = 0; i < passLen; i++){
            passWd[i] = 'a' + rand() % 26;
        }
    }
	if (passLen == 3){
		passWd = "aaa";
        for (int i = 0; i < passLen; i++){
            passWd[i] = 'a' + rand() % 26;
        }
    }
    if (passLen == 4){
    	passWd = "aaaa";
        for (int i = 0; i < passLen; i++){
            passWd[i] = 'a' + rand() % 26;
        }
    }
}
