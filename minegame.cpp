   #include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

void initboard(char t[][10]) // intialize the board
{

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            t[i][j] = 'B';
        }
    }
}

void printboard(char y[][10]) // print the board
{

    cout << setw(32);

    for (int j = 0; j <= 9; j++)
    {
        cout << j << "  ";
    }
    cout << endl
         << setw(32);
    for (int i = 0; i < 25; i++)
    {
        cout << "_";
    }

    cout << endl;

    for (int i = 0; i <= 9; i++)
    {

        cout << setw(30) << i << "|";
        for (int j = 0; j <= 9; j++)
        {
            cout << y[i][j] << "  ";
        }
        cout << "|" << endl;
    }
}

void initrealboard(char y[][10]) // intialized the realboard
{

    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            y[i][j] = '0';
        }
    }
}

void one(int x, int y, char arr[][10]) // To print the number on realboard
{
    if (arr[x][y] != 'X')
    {

        arr[x][y] = arr[x][y] + 1;
    }
}

void minegenerator(char t[][10]) // To generate the mine
{
    int counter = 0, y = 0;
    int a, b, arr[20];
    int p = 0;
    for (int i = 0; i < 20; i++)
    {
        arr[i] = 19;
    }

    srand(time(0));
    while (counter <= 9 && y < 20)
    {

    start:
        a = (rand() % 10);
        b = (rand() % 10);
        if (p > 0)
        {
            for (int i = 0; i < 20; i += 2)
            {
                if (a == arr[i] && b == arr[i + 2])
                {
                    goto start;
                }
            }
        }
        arr[y] = a;
        arr[y + 1] = b;

        t[a][b] = 'X';

        one(a - 1, b - 1, t);
        one(a - 1, b, t);
        one(a - 1, b + 1, t);
        one(a, b + 1, t);
        one(a + 1, b + 1, t);
        one(a + 1, b, t);
        one(a + 1, b - 1, t);
        one(a, b - 1, t);

        counter++;
        y += 2;
    }
}

void revealwhen0(int x, int y, char rea[][10], char disp[][10]) // On the input reveal the number
{
    if (rea[x][y] != '0' && rea[x][y] != 'X' && disp[x][y] == 'B' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
    {
        disp[x][y] = rea[x][y];
    }
    if (rea[x][y] == '0' && disp[x][y] == 'B' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
    {
        disp[x][y] = '-';
        revealwhen0(x - 1, y - 1, rea, disp);
        revealwhen0(x - 1, y, rea, disp);
        revealwhen0(x - 1, y + 1, rea, disp);
        revealwhen0(x, y + 1, rea, disp);
        revealwhen0(x + 1, y + 1, rea, disp);
        revealwhen0(x + 1, y, rea, disp);
        revealwhen0(x + 1, y - 1, rea, disp);
        revealwhen0(x, y - 1, rea, disp);
    }
}

void flag(int x, int y, char rea[][10], char disp[][10])
{
str:
    cout << "ENTER A ROW & COLLUM" << endl;
    cin >> x >> y;

    if (x < 0 || y < 0 || x > 9 || y > 9)
    {
        cout << "ENTER VALID LOCATION !!" << endl;
        goto str;
    }
    else
    {

        if (disp[x][y] == 'B' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
        {
            disp[x][y] = '*';
        }
        else
        {
            if (disp[x][y] != 'B' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
            {

                cout << "THIS BOX IS ALEADY FLAGGED !!" << endl;
                goto str;
            }
        }
    }

   
}

void unflag(int x, int y, char rea[][10], char disp[][10])
{
str:
    cout << "ENTER A ROW & COLLUM" << endl;
    cin >> x >> y;

    if (x < 0 || y < 0 || x > 9 || y > 9)
    {
        cout << "ENTER VALID LOCATION !!" << endl;
        goto str;
    }
    else
    {

        if (disp[x][y] == '*' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
        {
            disp[x][y] = 'B';
        }
        else
        {
            if (disp[x][y] != '*' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
            {

                cout << "THIS BOX IS ALEADY UNFLAGGED !!" << endl;
                goto str;
            }
        }
    }
}

void openbox(int x, int y, char rea[][10], char disp[][10]) // To enter the move to openbox
{
str:
    cout << "ENTER A ROW & COLLUM";
    cin >> x >> y;
    if (rea[x][y] != '0' && rea[x][y] != 'X' && disp[x][y] != '*' && disp[x][y] == 'B' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
    {
        disp[x][y] = rea[x][y];
    }
    else
    {
        if (rea[x][y] == '0' && disp[x][y] == 'B' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
        {
            revealwhen0(x, y, rea, disp);
        }
        else
        {

            if (rea[x][y] == 'X' && disp[x][y] == 'B' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
            {

                cout << "YOU HIT THE MINE" << endl
                     << "YOU LOSS THE GAME" << endl;
                exit(0);
            }
            else
            {

                if (disp[x][y] != 'B' && disp[x][y] != '*' && x >= 0 && y >= 0 && x <= 9 && y <= 9)
                {
                    cout << "THE BOX IS ALREADY OPEN !!" << endl;
                    goto str;
                }
                else
                {
                    if (x < 0 || y < 0 || x > 9 || y > 9)
                    {
                        cout << "ENTER VALID LOCATION !!" << endl;
                        goto str;
                    }
                }
            }
        }
    }
}

void player_input(int x, int y, char rea[][10], char disp[][10]) // Get the input from the user
{
    int choice;
    cout << "ENTER 1 FOR OPENBOX " << endl
         << "ENTER 2 FOR FLAG THE BOX" << endl
         << "ENTER 3 FOR UNFLAG THE BOX" << endl;
    cout << "ENTER YOUR CHOICE : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        openbox(x, y, rea, disp);
        break;

    case 2:
        flag(x, y, rea, disp);
        break;

    case 3:
        unflag(x, y, rea, disp);
        break;
    }
}

int main()
{
    char board[10][10];
    char realboard[10][10];
    int xaxis, yaxis;
    initrealboard(realboard);
    minegenerator(realboard);
    initboard(board);
    while (true)
    {
        printboard(realboard);
        printboard(board);
        player_input(xaxis, yaxis, realboard, board);
    }

    return 0;
}