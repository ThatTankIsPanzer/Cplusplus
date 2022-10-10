#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int tc;
	float x1,y1;
	float x2,y2;
	float x3,y3;
	float x4,y4;
	float a1=0,b1=0,a2=0,b2=0;
	float x=0,y=0;  
	
	cin >> tc;
	
	for(int i = 0; i <tc; i++){ 
		
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		
        //y1 = a1 * x1 + b1;
        //y2 = a1 * x2 + b1;
        
        //y3 = a2 * x3 + b2;
        //y4 = a2 * x4 + b2;
    
        a1 = (y2 - y1)/(x2 - x1);  // slope 1.
        b1 = y2 - a1 * x2;         // xzero 1.
        
        a2 = (y4 - y3)/(x4 - x3);  // slope 2.
        b2 = y4 - a2 * x4;         // xzero 2.
        
        //Y1 = X1 * a1 + b1;
        //Y2 = X2 * a2 + b2;
        //Y1=Y2;  X1=X2;
        
        if(x1 == x3 && y1 == y3 && x2 == x4 && y2 == y4){
        	cout << "yes" << "   " << "coincide 重合" << endl;
		}
		else if(x1 == x4 && y1 == y4 && x3 == x2 && y3 == y2){
        	cout << "yes" << "   " << "coincide 重合" << endl;
		}
		else if(a1 == a2 && b1 == b2 && x1 <= x4 && y1 <= y4 && x2 >= x3 && y2 >= y3){
			cout << "yes" << "   " << "coincide 重合" << endl;
		}
		else if(a1 == a2 && b1 == b2 && x1 >= x4 && y1 >= y4 && x2 <= x3 && y2 <= y3){
			cout << "yes" << "   " << "coincide 重合" << endl;
		}
		else if((a1 == 0 && b1 != 0 && y1 == y2 && y1 > y3 && y1 < y4) || (a1 == 0 && b1 != 0 && y1 == y2 && y1 < y3 && y1 > y4) || (a2 == 0 && b2 != 0 && y3 == y4 && y3 > y1 && y3 < y2) || (a2 == 0 && b2 != 0 && y3 == y4 && y3 < y1 && y3 > y2)
		  ||  (a1 != a2 && (y1 == y3 || y1 == y4) && (y2 == y3 || y2 == y4) && (x1 > x3 && x2 < x4)) || (a1 != a2 && (y1 == y3 || y1 == y4) && (y2 == y3 || y2 == y4) && (x1 < x3 && x2 > x4))){
			cout << "yes" << "   ";
			if((a1 != a2 && (y1 == y3 || y1 == y4) && (y2 == y3 || y2 == y4) && (x1 > x3 && x2 < x4)) || (a1 != a2 && (y1 == y3 || y1 == y4) && (y2 == y3 || y2 == y4) && (x1 < x3 && x2 > x4))){
			    if(x1 == x2){
				    x = x1;
				    if(a1 != 0){
				        y = a1 * x1 + b1;
			        } 
			        else if(a2 != 0){
				        y = a2 * x1 + b2;
			        }
			    } 
			    else if(x3 == x4){
				    x = x3;
				    if(a1 != 0){
				        y = a1 * x3 + b1;
			        } 
			        else if(a2 != 0){
				        y = a2 * x3 + b2;
			        }
			    }
			cout << x << "   " << y << endl;
		}
		else{
				x=(b1-b2)/-(a1-a2);
            y=x*a2+b2;
            cout << x << "  " << y << endl;
		}
		
		}
        else if((a1 == 0 && y1 != y2 && x1 != x3 && x1 != x4) || (a2 == 0 && y3 != y4 && x3 != x2 && x3 != x1) || (a1 == 0 && y1 == y2 && y1 != y3 && y1 != y4)
		  || (a2 == 0 && y3 == y4 && y3 != y2 && y3 != y1) || (a1 != a2 && x1 == x2 && x1 <= x3 && x1 <= x4) || (a1 != a2 && x1 == x2 && x1 >= x3 && x1 >= x4) 
		  || (a1 != a2 && x1 == x2 && x1 >= x3 && x1 <= x4) || (a1 != a2 && x1 == x2 && x1 <= x3 && x1 >= x4) || (a1 != a2 && x3 == x4 && x3 <= x1 && x3 <= x2)
		 || (a1 != a2 && x3 == x4 && x3 >= x1 && x3 >= x2) || (a1 != a2 && x3 == x4 && x3 >= x1 && x3 <= x2) || (a1 != a2 && x3 == x4 && x3 <= x1 && x3 >= x2)
		 || (a1 != a2 && b1 != b2 && (x1 < x3 && x2 < x4 && y1 > y3 && y1 > y4)) || (a1 != a2 && b1 != b2 && x1 > x3 && x2 > x4 && y1 < y3 && y1 < y4)){
        	cout << "no" << endl;
		}
        else if((a1 != a2 && b1 != b2) || (a1 > a2 && b1 >= b2) || (a1 < a2 && b1 <= b2) || (a1 > a2 && b1 <= b2) || (a1 < a2 && b1 >= b2)){
        	
        	cout << "yes" << "   ";
        	
			if (x1 == x3 && y1 == y3){
        		cout << x1 << "   " << y1 << endl;
		    }
		    else if (x2 == x4 && y2 == y4){
        		cout << x2 << "   " << y2 << endl;
		    }
		    else if (x1 == x4 && y1 == y4){
        		cout << x1 << "   " << y1 << endl;
		    }
		    else if (x3 == x2 && y3 == y2){
        		cout << x2 << "   " << y2 << endl;
		    }
            else{
                x=(b1-b2)/-(a1-a2);
                y=x*a2+b2;
                cout << x << "  " << y << endl;
            }
        }
        else{
        	cout << "no" << endl;
		}

    }
    //cout << a1 << "   " << b1 << "   " << a2 << "   " << b2 << endl;
    //cout << x << "  " << y;
        
        

	return 0;
}
