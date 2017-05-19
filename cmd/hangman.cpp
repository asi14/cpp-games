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

string parseOutput(std::string random, std::string output, std::string test){
		for(int i = 0; i < random.length(); i++){
		if(random.at(i)==test.at(0) and output.at(i) == '*'){
			std::string temp = "";
			temp += output.substr(0,i);
			temp += test;
			temp += output.substr(i+1,random.length());
			output = temp;	
		}	
	}
	return output;	
}

int process(std::string random){
	string output = "";
	for(int i = 0; i < random.length(); i++){ //replace later with something like "*' * random.length() or something
		output+="*";	
	}
	int i = 10;
	bool testa = false;
	while(i > 0 and testa == false){
		std::string test;
		std::cout << "enter a character" << endl;
		std::getline(std::cin, test);
		if(test.length() > 1){std::cout << "invalid input" << endl;}
		else if(random.find(test)==std::string::npos){
			std::cout << "the char is not there\n" << "You have " << i-1 << " chances left\n" << "here is your current hint\n" << output << endl;
			i--;	
		}
		else{
			std::cout << test << "was found\n" << "here is your current hint" << endl;
			output = parseOutput(random, output, test);
			std::cout << output << endl;			
		}
		if(output == random){
			testa = true;
		}
	}
	if(testa == true){std::cout << "you win" << endl;}
	return 0;	
}

int main(){
	string arr[] = {"hello","world","bye","michele","ubuntu","vim","master","race","trains","like"};
	std::string rando = arr[gen()];
	process(rando);
	return 0;
}
