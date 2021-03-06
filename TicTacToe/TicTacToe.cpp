// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>

bool QUIT = false;
bool OPTIONSELETED = false;
bool WIN = false;
bool PLAYERWON = false;

int MENUOFFSET = 0;

int GAMEOFFSETX = 0;
int GAMEOFFSETY = 0;

int Turns = 1;

std::string DrawingPosition[5][5]
{
	{ " ", "|", " ", "|", " " },
	{ "-", "-", "-" , "-" , "-"},
	{ " ", "|", " ", "|", " " },
	{ "-", "-", "-" , "-" , "-" },
	{ " ", "|", " ", "|", " " }
};

std::string SpliterX = "|";

using namespace std; // kinda lazy not to use it

DWORD WINAPI Draw()
{
	while (1)
	{
		if (!WIN)
		{
			for (int x = 0; x < 5; x++)  // loop 3 times for three lines
			{
				for (int y = 0; y < 5; y++)  // loop for the three elements on the line
				{
					cout << DrawingPosition[x][y];  // display the current element out of the array
				}
				cout << endl;  // when the inner loop is done, go to a new line
			}
			Sleep(200);
			system("CLS");
		}
		else
		{
			Sleep(200);
			system("CLS");
			if (PLAYERWON)
			{
				cout << "Game Over ( Player X WON )" << endl;
			}
			else
			{
				cout << "Game Over ( Player O WON )" << endl;
			}
			Sleep(3000);
			exit(1);
		}
	}
	return 0;
}

DWORD WINAPI GetInput()
{
	while (!QUIT)
	{
		if (!OPTIONSELETED)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				if (!(MENUOFFSET <= 0))
				{
					MENUOFFSET--;
				}
				Sleep(200);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (!(MENUOFFSET >= 2))
				{
					MENUOFFSET++;
				}
				Sleep(200);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				OPTIONSELETED = true;
			}
		}
		else
		{
			if (GetAsyncKeyState(VK_UP))
			{
				if (DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "X" && DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "O")
				{
					DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] = " ";
				}
				GAMEOFFSETY--;
				if (GAMEOFFSETY == 1)
				{
					GAMEOFFSETY = 0;
				}
				if (GAMEOFFSETY == 3)
				{
					GAMEOFFSETY = 2;
				}

				if (GAMEOFFSETY < 0)
				{
					GAMEOFFSETY = 0;
				}

				Sleep(200);
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "X" && DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "O")
				{
					DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] = " ";
				}
				GAMEOFFSETY++;
				if (GAMEOFFSETY == 1)
				{
					GAMEOFFSETY = 2;
				}
				if (GAMEOFFSETY == 3)
				{
					GAMEOFFSETY = 4;
				}

				if (GAMEOFFSETY > 4)
				{
					GAMEOFFSETY = 5;
				}

				Sleep(200);
			}

			if (GetAsyncKeyState(VK_RIGHT))
			{
				if (DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "X" && DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "O")
				{
					DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] = " ";
				}
				GAMEOFFSETX++;
				if (GAMEOFFSETX == 1)
				{
					GAMEOFFSETX = 2;
				}
				if (GAMEOFFSETX == 3)
				{
					GAMEOFFSETX = 4;
				}

				if (GAMEOFFSETX > 4)
				{
					GAMEOFFSETX = 5;
				}

				Sleep(200);
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				if (DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "X" && DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "O")
				{
					DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] = " ";
				}
				GAMEOFFSETX--;
				if (GAMEOFFSETX == 1)
				{
					GAMEOFFSETX = 0;
				}
				if (GAMEOFFSETX == 3)
				{
					GAMEOFFSETX = 2;
				}

				if (GAMEOFFSETX < 0)
				{
					GAMEOFFSETX = 0;
				}

				Sleep(200);
			}
			if (GAMEOFFSETY < 0)
			{
				GAMEOFFSETY = 0;
			}
			if (GAMEOFFSETY > 4)
			{
				GAMEOFFSETY = 4;
			}

			if (GAMEOFFSETX < 0)
			{
				GAMEOFFSETX = 0;
			}
			if (GAMEOFFSETX > 4)
			{
				GAMEOFFSETX = 4;
			}

			if (GetAsyncKeyState(VK_RETURN))
			{
				if (DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "X" && DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "O")
				{

					Turns++;
					// O
					if (Turns % 2 == 0)
					{
						DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] = "O";
					}
					// X
					else
					{
						DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] = "X";
					}
					Sleep(200);
				}
			}
			if (DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "X" && DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] != "O")
			{
				DrawingPosition[GAMEOFFSETY][GAMEOFFSETX] = "+";
			}
		}
		
		Sleep(30);
	}
	return 0;
}

