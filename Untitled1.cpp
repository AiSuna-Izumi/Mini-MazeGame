#include <iostream>
using namespace std;

unsigned char player ={1};
int posX=1,posY=1;
unsigned char action;

void playerAction();
struct enemy{
	char symbol;
	bool active;
	int x;
	int y;
};

unsigned char maze[20][20]=
	 { {'-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-', '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-'}
     , {'|' , '#' , '#' , '#' , '|' , '#' , '#' , '#' , '#' , '#' , '#', '#' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '#' , '|' , '-' , '-' , '-' , '-', '-' , '-' , '#' , '-' , '-' , '-' , '-' , '-' , '|'}
     , {'|' , '#' , '|' , '#' , '#' , '#' , '|' , '#' , '#' , '#' , '#', '#' , '|' , '#' , '#' , '#' , '#' , '#' , '#' , '|'}
     , {'|' , 'O' , '|' , '#' , '|' , '-' , '-' , '#' , '|' , '-' , '|', '#' , '|' , '-' , '-' , '-' , '-' , '-' , '#' , '|'}
     , {'|' , '-' , '-' , '-' , '|' , '#' , '|' , '#' , '|' , '#' , '|', '#' , '|' , '#' , '#' , '#' , '#' , '#' , '#' , '|'}
     , {'|' , '#' , '#' , '#' , '|' , '#' , '|' , '#' , '#' , '#' , '|', '#' , '|' , '#' , '-' , '-' , '-' , '-' , '-' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '#' , '|' , '-' , '#' , '|' , '-', '#' , '|' , '#' , '|' , '#' , '#' , '#' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '#' , '|' , '#' , '#' , '|' , '#', '#' , '|' , '#' , '#' , '#' , '-' , '-' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '#' , '|' , '#' , '-' , '|' , '#', '#' , '|' , '-' , '-' , '-' , '|' , '|' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '#' , '#' , '|' , '#' , '#' , '|' , '#', '#' , '#' , '|' , '#' , '#' , '#' , '|' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '-' , '-' , '-' , '#' , '|' , '#', '|' , '#' , '|' , '#' , '-' , '-' , '|' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '#' , '#' , '#' , '#' , '|' , '#', '|' , '#' , '|' , '#' , '|' , '#' , '#' , '#' , '|'}
     , {'|' , '#' , '-' , '-' , '|' , '#' , '|' , '-' , '#' , '|' , '#', '|' , '#' , '|' , '#' , '-' , '-' , '#' , '-' , '|'}
     , {'|' , '#' , '#' , '#' , '|' , '#' , '|' , '#' , '#' , '|' , '#', '|' , '#' , '|' , '#' , '#' , '#' , '#' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '#' , '|' , '#' , '#' , '|' , '#', '|' , '#' , '|' , '-' , '-' , '-' , '-' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '#' , '#' , '|' , '#' , '#' , '|' , '#', '|' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , '|'}
     , {'|' , '#' , '|' , '#' , '|' , '-' , '-' , '-' , '-' , '-' , '#', '|' , '#' , '|' , '-' , '-' , '-' , '-' , '#' , '|'}
     , {'|' , 'X' , '|' , '#' , '|' , '#' , '#' , '#' , '#' , '#' , '#', '|' , '#' , '|' , '#' , '#' , '#' , '#' , '#' , '|'}
     , {'-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-', '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-' , '-'}};
int main(){
	while (action !='Q'||'q'){
		cout<<"Control Your Player using W A S D..\n\n";
		
		maze[posX][posY]=player;
		
		for(int y=0;y<=20;y++){
			cout<<endl;
			for(int x=0;x<=20;x++){
				cout<<maze[y][x];
			}
			
			//call struuct
			enemy enemy1 ;
			enemy1.symbol='X';
			enemy1.active=true;
			enemy1.x=3;
			enemy1.y=6;
			maze[enemy1.y][enemy1.x]=enemy1.symbol;
			
			//call second struct for enemy
			enemy enemy2;
			enemy2.symbol='Y';
			enemy2.active =true;
			enemy2.x=8;
			enemy2.y=1;
			maze[enemy2.y][enemy2.x]=enemy2.symbol;
		}
		
		playerAction();
	}
	return 0;
}
void playerAction(){
	cout<<"\n Your Action";
	cin>>action;
	int prevposX=posX;
	int prevposY=posY;
	
	unsigned char space={32};
	
	switch (action){
		case 'a':
			if(maze[posX][posY-1] !='a'){
				posY--;
//				cout<<posX<<','<<posY<<endl;
				maze[prevposX][prevposY]= space;
			}
			system("cls");
			
		break;
		
		case 'd':
			if(maze [posX][posY+1] !='#'){
				posY++;
	//			cout<<posX<<','<<posY<<endl;
				maze[prevposX][prevposY]=space;
			}
		system("cls");
		break;
		
		case 's':
			if(maze[posX+1][posY] !='#'){
				posX++;
				cout<<posX<<','<<posY<<endl;
				maze[prevposX][prevposY]=space;
			}
			system("cls");
			break;
			
		case 'w':
			if(maze [posX-1][posY] !='#'){
				posX--;
		//		cout<<posX<<','<<posY<<endl;
				maze[prevposX][prevposY]=space;
			}
			system("cls");

		default:
			cout<<"Incorrect Action \n";
			break;
	}
}


