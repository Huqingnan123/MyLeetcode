#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int is_man_win(char (*chess)[3]);
int is_robot_win(char(*chess)[3]);
void mankind(char (*chess)[3]);
void robot(char (*chess)[3]);
void output(char (*chess)[3]);
int main(void)
{
	char chess[3][3] = { {'X','X','X'},{'_','_','_'},{'O','O','O'} };
	output(chess);
	while (is_robot_win(chess) == 1|| is_man_win(chess) != 1)
	{
		mankind(chess);
		printf("After mankind's operation:\n");
		output(chess);
		if (is_man_win(chess) != 1)
		{
			robot(chess);
			printf("After robot's operation:\n");
			output(chess);
			if(is_robot_win(chess) == 1)
				printf("Sorry...Robot Win!\n");
		}
		else
			printf("Congratulations! Mankind Win!\n");
	}
	return 0;
}

int is_man_win(char (*chess)[3])
{
	if ((chess[0][0] == 'X' && chess[1][1]=='X' && chess[2][2]=='X') || (chess[0][2] == 'X' && chess[1][1] == 'X' && chess[2][0] == 'X'))
		return 1;
	else
		return 0;
}

int is_robot_win(char (*chess)[3])
{
	if ((chess[0][0] == 'O' && chess[1][1] == 'O' && chess[2][2] == 'O') || (chess[0][2] == 'O' && chess[1][1] == 'O' && chess[2][0] == 'O'))
		return 1;
	else
		return 0;
}

void mankind(char (*chess)[3])
{
	int row, line,newrow,newline;
	scanf("%d %d", &row, &line);
	scanf("%d %d", &newrow, &newline);
	if (chess[newrow][newline] != '_'||(abs(newrow-row)+abs(newline-line)!=1))
	{
		printf("Illegal operation! Please input again!\n");
		mankind(chess);
	}
	else
	{
		printf("Now row%d line%d->row%d line%d.\n\n", row, line, newrow, newline);
		chess[row][line] = '_';
		chess[newrow][newline] = 'X';
	}
}

void robot(char (*chess)[3])
{
	int row=0, line=0;
	srand((unsigned)time(NULL));
	while (1)
	{
		row = rand() % 3;
		line = rand() % 3;
		if (chess[row][line] == '_')
		{
			if (row == 0 && line == 0)
			{
				if (chess[row + 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row+1][line] = '_';
					break;
				}
				if (chess[row][line+1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line+1] = '_';
					break;
				}
			}
			if (row == 0 && line == 1)
			{
				if (chess[row][line-1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line-1] = '_';
					break;
				}
				if (chess[row][line + 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line + 1] = '_';
					break;
				}
				if (chess[row + 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row + 1][line] = '_';
					break;
				}
			}
			if (row == 0 && line == 2)
			{
				if (chess[row + 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row + 1][line] = '_';
					break;
				}
				if (chess[row][line - 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line - 1] = '_';
					break;
				}
			}
			if (row == 1 && line == 0)
			{
				if (chess[row - 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row - 1][line] = '_';
					break;
				}
				if (chess[row][line + 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line + 1] = '_';
					break;
				}

				if (chess[row + 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row + 1][line] = '_';
					break;
				}
			}
			if (row == 1 && line == 1)
			{
				if (chess[row][line - 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line - 1] = '_';
					break;
				}
				if (chess[row][line + 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line + 1] = '_';
					break;
				}
				if (chess[row + 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row + 1][line] = '_';
					break;
				}
				if (chess[row-1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row - 1][line] = '_';
					break;
				}
			}
			if (row == 1 && line == 2)
			{
				if (chess[row][line - 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line - 1] = '_';
					break;
				}

				if (chess[row + 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row + 1][line] = '_';
					break;
				}
				if (chess[row - 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row - 1][line] = '_';
					break;
				}
			}
			if (row == 2 && line == 0)
			{
				if (chess[row][line + 1] == 'O')
				{

					chess[row][line] = 'O';
					chess[row][line + 1] = '_';
					break;
				}
				if (chess[row - 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row - 1][line] = '_';
					break;
				}
			}
			if (row == 2 && line == 1)
			{
				if (chess[row][line - 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line - 1] = '_';
					break;
				}
				if (chess[row][line + 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line + 1] = '_';
					break;
				}
				if (chess[row - 1][line] = 'O')
				{
					chess[row][line] = 'O';
					chess[row - 1][line] = '_';
					break;
				}
			}
			if (row == 2 && line == 2)
			{
				if (chess[row][line - 1] == 'O')
				{
					chess[row][line] = 'O';
					chess[row][line - 1] = '_';
					break;
				}
				if (chess[row - 1][line] == 'O')
				{
					chess[row][line] = 'O';
					chess[row - 1][line] = '_';
					break;
				}
			}
		}
	}
}
void output(char (*chess)[3])
{
	printf("-------------\n"
		   "| %c | %c | %c |\n"
		   "-------------\n"
		   "| %c | %c | %c |\n"
		   "-------------\n"
		   "| %c | %c | %c |\n"
		   "-------------\n",chess[0][0], chess[0][1], chess[0][2], chess[1][0], chess[1][1], chess[1][2], chess[2][0], chess[2][1], chess[2][2]);
	putchar('\n');
}

