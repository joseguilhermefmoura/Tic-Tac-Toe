#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
const char ENTER = 13;
const char ESC = 27;

// ~ ******* << TEXT-FUNCTION VARIABLES >> ******* ~ //
const char TAB[6] = "\t\t\t";          // Tabulation
const char NL[2] = "\n"; 	             // New line 
const char TOP_BORDER = 205;
const char TOP_LEFT_EDGE = 201;
const char TOP_RIGHT_EDGE = 187;
const char LEFT_AND_RIGHT_BORDER = 186;
const char BOTTOM_LEFT_EDGE = 200;
const char BOTTOM_RIGHT_EDGE = 188;
const char BOTTOM_BORDER = 205;
// ~ ********************* ~~ ********************* ~ //

void changeColor(int color){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
};

// ~ ******* << GAMING-FUNCTIONING VARIABLES >> ******* ~ //
bool endOfGame;
bool continueToPlay;
int closeGameLoop;
int atualizeTimes;
int player1Score;
int player2Score;
int currentPlayer;
int lastPlayer;
int changePlayer;
int winner;
int selectedPosition;
int position1;
int position2;
int position3;
int position4;
int position5;
int position6;
int position7;
int position8;
int position9;
char position1char;
char position2char;
char position3char;
char position4char;
char position5char;
char position6char;
char position7char;
char position8char;
char position9char;
int position1W;
int position2W;
int position3W;
int position4W;
int position5W;
int position6W;
int position7W;
int position8W;
int position9W;
// ~ *********************** ~~ *********************** ~ //

void setup(){ // Starting game function that sets up the game for being played
	endOfGame = false;
	winner = 0;
	closeGameLoop = 1;
	atualizeTimes = 0;
	player1Score = 0;
	player2Score = 0;
	currentPlayer = 1;
	changePlayer = 1;
	lastPlayer = 0;
	position1 = 0;
	position2 = 0;
	position3 = 0;
	position4 = 0;
	position5 = 0;
	position6 = 0;
	position7 = 0;
	position8 = 0;
	position9 = 0;
	position1char = ' ';
	position2char = ' ';
	position3char = ' ';
	position4char = ' ';
	position5char = ' ';
	position6char = ' ';
	position7char = ' ';
	position8char = ' ';
	position9char = ' ';
	position1W = 0;
	position2W = 0;
	position3W = 0;
	position4W = 0;
	position5W = 0;
	position6W = 0;
	position7W = 0;
	position8W = 0;
	position9W = 0;
};

void welcome_messages(){ // Initialize some messages explaining to the user how to play the game
	system("color 0F");
	changeColor(14);
	// First message **********
	cout << NL << NL;
	cout << TAB << "Welcome to Tic-tac Toe! -- Developed by _github>@joseguilhermefmoura" << endl;
	cout << NL << NL << TAB;
	Sleep(3000);
	// Second message **********
	changeColor(15);
	cout << "This game follows the Tic-tac Toe field pattern shown below:" << endl;
	cout << NL << NL;
	for(int i = 0; i <= 16; i++){ // Loop for printing the top border
			if(i == 0){
				changeColor(15);
				cout << TAB;
				changeColor(185);
				cout << TOP_LEFT_EDGE;
			} else if (i == 16){
				cout << TOP_RIGHT_EDGE << endl;
			} else {
				cout << TOP_BORDER;
			}
	}
	{ // Printing the left and right border + warning about the usage of these numbers
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "               " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "   7 | 8 | 9   " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << " ------------- " << LEFT_AND_RIGHT_BORDER;
		changeColor(15);
		cout << "\t";
		changeColor(12);
		cout << "*! You must use these numbers" << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "   4 | 5 | 6   " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << " ------------- " << LEFT_AND_RIGHT_BORDER;
		changeColor(15);
		cout << "\t";
		changeColor(12);
		cout << "in order to play the game!*" << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "   1 | 2 | 3   " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "               " << LEFT_AND_RIGHT_BORDER << endl;
	}
	for(int i = 0; i <= 16; i++){ // Loop for printing the bottom border
		if(i == 0){
			changeColor(15);
			cout << TAB;
			changeColor(185);
			cout << BOTTOM_LEFT_EDGE;
		} else if (i == 16){
			cout << BOTTOM_RIGHT_EDGE << endl;
		} else {
			cout << BOTTOM_BORDER;
		}
	}
	changeColor(15);
	cout << NL << NL << TAB;
	Sleep(5500);

	// Third message
	changeColor(10);
	cout << "Alright, press the ENTER key to finally start the game! ";
	while ((getch()) != ENTER);
};

