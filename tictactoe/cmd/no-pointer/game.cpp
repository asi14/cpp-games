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



//recursive function that does the hair splitting
int bestWin(int (rep)[3][3], int stage){
	cout << "i got here too" << endl;
	if(validate(rep)==2){return -1;}
	else if(validate(rep) == 1 or validate(rep) == 3){return stage;}
	else{
		cout << "branching type board" << endl;
		int arrLength = 0; //holds arrlength for eventual stage numbers
		for(int i = 0; i < 3; i++){
			for(int a = 0; a <3; a++){
				if((rep)[i][a]==0){arrLength++;}
			}	
		}
		cout << "length of" << stage << "stage array: " << arrLength << endl;
		int stages [arrLength];
		int stageCount=0;
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
					cout << "here is the array for stage " << stage << endl;
					printBoard(duplicate);
					stages[stageCount] = bestWin(duplicate,stage++);
					stageCount++;	
				}	
			}	
		}
		//calculates least smount of stages for a win
		int output = sizeof(stages);
		for(int i = 0; i < sizeof(stages); i++){
			if(stages[i] < output and stages[i] > 0){output = stages[i];}	
		}
		return output;	
	}
}



//"master" version of bestWin: holds stage 1 array and from there determines the best case to go for
int cpuCalc(int (rep)[3][3]){
//need some advice	
/*
algorithim structure:

1) create array of possible moves, which ones lead to failure, and how many moves out of it
2) create recursive function that goes through each of the scenarios (they will all branch out)
3) determine from there a situation that will lead to a win scenario (or a tie scenario) in the least number of moves
*/
	cout << "I got here" << endl;
	if(isEmpty(rep)){
		input(rep,1,1,1);
		return 0;
	}
	else
	{
	int arrLen = 0;
	for(int i =0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			if((rep)[i][a]==0){arrLen++;}	
		}	
	}
	cout << "arrLen" << arrLen << endl;
	int stages [arrLen];
	int stageCount = 0;
	for(int i =0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			if((rep)[i][a]==0){
				int dupli[3][3];
				for(int x = 0; x < 3; x++){
					for(int y = 0; y < 3; y++){
						dupli[x][y]=rep[x][y];	
					}	
				}
				/*
				for(int d =0; d < 9; d++){
					std::copy((rep)+d, dupli);//change here	
				}
				*/
				dupli[i][a]=1;
				cout << "here is a case" << endl;
				printBoard(dupli);
				stages[stageCount] = bestWin(dupli,2);	
				cout << "here is the stage number for the case: " << stages[stageCount] << endl;
				stageCount++;
			}	
		}	
	}
	cout << "The size of the array is now" << sizeof(stages) << "and here is the array\n[";
	for(int i = 0; i < sizeof(stages); i++){
		cout << stages[i] << ",";	
	}	
	cout << "]" << endl;
	int eval = arrLen, movePlace=-5;
	//determines the smallest stage 1 scenario, and its position
	for(int i = 0; i < arrLen; i++){
		if(stages[i] < eval and stages[i] > 0){eval=stages[i]; movePlace = i;}
	}
	int testMove = 0;
	//from there re-loops through the array, finds the proper zero and maps a 1 there
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
		printBoard(board);
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

