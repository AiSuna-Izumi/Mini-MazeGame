#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

unsigned char player ={'P'};
int posX=1,posY=1;
unsigned char action;
void finish();
void playerAction();
struct enemy{
	bool active;
	int x;
	int y;
};

unsigned char maze[15][15]= 
                         {   {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
						     {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
							 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','+'}  };

int main(){

	while (action !='Q'||'q'){
		cout<<"Control Your Player using W A S D.-\n\n";
		system("color 20");
		char x=' ';
		int row,column;
		maze[posX][posY]=player;
		
		for(int y=0;y<=15;y++){
			cout<<endl;
			for(int x=0;x<16;x++){
				cout<<maze[y][x];
				row=x;
			}
			column=y;
			
		}
		playerAction();
		
	}
	return 0;
}
void playerAction(){
	int prevposX=posX,prevposY=posY;
	cout<<"\nYour Action \n";
	cin>>action;
	char x=' ';
	unsigned char space={32};
	
	switch (action){
		case 'a':
			if(maze[posX][posY-1] !='#'){
				posY--;
				maze[prevposX][prevposY]= space;
			}
					
			system("cls");
			
		break;
		
		case 'd':
			if(maze [posX][posY+1] !='#'){
				posY++;
				maze[prevposX][prevposY]=space;
				
				
			}
			else if(maze[posX][posY+1] ='#'){
				cout<<"YOU BREAK THE TREE!!!! \n ENTER ANOTHER STEP!!";
				cout << "Press Enter to Continue\n";
	            cin>>x;
			}

		system("cls");
		break;
		
		case 's':
			if(maze[posX+1][posY] !='#'){
				posX++;
				cout<<posX<<','<<posY<<endl;
				maze[prevposX][prevposY]=space;
			}
			else if(maze[posX+1][posY] ='#'){
				cout<<"YOU BREAK THE TREE!!!!\n ENTER ANOTHER STEP!!";
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
				cout<<"YOU BREAK THE TREE!!!!\n ENTER ANOTHER STEP!!";
				cout << "Press Other Key And Enter to Continue\n";
	            cin>>x;
			}
			system("cls");

		default:
			cout<<"Incorrect Action \n";
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



