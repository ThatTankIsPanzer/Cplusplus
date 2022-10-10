#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int num;
	char c;
	int astr;
    int strLen;
    
    cin >> num;
    while(num > 0){
    	cin >> astr;
    	for(int i = 0; i < strLen / 2;i++){
            c = astr[i];
            astr[i] = aStr[strLen-1-i];
            astr[strLen-1-i] = c;
        }
    cout << aStr << endl
	}
	return 0;
}