void draw(){ // Loop responsible for the drawing of the game screen every time it's needed while gaming
	changeColor(15);
	system("cls");
	cout << NL << NL << NL << NL << NL << NL << NL << NL;
		
	for(int i = 0; i <= 16; i++){ // Loop for printing the top border
			if(i == 0){
				cout << TAB;
				changeColor(185);
				cout << TOP_LEFT_EDGE;
			} else if (i == 16){
				cout << TOP_RIGHT_EDGE << endl;
			} else {
				cout << TOP_BORDER;
			}
	}
	{ // Printing the left and right border + warning about the usage of these numbers
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "               " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "   " << position7char << " | " << position8char << " | " << position9char << "   " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << " ------------- " << LEFT_AND_RIGHT_BORDER;
		changeColor(14);
		cout << "\t" << "Player 1 ->  X" << endl;
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "   " << position4char << " | " << position5char << " | " << position6char << "   " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << " ------------- " << LEFT_AND_RIGHT_BORDER;
		changeColor(14);
		cout << "\t" << "Player 2 ->  O" << endl;
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "   " << position1char << " | " << position2char << " | " << position3char << "   " << LEFT_AND_RIGHT_BORDER << endl;
		changeColor(15);
		cout << TAB;
		changeColor(185);
		cout << LEFT_AND_RIGHT_BORDER << "               " << LEFT_AND_RIGHT_BORDER << endl;
	}
	for(int i = 0; i <= 16; i++){ // Loop for printing the bottom border
		if(i == 0){
			changeColor(15);
			cout << TAB;
			changeColor(185);
			cout << BOTTOM_LEFT_EDGE;
		} else if (i == 16){
			cout << BOTTOM_RIGHT_EDGE << endl;
		} else {
			cout << BOTTOM_BORDER;
		}
	}
	
	changeColor(15);
	cout << NL << NL << TAB;
};

void score(){
	system("cls");
	cout << NL << NL << NL << NL << NL << NL << NL << NL;

	for(int i = 0; i <= 16; i++){
			if(i == 0){
				changeColor(15);
				cout << TAB;
				changeColor(185);
				cout << TOP_LEFT_EDGE;
			} else if (i == 16){
				cout << TOP_RIGHT_EDGE << endl;
			} else {
				cout << TOP_BORDER;
			}
	}
	changeColor(15);
	cout << TAB;
	changeColor(185);
	cout << LEFT_AND_RIGHT_BORDER << "               " << LEFT_AND_RIGHT_BORDER << endl;
	
	// First line of Tic-Tac Toe with colors.
	changeColor(15);
	cout << TAB;
	changeColor(185);
	cout << LEFT_AND_RIGHT_BORDER << "   ";
	if(position7W != 0){
		changeColor(178);
		cout << position7char;
		changeColor(185);
	} else{
		cout << position7char;
	}
	cout << " | ";
	if(position8W != 0){
		changeColor(178);
		cout << position8char;
		changeColor(185);
	} else{
		cout << position8char;
	}
	cout << " | ";
	if(position9W != 0){
		changeColor(178);
		cout << position9char;
		changeColor(185);
	} else{
		cout << position9char;
	}
	cout << "   " << LEFT_AND_RIGHT_BORDER << endl;
	changeColor(15);
	cout << TAB;
	changeColor(185);
	cout << LEFT_AND_RIGHT_BORDER << " ------------- " << LEFT_AND_RIGHT_BORDER;
	changeColor(14);
	cout << "\t" << "Player 1 ->  X" << endl;
	
	// Second line of Tic-Tac Toe with colors.
	changeColor(15);
	cout << TAB;
	changeColor(185);
	cout << LEFT_AND_RIGHT_BORDER << "   ";
	if(position4W != 0){
		changeColor(178);
		cout << position4char;
		changeColor(185);
	} else{
		cout << position4char;
	}
	cout << " | ";
	if(position5W != 0){
		changeColor(178);
		cout << position5char;
		changeColor(185);
	} else{
		cout << position5char;
	}
	cout << " | ";
	if(position6W != 0){
		changeColor(178);
		cout << position6char;
		changeColor(185);
	} else{
		cout << position6char;
	}
	cout << "   " << LEFT_AND_RIGHT_BORDER << endl;
	changeColor(15);
	cout << TAB;
	changeColor(185);
	cout << LEFT_AND_RIGHT_BORDER << " ------------- " << LEFT_AND_RIGHT_BORDER;
	changeColor(14);
	cout << "\t" << "Player 2 ->  O" << endl;
	
	// Second line of Tic-Tac Toe with colors.
	changeColor(15);
	cout << TAB;
	changeColor(185);
	cout << LEFT_AND_RIGHT_BORDER << "   ";
	if(position1W == 1){
		changeColor(178);
		cout << position1char;
		changeColor(185);
	} else {
		cout << position1char;
	}	
	cout << " | ";
	if(position2W != 0){
		changeColor(178);
		cout << position2char;
		changeColor(185);
	} else{
		cout << position2char;
	}
	cout << " | ";
	if(position3W != 0){
		changeColor(178);
		cout << position3char;
		changeColor(185);
	} else{
		cout << position3char;
	}
	cout << "   " << LEFT_AND_RIGHT_BORDER << endl;
	changeColor(15);
	cout << TAB;
	changeColor(185);
	cout << LEFT_AND_RIGHT_BORDER << "               " << LEFT_AND_RIGHT_BORDER << endl;
	
	for(int i = 0; i <= 16; i++){ // Loop for printing the bottom border
		if(i == 0){
			changeColor(15);
			cout << TAB;
			changeColor(185);
			cout << BOTTOM_LEFT_EDGE;
		} else if (i == 16){
			cout << BOTTOM_RIGHT_EDGE << endl;
		} else {
			cout << BOTTOM_BORDER;
		}
	}
	
	changeColor(15);
	cout << NL << NL << TAB;
	cout << NL << NL;
			
	if(winner == 1){
		changeColor(14);
		cout << "\a";
		cout << TAB << "Congratulations, Player 1, you won the game!!" << endl;
	} else if (winner == 2){
		changeColor(14);
		cout << "\a";
		cout << TAB << "Congratulations, Player 2, you won the game!!" << endl;
	} else {
		changeColor(12);
		cout << "\a" << "\a" << "\a";
		cout << TAB << "Ops! You draw the game!" << endl;
	}
	
	changeColor(15);
	cout << NL << NL << NL;
	changeColor(14);
	cout << TAB << "Press ENTER to play again or ESC to close the game!" << endl;
	
	while(closeGameLoop){
		switch(getch()){
			case ENTER:
				continueToPlay = true;
				closeGameLoop = 0;
				break;
			case ESC:
				continueToPlay = false;
				closeGameLoop = 0;
				break;
			default:
				closeGameLoop = 1;
				break;
		}
	}
}

