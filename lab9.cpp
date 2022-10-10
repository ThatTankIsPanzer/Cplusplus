#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int rollDice();
int crapsFunc ();
int main (){
	srand (time (0));
	float pt;
	double wp [100000];
	char play = 'y';
	float wins = 0;
	float bp = 0;
	float WP = 0;
	cout << "[IN] Enter the number of Craps games to be played: ";
    cin >> pt;
    
for (int j = 0; play == 'y' || play == 'Y'; ++j) {
        for (int i = 0; i < pt; ++i) {
                wins += crapsFunc();
        }
        
        wp[j] = wins / pt;
        cout << "Number of Craps games won by the player = " << wins << ";   " << "Win probability = " << wp[j] << endl;
        cout << "[IN] Continue to play? ( Y or y for yes): ";
        cin >> play;
        wins = 0; 
        if (j == 0) {
            bp = wp[0];
        }
        if (j != 0 && bp < wp[j]) {
            bp = wp[j];
        }
    }
	cout << "The best win probability " << bp << endl;
}
int crapsFunc () {
	int win = 0;
	enum Status {CONTINUE, WON, LOST};
	
	int myPoint;
	Status gameStatus;
	
	int sumOfDice = rollDice();
	
	switch (sumOfDice){
	    case 8: case 9:  case 10:  case 11:  
		gameStatus = WON;
		break;
        case 2:  case 3:  case 12:
		gameStatus = LOST;
		break;
		default:
			gameStatus = CONTINUE;
			myPoint = sumOfDice;
			break;
	}
	while(gameStatus == CONTINUE){
		
		sumOfDice = rollDice();
		
		if(sumOfDice == myPoint){
			gameStatus = WON;
		}
		else if (sumOfDice == 7){
			gameStatus = LOST;
		}
	}
	if (gameStatus == WON){
		win++;
	}
	return win;
}
int rollDice(){
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
		
	int sum = die1 + die2;
		
	return sum;
   
}

	


