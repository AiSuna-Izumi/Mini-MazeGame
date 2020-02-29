#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
void up();
void down();
void right();
void left();
void refresh();
void start();
     
struct maze{
	string up;
	string down;
	string left;
	char maze[23][12];
    struct maze *next;
};
maze *head;
int main(){
//	start();
	refresh();
	
}
     
void start()
{
	    system("color 34");
	    maze *newptr, *crptr, *prptr;
	newptr = new maze; 

    int a;
    int choice;
    char again;
    char x[20];
    cout<<endl;
    cout<<"            *                                           *    "<<endl;   
    cout<<"          **                                            *   "<<endl;
    cout<<"   *** Welcome to the Clinic System Management ****"<<endl;
    cout<<"          **                                             **  "<<endl;
    cout<<"            *                                           *   "<<endl;
    cout<<endl;                                                   
    
    
    Beep(2020,1100);                                                             // causes the computer to beep
    char l=219;                                                                  //for loading bar
    cout<<"Please wait while system is analyzing the data\n";
    for ( int i=0; i<10 ; i++)
    {
        Beep(2000,500);
        cout<<l; 
         }
    	cout << "Press Enter to Continue\n";
	cin.ignore();
}
void refresh(){
	system ("cls");
	system("color 10");
	maze *newptr, *crptr, *prptr;
	crptr = head;
	ifstream showMaze; //declare in file 
	showMaze.open("mazeMap.txt", ios::app);//open customer.txt file
	string line;
	int choice;
	
		if (showMaze.is_open()){
			while(!showMaze.eof())
			{

			for(int i=0; i<27;i++){
				for(int j=0;j<12;j++){
			getline(showMaze,newptr->maze[i][j]);
			cout<<line<<endl;	
				}
			}
			
    	 		
	}
			
}
}
	