void atualize(){
	if(changePlayer == 1){
		if(lastPlayer == 1)
			currentPlayer = 2;
		else 
			currentPlayer = 1;
		
		lastPlayer = currentPlayer;	
	}
	
	changeColor(14);
	cout << NL << NL;
	if(currentPlayer == 1)
		cout << TAB << " Please, player 1, insert the number position you want to pick: ";
	else
		cout << TAB << " Please, player 2, insert the number position you want to pick: ";
	
	switch(getch()){
		case '1':
			if(position1 == 0){
				atualizeTimes++;
				position1 = currentPlayer;
				
				if(currentPlayer == 1)
					position1char = 'X';
				else 
					position1char = 'O';
				
				if(position1 == currentPlayer && position4 == currentPlayer && position7 == currentPlayer){
					winner = currentPlayer;
					position1W++;
					position4W++;
					position7W++;
				} else if(position1 == currentPlayer && position2 == currentPlayer && position3 == currentPlayer){
					winner = currentPlayer;
					position1W++;
					position2W++;
					position3W++;
				} else if(position1 == currentPlayer && position5 == currentPlayer && position9 == currentPlayer){
					winner = currentPlayer;
					position1W++;
					position5W++;
					position9W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		case '2':
			if(position2 == 0){
				atualizeTimes++;
				position2 = currentPlayer;
				
				if(currentPlayer == 1)
					position2char = 'X';
				else
					position2char = 'O';
				
				if(position2 == currentPlayer && position1 == currentPlayer && position3 == currentPlayer){
					winner = currentPlayer;
					position2W++;
					position1W++;
					position3W++;
				} else if(position2 == currentPlayer && position5 == currentPlayer && position8 == currentPlayer){
					winner = currentPlayer;
					position2W++;
					position5W++;
					position8W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		case '3':
			if(position3 == 0){
				atualizeTimes++;
				position3 = currentPlayer;
				
				if(currentPlayer == 1)
					position3char = 'X';
				else 
					position3char = 'O';
				
				if(position3 == currentPlayer && position6 == currentPlayer && position9 == currentPlayer){
					winner = currentPlayer;
					position3W++;
					position6W++;
					position9W++;
				} else if(position3 == currentPlayer && position2 == currentPlayer && position1 == currentPlayer){
					winner = currentPlayer;
					position3W++;
					position2W++;
					position1W++;
				} else if(position3 == currentPlayer && position5 == currentPlayer && position7 == currentPlayer){
					winner = currentPlayer;
					position3W++;
					position5W++;
					position7W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		case '4':
			if(position4 == 0){
				atualizeTimes++;
				position4 = currentPlayer;
				
				if(currentPlayer == 1)
					position4char = 'X';
				else 
					position4char = 'O';
				
				if(position4 == currentPlayer && position5 == currentPlayer && position6 == currentPlayer){
					winner = currentPlayer;
					position4W++;
					position5W++;
					position6W++;
				} else if(position4 == currentPlayer && position1 == currentPlayer && position7 == currentPlayer){
					winner = currentPlayer;
					position4W++;
					position1W++;
					position7W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		case '5':
			if(position5 == 0){
				atualizeTimes++;
				position5 = currentPlayer;
				
				if(currentPlayer == 1)
					position5char = 'X';
				else 
					position5char = 'O';
				
				if(position5 == currentPlayer && position1 == currentPlayer && position9 == currentPlayer){
					winner = currentPlayer;
					position5W++;
					position1W++;
					position9W++;
				} else if(position5 == currentPlayer && position3 == currentPlayer && position7 == currentPlayer){
					winner = currentPlayer;
					position5W++;
					position3W++;
					position7W++;
				} else if(position5 == currentPlayer && position4 == currentPlayer && position6 == currentPlayer){
					winner = currentPlayer;
					position5W++;
					position4W++;
					position6W++;
				} else if(position5 == currentPlayer && position2 == currentPlayer && position8 == currentPlayer){
					winner = currentPlayer;
					position5W++;
					position2W++;
					position8W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		case '6':
			if(position6 == 0){
				atualizeTimes++;
				position6 = currentPlayer;
				
				if(currentPlayer == 1)
					position6char = 'X';
				else 
					position6char = 'O';
				
				if(position6 == currentPlayer && position5 == currentPlayer && position4 == currentPlayer){
					winner = currentPlayer;
					position6W++;
					position5W++;
					position4W++;
				} else if(position6 == currentPlayer && position3 == currentPlayer && position9 == currentPlayer){
					winner = currentPlayer;
					position6W++;
					position3W++;
					position9W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;	
		case '7':
			if(position7 == 0){
				atualizeTimes++;
				position7 = currentPlayer;
				
				if(currentPlayer == 1)
					position7char = 'X';
				else 
					position7char = 'O';
				
				if(position7 == currentPlayer && position5 == currentPlayer && position3 == currentPlayer){
					winner = currentPlayer;
					position7W++;
					position5W++;
					position3W++;
				} else if(position7 == currentPlayer && position4 == currentPlayer && position1 == currentPlayer){
					winner = currentPlayer;
					position7W++;
					position4W++;
					position1W++;
				} else if(position7 == currentPlayer && position8 == currentPlayer && position9 == currentPlayer){
					winner = currentPlayer;
					position7W++;
					position8W++;
					position9W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		case '8':
			if(position8 == 0){
				atualizeTimes++;
				position8 = currentPlayer;
				
				if(currentPlayer == 1)
					position8char = 'X';
				else 
					position8char = 'O';
				
				if(position8 == currentPlayer && position5 == currentPlayer && position2 == currentPlayer){
					winner = currentPlayer;
					position8W++;
					position5W++;
					position2W++;
				} else if(position8 == currentPlayer && position7 == currentPlayer && position9 == currentPlayer){
					winner = currentPlayer;
					position8W++;
					position7W++;
					position9W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		case '9':
			if(position9 == 0){
				atualizeTimes++;
				position9 = currentPlayer;
				
				if(currentPlayer == 1)
					position9char = 'X';
				else 
					position9char = 'O';
				
				if(position9 == currentPlayer && position8 == currentPlayer && position7 == currentPlayer){
					winner = currentPlayer;
					position9W++;
					position8W++;
					position7W++;
				} else if(position9 == currentPlayer && position5 == currentPlayer && position1 == currentPlayer){
					winner = currentPlayer;
					position9W++;
					position5W++;
					position1W++;
				} else if(position9 == currentPlayer && position6 == currentPlayer && position3 == currentPlayer){
					winner = currentPlayer;
					position9W++;
					position6W++;
					position3W++;
				}
				changePlayer = 1;
			} else {
				changePlayer = 0;
			}
			break;
		default:
       		changePlayer = 0;
			break;
	}
}

int main(){
	system("TITLE Tic-Tac Toe! by _github:joseguilhermefmoura");
	
	welcome_messages();
	setup();
	while(!endOfGame){
		draw();
		atualize();
		if(atualizeTimes == 9 || winner != 0){
			endOfGame = true;
			score();
			if(continueToPlay){
				endOfGame = false;
				setup();
			} else{
				system("cls");
				cout << NL << NL << NL << NL << NL << NL << NL << NL << NL;
				changeColor(14);
				cout << TAB << TAB << "Thank you for playing! ";
				Sleep(2000);
				exit(0);		
			}
		}
	}
	
	return 0;
}
