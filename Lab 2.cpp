//The Sinking Ship 
//
//Created Oct. 4, 2018
//By: Ryan Stolys

#include <iostream>
#include<cstdlib>

using namespace std;

//Constants 
#define BATTLESHIP 4
#define CRUISER 3
#define CARGO 2
#define SUBMARINE 1
#define DIM 8
#define NUM_BOARDS 100



//Prototypes
void Generate_Board(int** GameBoard, int seed);
void Print_Board(int** Game_Board);
bool Check_Location(int Ship_Type, int x, int y, int** GameBoard);
void Insert_Ship(int Ship_Type, int** GameBoard, int x, int y);
void Set_Board(int** Game_Board);

int main()
{


	//Allocate Game Board
	int** Game_Board = new int*[DIM];
	for (int i = 0; i < DIM; i++)
	{
		int* col = new int[8];
		Game_Board[i] = col;
	}

	//Set Game board to all zeros
	Set_Board(Game_Board);


	//Generate and Print Game board 100 times 

	for (int a = 0; a < NUM_BOARDS; a++)
	{
		//Call generate game baord function
		Generate_Board(Game_Board, a);

		//Call print function 
		Print_Board(Game_Board);

		//Reset game board to all zeros
		Set_Board(Game_Board);

		cout << endl << "************" << endl;
	}


	//Deallocate memory
	for (int b = 0; b < DIM; b++)
	{
		delete[] Game_Board[b];
	}
	delete[] Game_Board;

	return 0;
}


//Function Definitons

void Generate_Board(int** GameBoard, int seed)
{
	int x_loc;	//number will give rows and column index 
	int y_loc;

	//Initalize Rand function 
	srand(seed);

	//Place each type of ship starting with largest first

	//Battleship
	int count = 0;
	while (count != 1)
	{
		//Generate x and y location for ship
		x_loc = rand() % 8;
		y_loc = rand() % 8;

		//Determine in location is valid
		if (Check_Location(BATTLESHIP, x_loc, y_loc, GameBoard))
		{
			Insert_Ship(BATTLESHIP, GameBoard, x_loc, y_loc);
			count++;
		}
		else
		{
			continue;
		}
	}

	count = 0;			//Reset counter

	//Cruiser
	while (count != 2)
	{
		//Generate x and y location for ship
		x_loc = rand() % 8;
		y_loc = rand() % 8;

		//Determine in location is valid
		if (Check_Location(CRUISER, x_loc, y_loc, GameBoard))
		{
			Insert_Ship(CRUISER, GameBoard, x_loc, y_loc);
			count++;
		}
		else
		{
			continue;
		}
	}

	count = 0;			//Reset counter

	//Cargo Ship
	while (count != 5)
	{
		//Generate x and y location for ship
		x_loc = rand() % 8;
		y_loc = rand() % 8;

		//Determine in location is valid
		if (Check_Location(CARGO, x_loc, y_loc, GameBoard))
		{
			Insert_Ship(CARGO, GameBoard, x_loc, y_loc);
			count++;
		}
		else
		{
			continue;
		}
	}

	count = 0;			//Reset counter

	//Submarine
	while (count != 10)
	{
		//Generate x and y location for ship
		x_loc = rand() % 8;
		y_loc = rand() % 8;

		//Determine in location is valid
		if (Check_Location(SUBMARINE, x_loc, y_loc, GameBoard))
		{
			Insert_Ship(SUBMARINE, GameBoard, x_loc, y_loc);
			count++;
		}
		else
		{
			continue;
		}
	}

	//Game board is now filled

	return;
}

void Insert_Ship(int Ship_Type, int** GameBoard, int x, int y)
{
	if (Ship_Type == BATTLESHIP)
	{
		GameBoard[y][x] = BATTLESHIP;
		GameBoard[y + 1][x] = BATTLESHIP;
		GameBoard[y + 2][x] = BATTLESHIP;
		GameBoard[y + 3][x] = BATTLESHIP;
	}
	else if (Ship_Type == CRUISER)
	{
		GameBoard[y][x] = CRUISER;
		GameBoard[y + 1][x] = CRUISER;
		GameBoard[y + 2][x] = CRUISER;

	}
	else if (Ship_Type == CARGO)
	{
		GameBoard[y][x] = CARGO;
		GameBoard[y + 1][x] = CARGO;
	}
	else
	{
		GameBoard[y][x] = SUBMARINE;
	}

	return;
}


void Print_Board(int** Game_Board)
{
	int piece = 0;
	for (int row = 0; row < DIM; row++)
	{
		for (int col = 0; col < DIM; col++)
		{
			piece = Game_Board[row][col];

			//Print Charcter depending on piece type

			if (piece == BATTLESHIP)
			{
				cout << "B";
			}
			else if (piece == CRUISER)
			{
				cout << "C";
			}
			else if (piece == CARGO)
			{
				cout << "S";
			}
			else if (piece == SUBMARINE)
			{
				cout << "_";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}


bool Check_Location(int Ship_Type, int x, int y, int** GameBoard)
{

	if (Ship_Type == BATTLESHIP)
	{
		//Check if all of ship is on board
		if (y > 4)
		{
			return false;
		}

		//First ship placed, no other ships to avoid
	}
	else if (Ship_Type == CRUISER)
	{
		//Check if all of ship is on board
		if (y > 5)
		{
			return false;
		}

		//Check if other ships are in locations specifcied
		if (GameBoard[y][x] != 0 || GameBoard[y + 1][x] != 0 || GameBoard[y + 2][x] != 0)
		{
			return false;
		}
	}
	else if (Ship_Type == CARGO)
	{
		//Check if all of ship is on board
		if (y > 6)
		{
			return false;
		}

		//Check if other ships are in locations specifcied
		if (GameBoard[y][x] != 0 || GameBoard[y + 1][x] != 0)
		{
			return false;
		}
	}
	else if (Ship_Type == SUBMARINE)
	{
		//Ship will lie on board

		//Check if other ships are in locations specifcied
		if (GameBoard[y][x] != 0)
		{
			return false;
		}
	}

	//No conditions were violated, Loaction is valid 
	return true;
}


void Set_Board(int** Game_Board)
{
	for (int row = 0; row < DIM; row++)
	{
		for (int col = 0; col < DIM; col++)
		{
			Game_Board[row][col] = 0;
		}
	}
	return;
}
