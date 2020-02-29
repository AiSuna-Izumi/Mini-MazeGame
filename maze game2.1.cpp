#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

unsigned char player ={'O'}; //declare player on every function
int posX=1,posY=1;         //declare player place 
unsigned char move;       //declare move player

void playerMove();  //delcare player function

struct maze1{ //decalre struct
	bool active;
	int x;
	int y;
};

unsigned char maze[10][13]=
	 { {'-','#','#','#','#','#','#','-','#','-','-','-','+'}
	  ,{'-','#','#','#','#','#','#','-','#','-','#','#','#'}       //maze shape
	  ,{'-','-','-','#','#','#','#','-','#','-','#','#','#'}
	  ,{'-','#','-','-','#','-','-','-','#','-','-','#','#'}
	  ,{'-','#','#','-','#','-','#','-','#','#','-','#','#'}
	  ,{'-','#','#','-','#','-','#','-','#','-','-','-','#'}
	  ,{'-','-','#','-','-','-','#','-','#','-','#','#','#'}
	  ,{'#','.','-','#','-','#','#','-','#','-','#','#','#'}
	  ,{'#','#','-','#','-','-','#','-','-','-','#','#','#'}
	  ,{'#','#','-','-','-','#','#','#','#','#','#','#','#'}};

int main(){

		system("color 20");         //colour system
	while (move !='Q'||'q'){
		cout<<"Control Your Player using W A S D.-\n\n";
		char x=' ';
		maze[posX][posY]=player;
		
		for(int y=0;y<=10;y++){  //looping for row
			cout<<endl;
			for(int x=0;x<13;x++){ //nested loop column
				cout<<maze[y][x];
	
			}

		}
		playerMove();  //call playerAction function
		
	}
	return 0;
}

void playerMove(){
	int prevposX=posX,prevposY=posY;  //delcare position with int for row and column
	cout<<"\nYour Action \n";
	cin>>move;
	char x=' ';
	unsigned char space={32};
	
	switch (move){    //start selection using switch case
		case 'a':     //selection
			if(maze[posX][posY-1] !='#'){  //selection with if else
				posY--;
				maze[prevposX][prevposY]= space;
			}
				else if(maze[posX-1][posY] ='#'){
				cout<<"YOU BREAK THE TREE!!!! \n ENTER ANOTHER STEP!!\n";
				cout << "Press Enter to Continue\n";
	            cin>>x;
			}
					
			system("cls"); // system new page
			
		break; //break the case selection
		
		case 'd':
			if(maze [posX][posY+1] !='#'){
				posY++;
				maze[prevposX][prevposY]=space;
				
				
			}
			else if(maze[posX][posY+1] ='#'){
				cout<<"YOU BREAK THE TREE!!!! \n ENTER ANOTHER STEP!!\n";
				cout << "Press Enter to Continue\n";
	            cin>>x;
			}

		system("cls"); // system new page
		break;
		
		case 's':
			if(maze[posX+1][posY] !='#'){
				posX++;
				cout<<posX<<','<<posY<<endl;
				maze[prevposX][prevposY]=space;
			}
			else if(maze[posX+1][posY] ='#'){
				cout<<"YOU BREAK THE TREE!!!!\n ENTER ANOTHER STEP!!\n";
				cout << "Press Other Key And Enter to Continue\n";
	            cin>>x;
			}
			system("cls");
			break;
			
		case 'w':
			if(maze [posX-1][posY] !='#'){
				posX--;
				maze[prevposX][prevposY]=space;
			}
			else if(maze[posX-1][posY] ='#'){
				cout<<"YOU BREAK THE TREE!!!!\n ENTER ANOTHER STEP!! \n";
				cout << "Press Other Key And Enter to Continue\n";
	            cin>>x;
			}
			system("cls"); // system new page

		default:
			cout<<"Incorrect Action \n"; // if user enter other char from WASD
			break;
	}
		
}
//void finish(){
//	system("color 34");
//	cout<<endl;
//    cout<<"            *                                           *    "<<endl;   
//    cout<<"          **                                            *   "<<endl;
//    cout<<"   *** CONGRATULATIONSSSS YOUU WINN THISS GAMEEEE****"<<endl;
//    cout<<"          **                                             **  "<<endl;
//    cout<<"            *                                           *   "<<endl;
//    cout<<endl;                                                   
//    
//    
//    Beep(2020,1100);                                                             // causes the computer to beep
//    char l=219;                                                                  //for loading bar
//    cout<<"Please wait while system is analyzing the data\n";
//    for ( int i=0; i<10 ; i++)
//    {
//        Beep(2000,500);\
//        cout<<l; 
//	}
//	cout << "Press Enter to Continue\n";
//	cin.ignore();
//}



