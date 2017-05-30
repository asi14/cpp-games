#include <iostream>
#include <string>

using namespace std;

int cpuCalc(int (*rep)[3][3]){
//need some advice	
}

int input(int (*rep)[3][3], int i, int a, int input){
	(*rep)[i][a]=input;
	return 0;
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
		{0,0,0},
		{0,0,0},
		{0,0,0}	
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
	}
	//int (*rep)[3][3] = &board;
	return 0;


}
