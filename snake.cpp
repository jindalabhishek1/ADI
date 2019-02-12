// Snake Game

#include <iostream>
#include <stdlib.h>
using namespace std;

#define rows 10
#define cols 15

struct Node
{
    int x, y;
    char value;
    Node *next;
} *head, *tail;

struct Food
{
    int x, y;
    char value = 'F';
} *food;

Node * NewNode(int x, int y, char value)
{
    Node *newNode = new Node();
    newNode->x = x;
    newNode->y = y;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Food *createFood()
{
    srand(time(0));
    Food *newFood = new Food();
    newFood->x = rand() % (rows - 1);
    newFood->y = rand() % (cols - 1);
    return newFood;
}

char ** createBoard()
{
    char **board = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = ' ';
        }
    }
    return board;
}

void displayBoard(char **board)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << board[i][j] << '|';
        }
        cout << endl;
    }
}

void projectFood(char **board, Food *food)
{
    board[food->x][food->y] = food->value;
}

int main()
{
    char **board = createBoard();
    // displayBoard(board);
    food = createFood();
    // cout << food->x << " " << food->y << " " << food->value << endl;
    projectFood(board, food);
    displayBoard(board);
}
