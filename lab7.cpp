#include <iostream>
#include <iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int tc=0;//test cases.
	int R1L1,R1L2;
	int R1R1,R1R2;
	int R2L1,R2L2;
	int R2R1,R2R2;
	
	cin >> tc;
	for(int i=0; i<tc; i++){
		cin >> R1L1 >> R1L2 >> R1R1 >> R1R2 >> R2L1 >> R2L2 >> R2R1 >> R2R2;
		  if (R1L1 > R2R1 || R2L1 > R1R1 || R1L2 > R2R2 || R2L2 > R1R2 ){
        cout << "No"<< endl;
    }
    else{
        cout << "Yes"<< setw(3);

        if (R1L1 >= R2L1 && R1L2 >= R2L2 && R2R1 >= R1R1 && R2R2 >=R1R2){
            cout << "4" << setw(3);
        }
        else if (R1L2 < R2L2 && R1R2 > R2R2){
            cout << "0" << setw(3);
        }
       else if  (R2L1 > R1L1 && R1R1 > R2R1){
           cout << "0" << setw(3);
       }
       else if (R1R1 >= R2L1 && R1R2 >= R2L2 && R1L1 < R2L1 && R1L2 < R2L2){
           cout << "1" << setw(3);
       }
       else if (R2R1 >= R1L1 && R2R1 < R1R1 && R2L2 <= R1R2 && R2L2 > R1L2){
           cout << "1" << setw(3);
       }
       else if (R2L1 > R1L1 && R2L1 <= R1R1 && R1R2 > R2R2 && R2R2 >= R1L2){
           cout << "1" << setw(3);
       }
       else if (R1L1 <= R2R1 && R2R1 < R1R1 && R1L2 <= R2R2 && R2R2 < R1R2){
           cout << "1" << setw(3);
       }
       else{
           cout << "2" << setw(3);
       }


       if (R1L1 <= R2L1 && R1L2 <= R2L2 && R2R1 <= R1R1 && R2R2 <= R1R2){
            cout << "4" << endl;
       }
       else if ( R1L2 > R2L2 && R1R2 < R2R2){
            cout << "0" << endl;
       }
       else if (R2L1 < R1L1 && R1R1 < R2R1){
            cout << "0" << endl;
       }
       else if (R2L1 < R1L1 && R2L2 < R1L2 && R1L1 <= R2R1 && R1L2 <=R2R2){
            cout << "1" << endl;
       }
       else if (R2L1 <= R1R1 && R1R1 < R2R1 && R2L2 <= R1R2 && R1R2 < R2R2){
            cout << "1" << endl;
       }
       else if (R2L1 <= R1R1 && R1R1 < R2R1 && R2L2 < R1L2 && R1L2 <= R2R2 ){
            cout << "1" << endl;
       }
       else if (R2L1 < R1L1 && R1L1 <= R2R1 && R2L2 <= R1R2 && R1R2 < R2R2){
            cout << "1" << endl;
       }
       else{
            cout << "2" << endl;
       }
	    
	        
		
	}
		

		
	}
		    
		    
	
	return 0;
}
//(R1L1,R2L2)(R1R1,R1R2)(R2L1,R2L2)(R2R1,R2R2)
//(R1L1,R2R2)(R1R1,R2L2)(R2L1,R2R2)(R2R1,R2L2)
