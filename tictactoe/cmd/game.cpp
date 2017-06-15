#include <vector>
#include <iostream>
#include <string>

using namespace std;

//interprets final array from bestWin and determines the best case...?
int cpuCalc(int (*rep)[3][3]){
//need some advice	
/*
algorithim structure:

1) create array of possible moves, which ones lead to failure, and how many moves out of it
2) create recursive function that goes through each of the scenarios (they will all branch out)
3) determine from there a situation that will lead to a win scenario (or a tie scenario) in the least number of moves
*/
	
}

//recursive function that does the hair splitting
int bestWin(int (*rep)[3][3], int stage){
	if(validate(rep)==2){return -1;}
	else if(validate(rep) == 1 or validate(rep) == 3){return stage;}
	else{
		int arrLength = 0; //holds arrlength for eventual stage numbers
		for(int i = 0; i < 3; i++){
			for(int a = 0; a <3; a++){
				if((*rep)[i][a]==0){arrLength++;}
			}	
		}
		int stages [arrLength];
		int stageCount=0;
		for(int i = 0; i < 3; i++){
			for(int a = 0; a < 3; a++){
				if((*rep)[i][a]=0){
					int duplicate[3][3];
					for(int c = 0; i < 9; i++){
						std::copy((*rep)+c,duplicate);
						if(stage%2==0){copy[i][a]=1;} //this may have to change
						else{copy[i][a]=2;}
					}
					stages[stageCount] = bestWin(duplicate, stage++);
					stageCount++;	
				}	
			}	
		}
		int output = stages.length();
		for(int i = 0; i < stages.length(); i++){
			if(stages[i] < output){output = stages[i];}	
		}
		return output;	
	}
}
int input(int (*rep)[3][3], int i, int a, int input){
	(*rep)[i][a]=input;
	return 0;
}

bool isFull(int (*rep)[3][3]){
	bool test = true;
	for(int i = 0; i < 3; i++){
		for(int a=0; a < 3; a++){
			if((*rep)[i][a] == 0){test = false;}	
		}	
	}	
	return test;
}

//0 for no winner, 1 for cpu, 2 for user. requires later testing for ties
//needs bugtesting
int validate(int (*rep)[3][3]){
	int output = 0;
	if((*rep)[0][0]== 1 && (*rep)[0][1]== 1 && (*rep)[0][2]==1){cout<<"a";output = 1;}
	if((*rep)[0][0]== 2 && (*rep)[0][1]== 2 && (*rep)[0][2]==2){cout<<"b";output = 2;}
	if((*rep)[1][0]== 1 && (*rep)[1][1]== 1 && (*rep)[1][2]==1){cout<<"c";output = 1;}
	if((*rep)[1][0]== 2 && (*rep)[1][1]== 2 && (*rep)[1][2]==2){cout<<"d";output = 2;}
	if((*rep)[2][0]== 1 && (*rep)[2][1]== 1 && (*rep)[2][2]==1){cout<<"e";output = 1;}
	if((*rep)[2][0]== 2 && (*rep)[2][1]== 2 && (*rep)[2][2]==2){cout<<"f";output = 2;}

	if((*rep)[0][0]== 1 && (*rep)[1][0]== 1 && (*rep)[2][0]==1){cout<<"g";output = 1;}
	if((*rep)[0][0]== 2 && (*rep)[1][0]== 2 && (*rep)[2][0]==2){cout<<"h";output = 2;}
	if((*rep)[0][1]== 1 && (*rep)[1][1]== 1 && (*rep)[2][1]==1){cout<<"i";output = 1;}
	if((*rep)[0][1]== 2 && (*rep)[1][1]== 2 && (*rep)[2][1]==2){cout<<"j";output = 2;}
	if((*rep)[0][2]== 1 && (*rep)[1][2]== 1 && (*rep)[2][2]==1){cout<<"k";output = 1;}
	if((*rep)[0][2]== 2 && (*rep)[1][2]== 2 && (*rep)[2][2]==2){cout<<"l";output = 2;}

	if((*rep)[0][0]== 1 && (*rep)[1][1]== 1 && (*rep)[2][2]==1){cout<<"m";output=1;}
	if((*rep)[0][0]== 2 && (*rep)[1][1]== 2 && (*rep)[2][2]==2){cout<<"n";output=2;}
	if((*rep)[0][2]== 1 && (*rep)[1][1]== 1 && (*rep)[2][0]==1){cout<<"o";output=1;}
	if((*rep)[0][2]== 2 && (*rep)[1][1]== 2 && (*rep)[2][0]==2){cout<<"p";output=2;}

	if (isFull(rep) == true and output == 0){output = 3;}

	return output;
}

int printBoard(int (*rep)[3][3]){
	for(int i = 0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			cout << (*rep)[i][a] << " ";	
		}
		cout << endl;
	}
	return 0;
}

int main(){
	int board[3][3] = {
		{1,2,0},
		{2,1,0},
		{1,2,0}	
	};
	bool test = true;
	while(test){
		cpuCalc(&board);
		cout << "enter coords" << endl;
		int i;
		cin >> i;
		int a;
		cin >> a;
		input(&board, i, a, 2);
		if(validate(&board) == 0){
			cout << "The game continues, here is the board" << endl;
			printBoard(&board);	
		}
		else if(validate(&board)==1){
			cout << "It's a win for the computer" << endl;
			test = false;	
			printBoard(&board);
		}
		else if(validate(&board) == 2){
			cout << "It's a win for the player" << endl;	
			test = false;
		}
		else if(validate(&board) == 3){
			cout << "it's a tie" << endl;
			printBoard(&board);
			test=false;
		}
	}
	//int (*rep)[3][3] = &board;
	return 0;


}
