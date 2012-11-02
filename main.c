/*
 * Recursive N-Queens Solution by Randy White-  Released via GPLv2
 * 
 * Copyright 2012  <romxero@lapdog>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 *  http://github.com/romxero
 * 	http://www.youtube.com/romxero
 */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//declaration of the main functions
void queenP(int N, char chessBoard[N][N], int count, int *externalCounter);
void displayChessBoard(int N, char chessBoard[N][N]);
void splayBoard(int i,int k, int N, char chessBoard[N][N]);
void copyBoard(int N, char chessBoard[N][N],char duplicateBoard[N][N]);
void setChessBoard(int N, char chessBoard[N][N]);


	int main(int argc, char **argv)

	{
		
		if (!(argv[1]))
	{
		fflush(stdout);
		printf("Usage:\n%s [number]\nIts very simple!, just type in the program name and a number\nfor the board size, and number of queens\n\n",argv[0]);
		puts("Made by Randy White");
		return -1;
	}
	
		
		int N = atoi(argv[1]);
		char board[N][N]; //this is the multidemensional board right here
		int mainCounter = 0;
		
		int internalCounter = 0; //set this up so its zero to begin with
			//nothing yet
		//	recurse(internalCounter);

		
		
		
		fflush(stdout);
		puts("Recursive N-Queens Solution by Randy White");
		
		sleep(5);
		fflush(stdout);
		
		setChessBoard(N, board); //set up the chess board
		displayChessBoard(N, board); //set up the chess board
		
		printf("\nThis is the board, it is an %d X %d, and we are finding a solution for %d queens\n\n",N,N,N);
		
		sleep(5);
		queenP(N, board, internalCounter,&mainCounter); //there is a stack overflow WTF~!!

		
		return 1; //everything is good in the world

	}


void setChessBoard(int N, char chessBoard[N][N])
{
	int i, k;
	i = k = 0; //set the values in order to process them 
	for (i = 0; i < N; ++i)
	{
			for (k = 0; k < N; ++k)
			{
				chessBoard[i][k] = '-'; //assign them all the character '-'//
				
			}
		
	}
}

void queenP(int N, char chessBoard[N][N], int count, int *externalCounter)
{
	if (count == N)
	{
		++*externalCounter;
		puts("Found A Solution!!\n");

	}
	
	else
	{
	
			++count;
			
				
		int i, k; //counter for the  FSM 
		 
		 i = k = 0;

		for (i = 0; i < N; ++i)
		{
			for (k = 0; k < N; ++k)
			{
					if (chessBoard[i][k] == '-')
					{
						char duplicateBoard[N][N];
						copyBoard(N, chessBoard, duplicateBoard);
						duplicateBoard[i][k] = 'Q';
						splayBoard(i,k,N,duplicateBoard);
						displayChessBoard(N, duplicateBoard);
						
						printf("__________________________\n"); //seperate each chessboard
						printf("%d : Solutions\n\n",*externalCounter);
						printf("Created by Randy White\n\n"); //seperate each chessboard
						printf("__________________________\n\n"); //seperate each chessboard
						sleep(2);
								
					//	break;
						 
						 queenP(N, duplicateBoard,count,externalCounter);
						 
					}
				
			
				//break; //temporary
			}

			
		}
}

}
//duplicate below used to view the nqueens problem

void displayChessBoard(int N, char chessBoard[N][N])
{

		
int i, k; //counter for the  FSM 
 
 i = k = 0;

for (i = 0; i < N; ++i)
{
	for (k = 0; k < N; ++k)
	{
		printf("%c ",chessBoard[i][k]); //just a regular output of whats going on
		if (k == ( N - 1))
		{
				printf("\n");
		}
		//something here
	
	}
		

}


}

void copyBoard(int N, char chessBoard[N][N],char duplicateBoard[N][N])
{
	
	int i, k; //counter for the  FSM 
 
 i = k = 0;

for (i = 0; i < N; ++i)
{
	for (k = 0; k < N; ++k)
	{
		duplicateBoard[i][k] = chessBoard[i][k];

	}


}
	
}


void splayBoard(int i,int k, int N, char chessBoard[N][N])
{
		
		int m, n, o, p;
		m = n = o = p = 0;
		for (n = 0; n < N; ++n)
		{
			if ( n != k)
			{
				chessBoard[i][n] = '*';
			}
			
			
		}
		
		for (m = 0; m < N; ++m)
		{
			if ( m != i)
			{
				chessBoard[m][k] = '*';
			}
		}
		
		m = n = o = p = 0;
		o = p = k;
		
		m = n = i;
		
		for (; n < N; ++n)
		{
			if (!(o > N))
			{
				if (chessBoard[n][o] != 'Q')
				{
					chessBoard[n][o] = '*';
				}
				++o;
			}
			
			if (!(p < 0))
			{
				if (chessBoard[n][p] != 'Q')
				{
				chessBoard[n][p] = '*';
				}
				--p;
				
			}
			
		}
		
		o = p = k;		
	
	for (; m >= 0; --m)
	{
		if (!(o > N))
			{
				if (chessBoard[m][o] != 'Q')
				{
					chessBoard[m][o] = '*';
				}
				++o;
			}
			
			if (!(p < 0))
			{
				if (chessBoard[m][p] != 'Q')
				{
				chessBoard[m][p] = '*';
				}
				--p;
				
			}
		
		
	}
	
		//~ for (; i < N; ++i)
		//~ {
						//~ for (; (k+1) < N; ++k)
						//~ {
							//~ chessBoard[i][k] = '*';
							//~ 
							//~ 
						//~ }
					//~ 
		//~ }
	
	
}
