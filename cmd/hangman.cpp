#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int gen(){
	srand(time(NULL));
	int select = rand()%10;
	return select;
}

int process(){
	std::cout << "hello world" << endl;
	return 0;	
}
int main(){
	string arr[] = {"hello","world","bye","michele","ubuntu","vim","master","race","trains","like"};
	std::string rando = arr[gen()];
	std::cout << rando << endl;
	process();
	return 0;
}
