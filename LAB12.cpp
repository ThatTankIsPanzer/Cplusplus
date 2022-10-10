#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <typename T>
void findSecondLargest(T anAry[], int numElm, T &secondLargest, int &loc){
	T maxvalue = anAry[0];
    secondLargest = anAry[1];
	int n = 0;
	loc = -1;

	for (int i = 0; i < numElm; i++){
		if (i == numElm){
			break;
		}
	}
	
	for (int j = 1; j < numElm; j++){		 
        if (maxvalue < anAry[j]) {
    		maxvalue = anAry[j];
		}
		if (maxvalue == secondLargest){
			secondLargest = anAry[j-1];
		}
	}
	
	for (int k = 0; k < numElm; k++){
		if (maxvalue > anAry[k] && secondLargest < anAry[k]){
			secondLargest = anAry[k];
			
		}
		if (maxvalue != secondLargest && secondLargest == anAry[k]){
			loc = k;
		}
	}
}

int main() {
	int tc1;      //test case1.
	int tc2;      //test case2.
	string dt;    // data type.
	int value1[10000];       // max array for int.
	double value2[10000];    // max array for double.
	string value3[10000];    // max array for string.
	int scl1;      //secondLargest for int.
	double scl2;   //secondLargest for double.
	string scl3;   //secondLargest for string.
	int loc;
	cin >> tc1;
	
	for (int j = 0; j < tc1; j++){
	    cin >> dt;
	    cin >> tc2;
        for(int i = 0; i < tc2; i++){
            if(dt == "int"){
    	        int number;    // integer.
    	        cin >> number;
    	        value1[i] = number;
            }
            else if(dt == "double"){
        	    double doubleN;    //double value.
    	        cin >> doubleN;
    	        value2[i] = doubleN;
            }
            else if(dt == "string"){
            	string stringA;    //string alphabet.
    	        cin >> stringA;
    	        value3[i] = stringA;
            }
            else{
	            return 1;
            }
        }
        
        if (dt == "int"){
            findSecondLargest(value1, tc2, scl1, loc);
            if (loc == -1){
        	    cout << "#" << ' ' << loc << endl;
		    }
		    else {
                cout << scl1 << ' ' << loc << endl;
            }
        }
        else if (dt == "double"){
            findSecondLargest(value2, tc2, scl2, loc);
            if (loc == -1){
        	    cout << "#" << ' ' << loc << endl;
		    }
		    else {
                cout << scl2 << ' ' << loc << endl;
            }
        }
        else if (dt == "string"){
            findSecondLargest(value3, tc2, scl3, loc);
            if (loc == -1){
        	    cout << "#" << ' ' << loc << endl;
		    }
		    else {
                cout << scl3 << ' ' << loc << endl;
            }
        }
    }
	return 0;
}
