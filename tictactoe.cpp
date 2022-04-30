#include <bits/stdc++.h> 
using namespace std;
 
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int active_player;
char active_marker;

void printBoard(){
    cout<<"   "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<'\n';
    cout<<"---------------\n";
    cout<<"   "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<'\n';
    cout<<"---------------\n";
    cout<<"   "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<'\n';
    
} 
int r=0,c=0;
bool setMarker(int num){
     switch (num){
         case 1: r=0; c=0; break;
         case 2: r=0; c=1; break;
         case 3: r=0; c=2; break;
         case 4: r=1; c=0; break;
         case 5: r=1; c=1; break;
         case 6: r=1; c=2; break;
         case 7: r=2; c=0; break;
         case 8: r=2; c=1; break;
         case 9: r=2; c=2; break;
         default: cout<<"Invalid number. Enter again!\n";

     }
     if(board[r][c] != 'X' && board[r][c] != 'O')
     {
         board[r][c]=active_marker;
         return true;
     }
     else return false;
}

int checkWinner(){
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) return active_player;
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) return active_player;
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) return active_player;
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) return active_player;
    return 0;
}

void turn(){
    if(active_marker == 'X') active_marker = 'O';
    else active_marker = 'X';
    if(active_player == 1) active_player = 2;
    else active_player = 1;
}

void startGame(){
    label_1:
    cout<<"Player 1, choose your marker : X or O\n";

    char m;
    cin>>m;
    if(m != 'X' && m != 'O'){
        goto label_1;
    }
    active_player =1;
    active_marker= m;
    printBoard();

    int winner;

    for(int i=0; i<9; i++){
        cout<<"It's player "<<active_player<<"'s turn. Enter number : ";
        int num; cin>>num;
        if(num<1 || num>9 || !setMarker(num)){
            cout<<"Invalid number. Enter again!\n";
            i--;
            continue;
        }

        printBoard();
        winner=checkWinner();
        if(winner ==1 ) {
            cout<< "Player 1 won! Congratulations!!";
            break;
        }
        else if(winner ==2 ) {
            cout<< "Player 2 won! Congratulations!!";
            break;
        }

        turn();
    }
    if(winner==0){
        cout<<"Tie game!\n";
    }

}


int main(){
    startGame();
    return 0;
}