#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void initializeBoard()
{
    char ch = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }

    currentPlayer = 'X';
}

void displayBoard()
{
    cout << "\n";

    for(int i = 0; i < 3; i++)
    {
        cout << " ";

        for(int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << "\n";

        if(i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

bool makeMove(int choice)
{
    char mark = choice + '0';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == mark)
            {
                board[i][j] = currentPlayer;
                return true;
            }
        }
    }

    return false;
}

bool checkWinner()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;

        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

bool isDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' &&
               board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main()
{
    char replay;

    do
    {
        initializeBoard();

        bool gameOver = false;

        while(!gameOver)
        {
            displayBoard();

            int choice;

            cout << "Player "
                 << currentPlayer
                 << ", Enter Position (1-9): ";

            cin >> choice;

            if(choice < 1 || choice > 9)
            {
                cout << "\nInvalid Position!\n";
                continue;
            }

            if(!makeMove(choice))
            {
                cout << "\nPosition Already Taken!\n";
                continue;
            }

            if(checkWinner())
            {
                displayBoard();

                cout << "Player "
                     << currentPlayer
                     << " Wins!\n";

                gameOver = true;
            }
            else if(isDraw())
            {
                displayBoard();

                cout << "Game Draw!\n";

                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> replay;

    } while(replay == 'Y' || replay == 'y');

    cout << "\nThank You For Playing!\n";

    return 0;
}