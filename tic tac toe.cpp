```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char b[9] = {'1','2','3','4','5','6','7','8','9'};

void board();
bool winner();
bool draw();
void clearScreen();

int main()
{
    char again;
    srand(time(0));
    int choice;

    do
    {
        for(int i = 0; i < 9; i++)
            b[i] = '1' + i;

        clearScreen();

        cout << "===========================================" << endl;
        cout << "        ULTIMATE TIC TAC TOE ARENA         " << endl;
        cout << "===========================================" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Computer" << endl;
        cout << "3. Exit" << endl;
        cout << "===========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 3)
        {
            cout << "Thanks for Playing!" << endl;
            return 0;
        }
        else if(choice != 1 && choice != 2)
        {
            cout << "Invalid Choice!" << endl;
            return 0;
        }

        int pos;
        char turn = 'X';

        board();

        while(true)
        {
            if(choice == 1)
            {
                cout << "Player " << turn << "'s turn." << endl;
                cout << "Enter position (1-9): ";
                cin >> pos;
            }
            else
            {
                if(turn == 'X')
                {
                    cout << "Player (X)'s turn." << endl;
                    cout << "Enter position (1-9): ";
                    cin >> pos;
                }
                else
                {
                    cout << "Computer Turn..." << endl;

                    do
                    {
                        pos = rand() % 9 + 1;
                    }
                    while(b[pos-1] == 'X' || b[pos-1] == 'O');

                    cout << "Computer chose position: " << pos << endl;
                }
            }

            if(pos < 1 || pos > 9)
            {
                cout << "Invalid Position! Choose between 1 and 9.\n" << endl;
                continue;
            }

            if(b[pos-1] == 'X' || b[pos-1] == 'O')
            {
                cout << "Position already taken! Try Again.\n" << endl;
                continue;
            }

            b[pos-1] = turn;

            board();

            if(winner())
            {
                if(choice == 2 && turn == 'O')
                    cout << "Computer Wins! Better luck next time." << endl;
                else
                    cout << "Player " << turn << " Wins!" << endl;

                break;
            }

            if(draw())
            {
                cout << "Match Draw!" << endl;
                break;
            }

            if(turn == 'X')
                turn = 'O';
            else
                turn = 'X';
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;

    } while(again == 'Y' || again == 'y');

    cout << "\nThanks for Playing!" << endl;

    return 0;
}

void clearScreen()
{
    system("cls");
}

void board()
{
    clearScreen();

    cout << "=========== TIC TAC TOE ===========" << endl;
    cout << "\n     |     |     \n";
    cout << "  " << b[0] << "  |  " << b[1] << "  |  " << b[2] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << b[3] << "  |  " << b[4] << "  |  " << b[5] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << b[6] << "  |  " << b[7] << "  |  " << b[8] << " \n";
    cout << "     |     |     \n\n";
}

bool winner()
{
    if(b[0] == b[1] && b[1] == b[2]) return true;
    if(b[3] == b[4] && b[4] == b[5]) return true;
    if(b[6] == b[7] && b[7] == b[8]) return true;

    if(b[0] == b[3] && b[3] == b[6]) return true;
    if(b[1] == b[4] && b[4] == b[7]) return true;
    if(b[2] == b[5] && b[5] == b[8]) return true;

    if(b[0] == b[4] && b[4] == b[8]) return true;
    if(b[2] == b[4] && b[4] == b[6]) return true;

    return false;
}

bool draw()
{
    for(int i = 0; i < 9; i++)
    {
        if(b[i] >= '1' && b[i] <= '9')
            return false;
    }

    return true;
}
```