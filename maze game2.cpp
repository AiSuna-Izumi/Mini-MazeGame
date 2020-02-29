#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

unsigned char player ={'P'}; //declare player on every function
int posX=1,posY=1;         //declare player place 
unsigned char action;       //declare move player
void finish();      //declare finish function
void playerAction();  //delcare player function

struct enemy{ //decalre struct
	bool active;
	int x;
	int y;
};

unsigned char maze[10][13]=
	 { {'#','-','-','-','#','-','-','-','-','-','-','-','#'}
	  ,{'-','-','#','-','#','-','#','#','#','#','#','-','#'}       //maze shape
	  ,{'#','#','#','-','#','-','-','-','-','-','#','-','#'}
	  ,{'#','-','-','-','-','#','#','#','#','-','#','-','+'}
	  ,{'#','#','#','#','-','#','-','#','#','-','#','-','#'}
	  ,{'#','-','-','#','-','#','-','#','#','-','#','-','#'}
	  ,{'#','#','-','#','-','-','-','-','-','-','#','-','#'}
	  ,{'#','.','-','-','-','#','-','#','#','#','#','-','#'}
	  ,{'#','#','#','#','#','#','-','-','-','-','#','-','#'}
	  ,{'#','-','-','-','-','-','-','#','#','-','-','-','#'}};

int main(){

		system("color 20");         //colour system
	while (action !='Q'||'q' ){
		cout<<"Control Your Player using W A S D.-\n\n";
		char x=' ';
		int row,column;
		maze[posX][posY]=player;
		
		for(int y=0;y<=10;y++){  //looping for row
			cout<<endl;
			for(int x=0;x<13;x++){ //nested loop column
				cout<<maze[y][x];
				row=x;
			}
			column=y;
			
		}
		if(maze[row][column]='+'){
			cout<<"SYSTEM EXIT";
			cin>>row;
		}
		playerAction();  //call playerAction function
		
	}
	return 0;
}

void playerAction(){
	int prevposX=posX,prevposY=posY;  //delcare position with int for row and column
	cout<<"\nYour Action \n \n Or Input Q To Exit \n ";
	cin>>action;
	char x=' ';
	unsigned char space={32};
	
	switch (action){    //start selection using switch case
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
				else if(maze[posX][posY-1] ='+'){
				cout<<"CONGRATE YOU FINISH THE MAZE!!!! \n\n";
				finish();
				system("exit");
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
			else if(maze[posX][posY+1] ='+'){
				cout<<"CONGRATE YOU FINISH THE MAZE!!!! \n\n";
				finish();
				system("exit");
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
				else if(maze[posX+1][posY] ='+'){
				cout<<"CONGRATE YOU FINISH THE MAZE!!!! \n\n";
				finish();
				system("exit");
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
			else if(maze[posX-1][posY] ='+'){
				cout<<"CONGRATE YOU FINISH THE MAZE!!!! \n\n";
				finish();
				system("exit");
			}
			system("cls"); // system new page
		
		case 'q':
			cout<<"READY TO QUIT \n";
			cin.ignore();
			system("Exit");
		default:
			cout<<"Incorrect Action \n"; // if user enter other char from WASD
			break;
	}
		
}
void finish(){
	system("color 34");
	cout<<endl;
    cout<<"            *                                           *    "<<endl;   
    cout<<"          **                                            *   "<<endl;
    cout<<"   *** CONGRATULATIONSSSS YOUU WINN THISS GAMEEEE****"<<endl;
    cout<<"          **                                             **  "<<endl;
    cout<<"            *                                           *   "<<endl;
    cout<<endl;                                                   
    
    
    Beep(2020,1100);                                                             // causes the computer to beep
    char l=219;                                                                  //for loading bar
    cout<<"Please wait while system is analyzing the data\n";
    for ( int i=0; i<10 ; i++)
    {
        Beep(2000,500);\
        cout<<l; 
	}
	cout << "Press Enter to Continue\n";
	cin.ignore();
}