DWORD WINAPI Menu()
{
	while (!OPTIONSELETED)
	{
		cout << "Welcome To Sagaan's Tic-Tac-Toe Game" << endl;
		cout << "Enjoy Your Stay" << endl;
		cout << endl;

		switch (MENUOFFSET)
		{
		case 0:
			cout << "Play <<" << endl;
			cout << "Help" << endl;
			cout << "Quit" << endl;
			break;
		case 1:
			cout << "Play" << endl;
			cout << "Help <<" << endl;
			cout << "Quit" << endl;
			break;
		case 2:
			cout << "Play" << endl;
			cout << "Help" << endl;
			cout << "Quit <<" << endl;
			break;
		}

		Sleep(200);
		system("CLS");
	}
	return 0;
}

void PlayGame()
{
	while (1)
	{
		// Horizonta WIN

		if ((DrawingPosition[0][0] == "X" && DrawingPosition[0][2] == "X" && DrawingPosition[0][4] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if ((DrawingPosition[0][0] == "O" && DrawingPosition[0][2] == "O" && DrawingPosition[0][4] == "O"))
		{
			WIN = true;
			PLAYERWON = false;
		}

		if ((DrawingPosition[2][0] == "X" && DrawingPosition[2][2] == "X" && DrawingPosition[2][4] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if ((DrawingPosition[2][0] == "O" && DrawingPosition[2][2] == "O" && DrawingPosition[2][4] == "O"))
		{
			WIN = true;
			PLAYERWON = false;
		}

		if ((DrawingPosition[4][0] == "X" && DrawingPosition[4][2] == "X" && DrawingPosition[4][4] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if ((DrawingPosition[4][0] == "O" && DrawingPosition[4][2] == "O" && DrawingPosition[4][4] == "O"))
		{
			WIN = true;
			PLAYERWON = false;
		}

		// Vertical WIN
		if ((DrawingPosition[0][0] == "X" && DrawingPosition[2][0] == "X" && DrawingPosition[4][0] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if ((DrawingPosition[0][0] == "O" && DrawingPosition[2][0] == "O" && DrawingPosition[4][0] == "O"))
		{
			WIN = true;
			PLAYERWON = false;
		}
		if ((DrawingPosition[0][2] == "X" && DrawingPosition[2][2] == "X" && DrawingPosition[4][2] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if ((DrawingPosition[0][2] == "O" && DrawingPosition[2][2] == "O" && DrawingPosition[4][2] == "O"))
		{
			WIN = true;
			PLAYERWON = false;
		}
		if ((DrawingPosition[0][4] == "X" && DrawingPosition[2][4] == "X" && DrawingPosition[4][4] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if ((DrawingPosition[0][4] == "O" && DrawingPosition[2][4] == "O" && DrawingPosition[4][4] == "O"))
		{
			WIN = true;
			PLAYERWON = false;
		}

		// DIA WIN
		if ((DrawingPosition[0][0] == "X" && DrawingPosition[2][2] == "X" && DrawingPosition[4][4] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if((DrawingPosition[0][0] == "O" && DrawingPosition[2][2] == "O" && DrawingPosition[4][4] == "O"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		if ((DrawingPosition[0][4] == "X" && DrawingPosition[2][2] == "X" && DrawingPosition[4][0] == "X"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		else if ((DrawingPosition[0][4] == "O" && DrawingPosition[2][2] == "O" && DrawingPosition[4][0] == "O"))
		{
			WIN = true;
			PLAYERWON = true;
		}
		Sleep(20);
	}
}

int main()
{
	while (!QUIT)
	{
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Menu, NULL, 0, NULL);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)GetInput, NULL, 0, NULL);
		while (!QUIT)
		{
			if (OPTIONSELETED)
			{
				Sleep(200);
				switch (MENUOFFSET)
				{
				case 0:
					CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Draw, NULL, 0, NULL);
					PlayGame();
					break;
				case 1:
					// http://web.cecs.pdx.edu/~bart/cs541-fall2001/homework/tictactoe-rules.html
					cout << "The object of Tic Tac Toe is to get three in a row. You play on\na three by three game board. The first player is known as X\nand the second is O. Players alternate placing Xs and Os on\nthe game board until either oppent has three in a row or all\nnine squares are filled." << endl;
					Sleep(5000);
					MENUOFFSET = 0;
					break;
				case 2:
					exit(-1);
					break;
				}
				Sleep(200);
			}
			else
			{
				Sleep(200);
			}
		}

	}
}

