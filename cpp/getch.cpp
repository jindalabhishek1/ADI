#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    while (1)
    {
        cout << "enter something:\t";       
        if (!kbhit())
        {
            cout << "keystrok " << (char)getch() << " hit. Thanks\n";
            break;
        }
    }
}