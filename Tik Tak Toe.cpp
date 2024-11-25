#include<iostream>

using namespace std;

//Its a 2 player Tic tac toe game and its good in Console.......Plz run it in console or terminux.....if you like plz leave a like🙏🙏

char  board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char mark;

int player;

char commar;

int com;

void draw(){

    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" | "<<endl;

    cout<<"------------\n";

    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" | "<<endl;

    cout<<"------------\n";

    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" | "<<endl;

    cout<<"------------\n";

}

void place(char slot){

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            if(board[i][j]==slot){

                board[i][j]=mark;

            }

        }

    }

}

int winner(){

    for(int i=0;i<3;i++){

        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){

            return player;

        }

        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){

            return player;

        }

    }

    if((board[0][0]==board[1][1]&&board[1][1]==board[2][2])||(board[0][2]==board[1][1]&&board[1][1]==board[2][0])){

        return player;

    }

    return 0;

}

void masel(){

    if(mark=='X'){

        mark='O';

    }

    else{

        mark='X';

    }

    if(player==1){

        player=2;

    }

    else{

        player=1;

    }

}

void game(){

    cout<<"Enter the marker of yours: ";

    cin>>mark;

    player=1;

    draw();

    int won;

    for(int i=0;i<9;i++){

        cout<<"Its player "<<player<<" Enter yout slot: ";

        char slot;

        cin>>slot;

        place(slot);

        draw();

        won=winner();

        if(won==1){

            cout<<"Player 1 won!"<<endl;

            exit(0);

        }

        else if(won==2){

            cout<<"player 2 won!"<<endl;

            exit(0);

        }

        masel();

    }

    if(won==0){

            cout<<"Its a draw!"<<endl;

        }

}

int main(){

    game();

}
