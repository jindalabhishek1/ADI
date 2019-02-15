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

struct Snake
{
    Node * ptr = NULL;
    int length = 0;
};

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
            board[i][j] = '_';
        }
    }
    return board;
}

void displayList(Node *head)
{
    while (head != NULL)
    {
        cout << head->x << " " << head->y << " " << head->value << endl;
        head = head->next;
    }
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

void detectFoodColision(Food *food)
{

}

void saveNode(Node **head_ref)
{
    
}

char createSnake(char flag)
{
    head = NewNode(4, 5, 'H');
    Node *newNode = new Node();
    newNode = NewNode(4, 6, '#');
    head->next = newNode;
    tail = NewNode(4, 7, 'T');
    newNode->next = tail;
    flag = 'a';
    return flag;
}

void projectFood(char **board, Food *food)
{
    board[food->x][food->y] = food->value;
}

void clearBoard(char **board)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = '_';
        }
    }
}

void projectSnake(char **board, Node **head_ref)
{
    Node *temp = *head_ref;
    while(temp != NULL)
    {
        board[temp->x][temp->y] = temp->value;
        temp = temp->next;
    }
}

void updateSnake(Node *temp)
{
    // Node *last = NULL;
    // Node *current = temp;
    if (temp->next == NULL)
    {
        // return current->next;
        return;
    }
    updateSnake(temp->next);
    temp->next->x = temp->x;
    temp->next->y = temp->y;
}

void moveSnake(Node **head_ref, char **board, Food *food, char flag)
{
    Node *temp = *head_ref;
    char choice;
    cout << "Enter:- w: forward, s: backward, a: left, d: right\n";
    cin >> choice;
    while (choice != 'x' && choice != 'X')
    {
        switch (choice)
        {
            case 'W':
            case 'w':
                // if (temp->x - temp->next->x > 0)
                if (flag == 's')
                {
                    // cout << "temp->x = " << temp->x << " temp->next->x = " << temp->next->x << endl;
                    cout << "Not Allowed\n";
                    // cout << flag << endl;
                }
                else
                {
                    Node *prev = *head_ref;
                    /*
                    while (temp->next != NULL)
                    {
                        temp->next->x = temp->x;
                        temp->next->y = temp->y;
                        // temp->next->value = temp->value;
                        // prev->x = prev->x - 1;
                        temp = temp->next;
                        // prev = prev->next;
                    }
                    */
                    updateSnake(prev);
                    // prev->x = prev->x -1;
                    if (prev->x == 0)
                    {
                        prev->x = rows - 1;
                    }
                    else
                    {
                        prev->x = prev->x - 1;
                    }
                    flag = 'w';
                }
                displayList(temp);
                break;
            case 'S':
            case 's':
                // if (temp->next->x - temp->x > 0)
                if (flag == 'w')
                {
                    cout << "Not Allowed\n";
                    // cout << flag << endl;
                }
                else
                {
                    Node *prev = *head_ref;
                    // cout << "prev:" << prev->x << " " << prev->y << " " << prev->value << endl;
                    /*
                    while (temp->next->next != NULL)
                    {
                        // updateSnake(temp);
                        // cout << last->x << " " << last->y << " " << last->value << endl;
                        // cout << last->next->x << " " <<  last->next->y << " " << last->next->value << endl;
                        // cout << temp->x << " " << temp->y << " " << temp->value << endl;
                        // cout << temp->next->x << " " <<  temp->next->y << " " << temp->next->value << endl;
                        // temp->next->value = temp->value;
                        // prev->x = prev->x + 1;
                        // temp = temp->next;
                        // prev = prev->next;
                        // cout << endl;
                    }
                    */
                    updateSnake(prev);
                    // prev->x = prev->x + 1;
                    if (prev->x == rows - 1)
                    {
                        prev->x = 0;
                    }
                    else
                    {
                        prev->x = prev->x + 1;
                    }
                    flag = 's';
                }
                displayList(temp);
                break;
            case 'A':
            case 'a':
                // if (temp->y - temp->next->y > 0)
                if (flag == 'd')
                {
                    cout << "Not Allowed\n";
                    // cout << flag << endl;
                }
                else
                {
                    Node *prev = *head_ref;
                    updateSnake(prev);
                    /*
                    while (temp->next != NULL)
                    {
                        temp->next->x = temp->x;
                        temp->next->y = temp->y;
                        // temp->next->value = temp->value;
                        // prev->y = prev->y - 1;
                        temp = temp->next;
                        // prev = prev->next;
                    }
                    */

                    // prev->y = prev->y - 1;
                    if (prev->y == 0)
                    {
                        prev->y = cols - 1;
                    }
                    else
                    {
                        prev->y = prev->y - 1;
                    }
                    flag = 'a';
                }
                displayList(temp);
                break;
            case 'D':
            case 'd':
                // if (temp->next->y - temp->y > 0)
                if (flag == 'a')
                {
                    cout << "Not Allowed\n";
                    // cout << flag << endl;
                }
                else
                {
                    Node *prev = *head_ref;
                    updateSnake(prev);
                    /*
                    while (temp->next != NULL)
                    {
                        temp->next->x = temp->x;
                        temp->next->y = temp->y;
                        // temp->next->value = temp->value;
                        // prev->y = prev->y + 1;
                        temp = temp->next;
                        // prev = prev->next;
                    }
                    */
                    // prev->y = prev->y + 1;
                    if (prev->y == cols - 1)
                    {
                        prev->y = 0;
                    }
                    else
                    {
                        prev->y = prev->y + 1;
                    }
                    flag = 'd';
                }
                displayList(temp);
                break;
            default:
                // cout << "Enter the correct choice";
                break;
        }
        clearBoard(board);
        projectFood(board, food);
        projectSnake(board, &temp);
        displayBoard(board);
        cout << "Enter:- w: forward, s: backward, a: left, d: right\n";
        cin >> choice;
    }

}

int main()
{
    char flag;
    char **board = createBoard();
    // displayBoard(board);
    food = createFood();
    // cout << food->x << " " << food->y << " " << food->value << endl;
    Snake *snake  = new Snake[rows];
    flag = createSnake(flag, snake);
    projectSnake(board, &head);
    projectFood(board, food);
    displayList(head);
    displayBoard(board);
    moveSnake(&head, board, food, flag);
}
