// Author : abdelrhman
#include <bits/stdc++.h>
#include <windows.h> // to color compilare
using namespace std;
class Game
{
private:
   char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    string p1;
    string p2;
    char c1;
    map<int, string >m{{1, " "}, {2, " "}, {3, " "}, {4, " "},
    {5, " "}, {6, " "}, {7, " "}, {8, " "}, {9, " "}};
    char c2;
   int counter = 0;
    int flag = -1;
    string nameP1;
    string nameP2;


public:
    Game(){};
    void update();
    void define();
    void firstPlayer();
    void secondPlayer();
    int checkWinner();
    void setTextColor(int n);
    void run();

};

void Game::define(){
    string c;
    cout << "\n<<<Please, Player One Enter your name : \n>>>";
    cin >> nameP1;
    while(true){
        cout << "\n<<<Plesae, Enter the character(X | O)(Captial letter) that you want to play with it : \n>>>";
        cin >> c;
        if(c.size() == 1){
            c1 = (char)toupper(c[0]);
            if((c1 == 'X' || c1 == 'O'))
            {
                if(c1 == 'X')c2 = 'O';
                else c2 = 'X';
                break;
            }
            else {
                cout << "\n\t\t\t**** This Input Invaild -> please " << nameP1 << " Try again! ****\n";
                continue;
            }
        }else{
            cout << "\n\t\t\t**** This Input Invaild -> please " << nameP1 << " Try again! ****\n";
            continue;
        }
    }
    cout << "\n<<<Please, Player Two Enter your name : \n>>>";
    cin >> nameP2;
    //cout << "\n\t\t\t**** " << nameP2 << " you can play with character " << c2 << " for finishing game ****" << endl;
}
void Game::update()
{
    setTextColor(2);
    cout << "\n\n\t " << nameP1 << " ---> " << c1
        << "\n\t " << nameP2 << " ---> " << c2 << "\n\n";
    setTextColor(6);
        cout << "\t\t----------------\n";
        cout << "\t\t|    |    |    |\n";
        cout << "\t\t|  " << board[0][0] << " |  " << board[0][1] << " |  " << board[0][2] << " |\n";
        cout << "\t\t ____|____|____|\n";
        cout << "\t\t|    |    |    |\n";
        cout << "\t\t|  " << board[1][0] << " |  " << board[1][1] << " |  " << board[1][2] << " |\n";
        cout << "\t\t ____|____|____\n";
        cout << "\t\t|    |    |    |\n";
        cout << "\t\t|  " << board[2][0] << " |  " << board[2][1] << " |  " << board[2][2] << " |\n";
        cout << "\t\t|    |    |    |\n";
        cout << "\t\t----------------\n";
    setTextColor(7);
}


void Game::firstPlayer()
{
    while (true){
        string c;
        cout << "\n>>>Please, "<< nameP1 << " Enter the position you want to play in it : \n>>>";
        cin >> c;
        if(c.size() > 1 || !isdigit(c[0])){
            cout << "\n\t\t\t**** This place Invaild -> please " << nameP1 << " Try again! ****\n";
            continue;
        }
        int Player1 = stoi(c);
        cout << "Player1: " << Player1 << endl;
        if (board[(Player1 / 3)][Player1 % 3 - 1] != 'X' && board[(Player1 / 3)][Player1 % 3 - 1] != 'O' && m[Player1] == " ")
        {
            m[Player1] = "xo";
            board[(Player1 / 3)][Player1 % 3 - 1] = c1;
            counter++;
            break;
        }
        else
        {
            cout << "\n\t\t\t**** This place filled -> please " << nameP1 << " Try again! ****\n";
            continue;
        }
    }
}
void Game::secondPlayer()
{
   while (true)
   {
        string c;
        cout << "\n>>>Please, "<< nameP2 << " Enter the position you want to play in it : \n>>>";
        cin >> c;
        if(c.size() > 1 || !isdigit(c[0])){
            cout << "\n\t\t\t**** This place Invaild -> please " << nameP2 << " Try again! ****\n";
            continue;
        }
        int Player2 = stoi(c);
        if (board[(Player2 / 3)][Player2 % 3 - 1] != 'X' && board[(Player2 / 3)][Player2 % 3 - 1] != 'O' && m[Player2] == " ")
        {
            m[Player2] = "xo";
            board[(Player2 / 3)][Player2 % 3 - 1] = c2;
            counter++;
            break;
        }
        else
        {
            cout << "\n\t\t\t**** This place filled -> please " << nameP2 << " Try again! ****\n";
            continue;
        }
   }
   
}
int Game::checkWinner()
{
    if((board[0][0] == c1 && board[0][1] == c1 && board[0][2] == c1)||
        (board[1][0] == c1 && board[1][1] == c1 && board[1][2] == c1)||
        (board[2][0] == c1 && board[2][1] == c1 && board[2][2] == c1)||
        (board[0][0] == c1 && board[1][0] == c1 && board[2][0] == c1)||
        (board[0][1] == c1 && board[1][1] == c1 && board[2][1] == c1)||
        (board[0][2] == c1 && board[1][2] == c1 && board[2][2] == c1)||
        (board[0][0] == c1 && board[1][1] == c1 && board[2][2] == c1)||
        (board[0][2] == c1 && board[1][1] == c1 && board[2][0] == c1)){return 0;cout << "adf" << endl;}
        if ((board[0][0] == c2 && board[0][1] == c2 && board[0][2] == c2)||
        (board[1][0] == c2 && board[1][1] == c2 && board[1][2] == c2)||
        (board[2][0] == c2 && board[2][1] == c2 && board[2][2] == c2)||
        (board[0][0] == c2 && board[1][0] == c2 && board[2][0] == c2)||
        (board[0][1] == c2 && board[1][1] == c2 && board[2][1] == c2)||
        (board[0][2] == c2 && board[1][2] == c2 && board[2][2] == c2)||
        (board[0][0] == c2 && board[1][1] == c2 && board[2][2] == c2)||
        (board[0][2] == c2 && board[1][1] == c2 && board[2][0] == c2)){return 1;cout << "adf 2" << endl;}
        return -1;
}
void Game::setTextColor(int n)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, n);
}
void Game::run(){
    define();
    Sleep(3000);
    system("cls");
    update();
    while(true){
        firstPlayer();
        update();

        if(checkWinner() == 0){cout << "\n\t\t\t*** The Winner is -> " << nameP1 << " ***" << endl;break;}
         if(counter >= 9){
            cout << "\n\t\t\t***** The game ended in a draw *****\n";
            return;
        }
        Sleep(2500);
        system("cls");
        update();
        secondPlayer();
        update();
        if(checkWinner() == 1){cout << "\n\t\t\t*** The Winner is -> " << nameP2 << " ***" << endl;break;}
        if(counter >= 9){
            cout << "\n\t\t\t***** The game ended in a draw *****\n";
            return;
        }
        Sleep(2500);
        system("cls");
    update();
    }

}
int main()
{
     system("cls");
    cout << "\n\n                                <<-------WELCOME USER IN THIS GAME------->>\n" << endl;
    cout << "\n                                         ***** Tic Tac Toe Game *****\n" << endl;
    Game g;
    g.run();
}
