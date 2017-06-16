#include <vector>
#include <iostream>
#include <string>

using namespace std;


int printBoard(int (rep)[3][3]){
	for(int i = 0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			cout << (rep)[i][a] << " ";	
		}
		cout << endl;
	}
	return 0;
}



int input(int (rep)[3][3], int i, int a, int input){
	(rep)[i][a]=input;
	return 0;
}

//dtermines if game board is EMPTY (opener minimax function)
bool isEmpty(int rep[3][3]){
	bool test = true;
	for(int i = 0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			if(rep[i][a]!=0){test = false;}	
		}	
	}
	return test;	
}


//determines if board is FULL (for validaton purposes)
bool isFull(int (rep)[3][3]){
	bool test = true;
	for(int i = 0; i < 3; i++){
		for(int a=0; a < 3; a++){
			if((rep)[i][a] == 0){test = false;}	
		}	
	}	
	return test;
}



//0 for no winner, 1 for cpu, 2 for user. requires later testing for ties
//needs bugtesting
int validate(int (rep)[3][3]){
	int output = 0;
	if((rep)[0][0]== 1 && (rep)[0][1]== 1 && (rep)[0][2]==1){cout<<"a";output = 1;}
	if((rep)[0][0]== 2 && (rep)[0][1]== 2 && (rep)[0][2]==2){cout<<"b";output = 2;}
	if((rep)[1][0]== 1 && (rep)[1][1]== 1 && (rep)[1][2]==1){cout<<"c";output = 1;}
	if((rep)[1][0]== 2 && (rep)[1][1]== 2 && (rep)[1][2]==2){cout<<"d";output = 2;}
	if((rep)[2][0]== 1 && (rep)[2][1]== 1 && (rep)[2][2]==1){cout<<"e";output = 1;}
	if((rep)[2][0]== 2 && (rep)[2][1]== 2 && (rep)[2][2]==2){cout<<"f";output = 2;}

	if((rep)[0][0]== 1 && (rep)[1][0]== 1 && (rep)[2][0]==1){cout<<"g";output = 1;}
	if((rep)[0][0]== 2 && (rep)[1][0]== 2 && (rep)[2][0]==2){cout<<"h";output = 2;}
	if((rep)[0][1]== 1 && (rep)[1][1]== 1 && (rep)[2][1]==1){cout<<"i";output = 1;}
	if((rep)[0][1]== 2 && (rep)[1][1]== 2 && (rep)[2][1]==2){cout<<"j";output = 2;}
	if((rep)[0][2]== 1 && (rep)[1][2]== 1 && (rep)[2][2]==1){cout<<"k";output = 1;}
	if((rep)[0][2]== 2 && (rep)[1][2]== 2 && (rep)[2][2]==2){cout<<"l";output = 2;}

	if((rep)[0][0]== 1 && (rep)[1][1]== 1 && (rep)[2][2]==1){cout<<"m";output=1;}
	if((rep)[0][0]== 2 && (rep)[1][1]== 2 && (rep)[2][2]==2){cout<<"n";output=2;}
	if((rep)[0][2]== 1 && (rep)[1][1]== 1 && (rep)[2][0]==1){cout<<"o";output=1;}
	if((rep)[0][2]== 2 && (rep)[1][1]== 2 && (rep)[2][0]==2){cout<<"p";output=2;}

	if (isFull(rep) == true and output == 0){output = 3;}

	return output;
}



