#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn ='X';
bool draw =false;
void display()
{
    system("cls");  
    cout<<"\ttic tak toe game "<<endl; 
    cout<<"\tPlayer1[x]\n\t Player2[0]"<<endl;
    cout<<"\t\t    |    |    \n";
    cout<<"\t\t "<<board[0][0]<<"  | "<<board[0][1]<<"  | "<<board[0][2]<<"  \n";
    cout<<"\t\t____|____|____\n";
    cout<<"\t\t    |    |    \n";
    cout<<"\t\t "<<board[1][0]<<"  | "<<board[1][1]<<"  | "<<board[1][2]<<"  \n";
    cout<<"\t\t____|____|____\n";
    cout<<"\t\t    |    |    \n";
    cout<<"\t\t "<<board[2][0]<<"  | "<<board[2][1]<<"  | "<<board[2][2]<<"  \n";
    cout<<"\t\t    |    |    \n"; 
}
void player_turn()
{
    int choice;
    if(turn=='X')
cout<<"\nPlayer1 [x] turn:";
if(turn =='O')
cout<<"\nPlayer2 [0] turn:";
    cin>>choice;
    int row,col;
    switch(choice){
        case 1:
        row=0;
        col=0;
        break;
        case 2:
        row=0;
        col=1;
        break;
        case 3:
        row=0;
        col=2;
        break;
        case 4:
        row=1;
        col=0;
        break;
        case 5:
        row=1;
        col=1;
        break;
        case 6:
        row=1;
        col=2;
        break;
        case 7:
        row=2;
        col=0;
        break;
        case 8:
        row=2;
        col=1;
        break;
        case 9:
        row=2;
        col=2;
        break;
        cout<<"Invalid choice"<<endl;
        break;
    }
    if(turn=='X')
cout<<"\nPlayer1 [x] turn:";
if(turn =='O')
cout<<"\nPlayer2 [0] turn:";
    if(turn=='0'&&board[row][col]!='X'&&board[row][col]!='0' )
    {
        board[row][col]='0';
        turn ='X';
    }
    else if(turn =='X'&&board[row][col]!='X'&&board[row][col]!='0')
    {
        board[row][col]='X';
        turn='0';
    }
    else{
        cout<<"box is filled\n Please try again!!!\n";
        player_turn();
    }
    display();
}
bool game_over()
{
 for(int i=0;i<3;i++)
 {
    if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] || board[0][i]==board[1][i]&&board[0][i]==board[2][i])
    return false;
 }
 if(board[0][0]==board[1][1]&&board[0][0]==board[2][2] || board[0][2]==board[1][1]&&board[0][0]==board[2][0])
 return false;
 for(int i=0;i<3;i++)
 {
     for(int j=0;j<3;j++)
     {
         if(board[i][j]!='X'&&board[i][j]!='0')
         return true;
     }
 }
 draw=true;
 return false;
}
int main()
{
    while(game_over()){
    display();
    player_turn();
    game_over();
    }
    if(turn =='X'&&draw==false)
    cout<<"Player 2 WIN"<<endl;
    else if(turn=='0'&&draw==false)
    cout<<"Player 1 WIN"<<endl;
    else{
        cout<<"Game Draw"<<endl;
    }
}