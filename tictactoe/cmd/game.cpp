#include <iostream>
#include <string>

using namespace std;

int input(int (*rep)[3][3], int i, int a, int input){
	(*rep)[i][a]=input;
	return 0;
}

//0 for no winner, 1 for cpu, 2 for user. requires later testing for ties
int  validate(int (*rep)[3][3]){
	int output = 0;
	if((*rep)[0][0]==(*rep)[0][1]==(*rep)[0][2]==1){output = 1;}
	if((*rep)[0][0]==(*rep)[0][1]==(*rep)[0][2]==2){output = 2;}
	if((*rep)[1][0]==(*rep)[1][1]==(*rep)[1][2]==1){output = 1;}
	if((*rep)[1][0]==(*rep)[1][1]==(*rep)[1][2]==2){output = 2;}
	if((*rep)[2][0]==(*rep)[2][1]==(*rep)[2][2]==1){output = 1;}
	if((*rep)[2][0]==(*rep)[2][1]==(*rep)[2][2]==2){output = 2;}

	if((*rep)[0][0]==(*rep)[1][0]==(*rep)[2][0]==1){output = 1;}
	if((*rep)[0][0]==(*rep)[1][0]==(*rep)[2][0]==2){output = 2;}
	if((*rep)[0][1]==(*rep)[1][1]==(*rep)[2][1]==1){output = 1;}
	if((*rep)[0][1]==(*rep)[1][1]==(*rep)[2][1]==2){output = 2;}
	if((*rep)[0][2]==(*rep)[1][2]==(*rep)[2][2]==1){output = 1;}
	if((*rep)[0][2]==(*rep)[1][2]==(*rep)[2][2]==2){output = 2;}

	if((*rep)[0][0]==(*rep)[1][1]==(*rep)[2][2]==1){output=1;}
	if((*rep)[0][0]==(*rep)[1][1]==(*rep)[2][2]==2){output=2;}
	if((*rep)[0][2]==(*rep)[1][1]==(*rep)[2][0]==1){output=1;}
	if((*rep)[0][2]==(*rep)[1][1]==(*rep)[2][0]==2){output=2;}

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
		cout << "enter coords" << endl;
		int i;
		cin >> i;
		int a;
		cin >> a;
		input(&board, i, a, 2),
		printBoard(&board);	
	}
	//int (*rep)[3][3] = &board;
	return 0;

}
