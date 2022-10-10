#include <iostream>
#include <string>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	string aStr; 
	int letters[26]={0};
	int L[16]={0};
	int FL[27]={0};
	int SV=0,NSV=0;    //starting with vowel and no starting with vowel.
	int SA=0;    //starting with alphabet.
	int WSD=0;    //with started a digit.
	int NA=0;
	int sum;
	int same;
	while(cin >> aStr){
		int leng = aStr.length();
		for(int i=0;i<leng;i++){
            if(aStr[i]==':')
                leng--;
            if(aStr[i]=='.')
                leng--;
            if(aStr[i]==',')
                leng--;
        }
        
        switch (aStr[0]){
            case 'a':  case 'A':
            	SV++;
            	letters[0]++;
            	if(leng>0){
            		leng--;
            		if(aStr[leng]=='a'|| aStr[leng]=='A'){
            			FL[1]++;
					}
				}
                break;
            case 'e':  case 'E':
                SV++;
                letters[1]++;
                if(leng>0){
            		leng--;
            		if(aStr[leng]=='e'|| aStr[leng]=='E'){
            			FL[2]++;
					}
				}
                break;
            case 'i':  case 'I':
                SV++;
                letters[2]++;
                if(leng>0){
            		leng--;
            		if(aStr[leng]=='i'|| aStr[leng]=='I'){
            			FL[3]++;
					}
				}
                break;
            case 'o':  case 'O':
                SV++;
                letters[3]++;
                if(leng>0){
            		leng--;
            		if(aStr[leng]=='o'|| aStr[leng]=='O'){
            			FL[4]++;
					}
				}
                break;
            case 'u':  case 'U':
                SV++;
                letters[4]++;
                if(leng>0){
            		leng--;
            		if(aStr[leng]=='u'|| aStr[leng]=='U'){
            			FL[5]++;
					}
				}
                break;
            case 'b':  case 'B':
                NSV++;
                letters[5]++;
                if(leng>0){
            		leng--;
            		if(aStr[leng]=='b'|| aStr[leng]=='B'){
            			FL[6]++;
					}
				}
                break;
            case 'c':  case 'C':
                NSV++;
                letters[6]++;
                if(leng>0){
            		leng--;
            		if(aStr[leng]=='c'|| aStr[leng]=='C'){
            			FL[7]++;
					}
				}
                break;
            case 'd':  case 'D':
                NSV++;
                letters[7]++;
                break;
            case 'f':  case 'F':
                NSV++;
                letters[8]++;
                break;
            case 'g':  case 'G':
                NSV++;
                letters[9]++;
                break;
            case 'h':  case 'H':
                NSV++;
                letters[10]++;
                break;
            case 'j':  case 'J':
                NSV++;
                letters[11]++;
                break;
            case 'k':  case 'K':
                NSV++;
                letters[12]++;
                break;
            case 'l':  case 'L':
                NSV++;
                letters[13]++;
                break;
            case 'm':  case 'M':
                NSV++;
                letters[14]++;
                break;
            case 'n':  case 'N':
                NSV++;
                letters[15]++;
                break;
            case 'p':  case 'P':
                NSV++;
                letters[16]++;
                break;
            case 'q':  case 'Q':
                NSV++;
                letters[17]++;
                break;
            case 'r':  case 'R':
                NSV++;
                letters[18]++;
                break;
            case 's':  case 'S':
                NSV++;
                letters[19]++;
                break;
            case 't':  case 'T':
                NSV++;
                letters[20]++;
                break;
            case 'v':  case 'V':
                NSV++;
                letters[21]++;
                break;
            case 'w':  case 'W':
                NSV++;
                letters[22]++;
                break;
            case 'x':  case 'X':
                NSV++;
                letters[23]++;
                break;
            case 'y':  case 'Y':
                NSV++;
                letters[24]++;
                break;
            case 'z':  case 'Z':
                NSV++;
                letters[25]++;
                break;
			case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                WSD++;
                break;  
            default:
            	NA++;
        }    
        
        sum++;
		switch(leng){
			case 1 :
                L[1]++;
                break;
            case 2 :
                L[2]++;
                break;
            case 3 :
                L[3]++;
                break;
            case 4 :
                L[4]++;
                break;
            case 5 :
                L[5]++;
                break;
            case 6 :
                L[6]++;
                break;
            case 7 :
                L[7]++;
                break;
            case 8 :
                L[8]++;
                break;
            case 9 :
                L[9]++;
                break;
            case 10 :
                L[10]++;
                break;
            case 11 :
                L[11]++;
                break;
            case 12 :
                L[12]++;
                break;
            case 13 :
                L[13]++;
                break;
            case 14 :
                L[14]++;
                break;
            case 0 :
                L[0]++;
                break;
            default :
                L[15]++;
                break;
		}
		
    }
    cout << "Total number of words: "<< sum << endl;
    cout << "Total number of words starting with a vowel: " << SV << endl;
    cout << "Total number of words not starting with a vowel, but with an alphabet: " << NSV << endl;
    cout << "Total number of words started with an alphabet: " << NSV+SV << endl;
    cout << "Total number of words started with a digit: " << WSD << endl;
    cout << "Distribution of words by word length: " << endl;
    cout << "L=0" << "  " <<  L[0] << endl;
    cout << "L=1" << "  " <<  L[1] << endl;
    cout << "L=2" << "  " << L[2] << endl;
    cout << "L=3" << "  " << L[3] << endl;
    cout << "L=4" << "  " << L[4] << endl;
    cout << "L=5" << "  " << L[5] << endl;
    cout << "L=6" << "  " << L[6] << endl;
    cout << "L=7" << "  " << L[7] << endl;
    cout << "L=8" << "  " << L[8] << endl;
    cout << "L=9" << "  " << L[9] << endl;
    cout << "L=10" << "  " << L[10] << endl;
    cout << "L=11" << "  " << L[11] << endl;
    cout << "L=12" << "  " << L[12] << endl;
    cout << "L=13" << "  " << L[13] << endl;
    cout << "L=14" << "  " << L[14] << endl;
    cout << "L>=15" << "  " << L[15] << endl;
    cout << "Distribution of words by first letter: " << endl;
    cout << "A/a:" << letters[0] << endl;
    cout << "B/b:" << letters[1] << endl;
    cout << "C/c:" << letters[2] << endl;
    cout << "D/d:" << letters[3] << endl;
    cout << "E/e:" << letters[4] << endl;
    cout << "F/f:" << letters[5] << endl;
    cout << "G/g:" << letters[6] << endl;
    cout << "H/h:" << letters[7] << endl;
    cout << "I/i:" << letters[8] << endl;
    cout << "J/j:" << letters[9] << endl;
    cout << "K/k:" << letters[10] << endl;
    cout << "L/l:" << letters[11] << endl;
    cout << "M/m:" << letters[12] << endl;
    cout << "N/n:" << letters[13] << endl;
    cout << "O/o:" << letters[14] << endl;
    cout << "P/p:" << letters[15] << endl;
    cout << "Q/q:" << letters[16] << endl;
    cout << "R/r:" << letters[17] << endl;
    cout << "S/s:" << letters[18] << endl;
    cout << "T/t:" << letters[19] << endl;
    cout << "U/u:" << letters[20] << endl;
    cout << "V/v:" << letters[21] << endl;
    cout << "W/w:" << letters[22] << endl;
    cout << "X/x:" << letters[23] << endl;
    cout << "Y/y:" << letters[24] << endl;
    cout << "Z/z:" << letters[25] << endl;
    cout << "0~9:" << WSD << endl;
    cout << "Other:" << NA << endl;
    cout << "Distribution of words whose first and last letters are the same: " << endl;
    cout << "A/a:" << FL[1] << endl;
    cout << "B/b:" << FL[2] << endl;
    cout << "C/c:" << FL[3] << endl;
    cout << "D/d:" << FL[4] << endl;
    cout << "E/e:" << FL[5] << endl;
    cout << "F/f:" << FL[6] << endl;
    cout << "G/g:" << FL[7] << endl;
    cout << "H/h:" << FL[8] << endl;
    cout << "I/i:" << FL[9] << endl;
    cout << "J/j:" << FL[10] << endl;
    cout << "K/k:" << FL[11] << endl;
    cout << "L/l:" << FL[12] << endl;
    cout << "M/m:" << FL[13] << endl;
    cout << "N/n:" << FL[14] << endl;
    cout << "O/o:" << FL[15] << endl;
    cout << "P/p:" << FL[16] << endl;
    cout << "Q/q:" << FL[17] << endl;
    cout << "R/r:" << FL[18] << endl;
    cout << "S/s:" << FL[19] << endl;
    cout << "T/t:" << FL[20] << endl;
    cout << "U/u:" << FL[21] << endl;
    cout << "V/v:" << FL[22] << endl;
    cout << "W/w:" << FL[23] << endl;
    cout << "X/x:" << FL[24] << endl;
    cout << "Y/y:" << FL[25] << endl;
    cout << "Z/z:" << FL[26] << endl;
	return 0;
    }
