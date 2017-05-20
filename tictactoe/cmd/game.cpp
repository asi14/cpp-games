#include <iostream>
#include <string>

using namespace std;
int printBoard(int (*rep)[3][3]){
	for(int i = 0; i < 3; i++){
		for(int a = 0; a < 3; a++){
			cout << (*rep)[i][a] << " ";	
		}
		cout << endl;
	}
}

int main(){
	int board[3][3] = {
		{0,0,0},
		{0,0,0},
		{0,0,0}	
	};
	printBoard(&board);
	//int (*rep)[3][3] = &board;
	return 0;

}
