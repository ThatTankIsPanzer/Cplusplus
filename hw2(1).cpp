#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
  double weight;
  double height;
  double BMI;
  double LowKilogram; 
  double HighKilogram;
  
  cout << "BMI calculater" << endl;
  
  cout << "input weight(kg)\n";
  cin >> weight;
  cout << "input height(m)\n";
  cin >> height;
  
  BMI = weight / (height * height);
  cout << "the BMI is " << BMI << endl;
  
  if (BMI < 18.5){
  	LowKilogram = 18.5 * height * height;
  }
  else if (BMI > 25){
  	HighKilogram = 25 * height * height;
  }
  
      if (BMI <= 10){
  	    cout << "you have Unreasonably small BMI\n";
  	    cout << "increase your weight to " << LowKilogram << " kg to bring your BMI value to 18.5" << endl;
  }
      else if (BMI > 10 && BMI <= 15){
  	    cout << "you are Highly severely underweight\n";
  	    cout << "increase your weight to " << LowKilogram << " kg to bring your BMI value to 18.5" << endl;
  }
      else if (BMI > 15 && BMI <= 16){
  	    cout << "you are Severely underweight\n";
  	    cout << "increase your weight to " << LowKilogram << " kg to bring your BMI value to 18.5" << endl;
  }
      else if (BMI > 16 && BMI <= 18.5){
  	    cout << "you are Underweight\n";
  	    cout << "increase your weight to " << LowKilogram << " kg to bring your BMI value to 18.5" << endl;
  }
      else if (BMI > 18.5 && BMI <= 25){
  	    cout << "you are Normal\n";	
  }
      else if (BMI >25 && BMI <= 40){
  	    cout << "you are Overweight\n";
  	    cout << "Decrease your weight to " << HighKilogram << " kg to bring your BMI value to 25" << endl;
  }
      else if (BMI > 40 && BMI <= 50){
  	    cout << "you are obese\n";
  	    cout << "Decrease your weight to " << HighKilogram << " kg to bring your BMI value to 25" << endl;
  	  }
      else if (BMI > 50 && BMI <= 60){
  	    cout << "you are Severely obese\n";
  	    cout << "Decrease your weight to " << HighKilogram << " kg to bring your BMI value to 25" << endl;
  }
      else if (BMI > 60 && BMI <= 70){
      	cout << "you are Highly severely obese\n"; 
  	    cout << "Decrease your weight to " << HighKilogram << " kg to bring your BMI value to 25" << endl;
  }
      else {
  	    cout << "you have Unreasonably large BMI\n";
        cout << "Decrease your weight to " << HighKilogram << " kg to bring your BMI value to 25" << endl;
  }
	return 0;
}
