#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void down();
void right();
void left();
void refresh();
     

int main(){
	
	string myText;

	ifstream showMaze; //declare in file
	showMaze.open("mazeMap.txt", ios::app);//open customer.txt file
	int choice;
	
		if (showMaze.is_open()){
			while(!showMaze.eof())
			{
			getline(showMaze, myText);
			cout<<myText<<endl;
		
	}
}
}