//recursive function that splits past Stage 1
//end goal of function: reduce a specific scenario of board to a stage number outlining how many moves required until victory
//or -1, where loss is inevitable
int bestWin(int (rep)[3][3], int stage){
	cout << "i got here too" << endl;
	if(validate(rep)==2){return -1;}
	else if(validate(rep) == 1 or validate(rep) == 3){return stage;}
	else{
		//creates array to hold subsequent stage values
		//length is determined by getting amount of remaining free spaces (0)
		int arrLength = 0;
		for(int i = 0; i < 3; i++){
			for(int a = 0; a <3; a++){
				if((rep)[i][a]==0){arrLength++;}
			}	
		}
		int stages [arrLength];
		int stageCount=0;

		//ieterates through the function looking for 0s
		//from there creates a new array where cpu/player 'input' inserted into detected free space
		//runs bestWin again for that function, stage number stored into stages
		for(int i = 0; i < 3; i++){
			for(int a = 0; a < 3; a++){
				cout << "aaaa" << endl;
				if((rep)[i][a]==0){
					int duplicate[3][3];
					//copies the values of rep over to duplicate, value by value
					for(int x = 0; x < 3; x++){
						for(int y = 0; y < 3; y++){
							duplicate[x][y]=rep[x][y];	
						}	
					}
					/*
					for(int c = 0; i < 9; i++){
						std::copy((rep)+c,duplicate);
					}
					*/
					if(stage%2==0){duplicate[i][a]=2;} //this may have to change
					else{duplicate[i][a]=1;}
					stages[stageCount] = bestWin(duplicate,stage++);
					stageCount++;	
				}	
			}	
		}
		//determines the smallest stage number (i.e. least possible number of steps to victory)
		//PROBLEM 1: if stages is printed, its length grows
		int output = sizeof(stages);
		for(int i = 0; i < sizeof(stages); i++){
			if(stages[i] < output and stages[i] > 0){output = stages[i];}	
		}
		return output;	
	}
}



//master version of bestWin: exactly it except the array is preserved
//reason: the output for this function will be used for the actual computer move
int cpuCalc(int (rep)[3][3]){
	//checks if game has just started
	if(isEmpty(rep)){
		input(rep,1,1,1);
		return 0;
	}
	else
	{

	//computes array of possible scenarios to hold stage values in
	int arrLen = 0;
	for(int i =0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			if((rep)[i][a]==0){arrLen++;}	
		}	
	}
	int stages [arrLen];
	int stageCount = 0;


	//ietrates through game board, searching for empty spaces
	//plugs in computer value (this function determines actual computer move) into hypothetical array
	//and runs bestWin on it
	//output value goes into array of possible stages
	for(int i =0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			if((rep)[i][a]==0){
				//generates temp array which holds possible game scenario
				int dupli[3][3];
				for(int x = 0; x < 3; x++){
					for(int y = 0; y < 3; y++){
						dupli[x][y]=rep[x][y];	
					}	
				}
				dupli[i][a]=1;
				stages[stageCount] = bestWin(dupli,2);	
				stageCount++;
			}	
		}	
	}
	//determines the smallest stage value that's not -1 and records its position
	//a second for loop will determine the position number and input value into board
	int eval = arrLen, movePlace=-5;
	for(int i = 0; i < arrLen; i++){
		if(stages[i] < eval and stages[i] > 0){eval=stages[i]; movePlace = i;}
	}


	//this function finds the proper 'free space' using the previously gotten value
	//puts in the computer value and plugs it into computer board
	int testMove = 0;
	for(int i = 0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			if(testMove==movePlace){input((rep),i,a,1);}	
			testMove++;
		}	
	}
	return 0;
	}
}
int main(){
	int board[3][3] = {
		{0,0,0},
		{0,0,0},
		{0,0,0}	
	};
	bool test = true;
	while(test){
		cpuCalc(board);
		cout << "enter coords" << endl;
		int i;
		cin >> i;
		int a;
		cin >> a;
		input(board, i, a, 2);
		if(validate(board) == 0){
			cout << "The game continues, here is the board" << endl;
			printBoard(board);	
		}
		else if(validate(board)==1){
			cout << "It's a win for the computer" << endl;
			test = false;	
			printBoard(board);
		}
		else if(validate(board) == 2){
			cout << "It's a win for the player" << endl;	
			test = false;
		}
		else if(validate(board) == 3){
			cout << "it's a tie" << endl;
			printBoard(board);
			test=false;
		}
	}
	//int (rep)[3][3] = &board;
	return 0;


}

