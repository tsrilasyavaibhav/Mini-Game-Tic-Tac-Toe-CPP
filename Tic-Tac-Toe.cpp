#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard()
{
    char ch = '1';

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=ch++;
        }
    }
}

void displayBoard()
{
    cout<<"\n";

    for(int i=0;i<3;i++)
    {
        cout<<" ";

        for(int j=0;j<3;j++)
        {
            cout<<board[i][j];

            if(j<2)
                cout<<" | ";
        }

        cout<<"\n";

        if(i<2)
            cout<<"-----------\n";
    }

    cout<<"\n";
}

bool placeMark(int choice,char mark)
{
    if(choice<1 || choice>9)
        return false;

    int row=(choice-1)/3;
    int col=(choice-1)%3;

    if(board[row][col]=='X' || board[row][col]=='O')
        return false;

    board[row][col]=mark;

    return true;
}

bool checkWin()
{
    // Rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] &&
           board[i][1]==board[i][2])
            return true;
    }

    // Columns
    for(int i=0;i<3;i++)
    {
        if(board[0][i]==board[1][i] &&
           board[1][i]==board[2][i])
            return true;
    }

    // Diagonal
    if(board[0][0]==board[1][1] &&
       board[1][1]==board[2][2])
        return true;

    if(board[0][2]==board[1][1] &&
       board[1][1]==board[2][0])
        return true;

    return false;
}

bool checkDraw()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X' && board[i][j]!='O')
                return false;
        }
    }

    return true;
}

int main()
{
    char playAgain='Y';

    while(playAgain=='Y' || playAgain=='y')
    {
        initializeBoard();

        char currentPlayer='X';

        while(true)
        {
            displayBoard();

            int choice;

            cout<<"Player "<<currentPlayer<<" enter position (1-9): ";
            cin>>choice;

            if(!placeMark(choice,currentPlayer))
            {
                cout<<"Invalid Move! Try Again.\n";
                continue;
            }

            if(checkWin())
            {
                displayBoard();
                cout<<"Player "<<currentPlayer<<" Wins!\n";
                break;
            }

            if(checkDraw())
            {
                displayBoard();
                cout<<"Match Draw!\n";
                break;
            }

            if(currentPlayer=='X')
                currentPlayer='O';
            else
                currentPlayer='X';
        }

        cout<<"\nPlay Again? (Y/N): ";
        cin>>playAgain;
    }

    cout<<"\nThanks for playing!\n";

    return 0;
}