#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};      //Position of the Empty Spaces
int row;
int column;
char token='x';
bool tie=false;
string n1="";//Input the name of players
string n2="";

void functionone()
{

    //CreateStructure of tic-tak-toe

    cout<<"   |     |   \n";
    cout<<" "<<space[0][0]<<" |  "<<space[0][1]<<"  | "<<space[0][2]<<" \n";        //Adding elements to these Empty Spaces
    cout<<"___|_____|___\n";
    cout<<"   |     |   \n";
    cout<<" "<<space[1][0]<<" |  "<<space[1][1]<<"  | "<<space[1][2]<<" \n";
    cout<<"___|_____|___\n";
    cout<<"   |     |   \n";
    cout<<" "<<space[2][0]<<" |  "<<space[2][1]<<"  | "<<space[2][2]<<" \n";
    cout<<"   |     |   \n"; 
}

void functiontwo()
{
    int digit;

    if(token=='x')
    {
        cout<<n1<<" please enter ";
        cin>>digit; 
    }

    if(token=='0')
    {
        cout<<n2<<" please enter ";
        cin>>digit; 
    }

    if(digit==1)
    {
        row=0;
        column=0;
    }
    if(digit==2)
    {
        row=0;
        column=1;
    }
    if(digit==3)
    {
        row=0;
        column=2;
    }
    if(digit==4)
    {
        row=1;
        column=0;
    }
    if(digit==5)
    {
        row=1;
        column=1;
    }
    if(digit==6)
    {
        row=1;
        column=2;
    }
    if(digit==7)
    {
        row=2;
        column=0;
    }
    if(digit==8)
    {
        row=2;
        column=1;
    }
    if(digit==9)
    {
        row=2;
        column=2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid !!!"<<endl;
    }

    if(token=='x' && space[row][column] !='x' && space[row][column] !='0')
    {
        space[row][column]='x';
        token='0';                  //Players 2 value is assigned
    }
    else if(token=='0' && space[row][column] !='x' && space[row][column] !='0')
    {
        space[row][column]='0';
        token='x';
    }
    else                             //In else we have to call the function again so that we can play again whenthere is no empty space
    {
        cout<<" There is no. Empty Space! "<<endl;
        functiontwo();
    }

    functionone();
}
bool functionthree()                  //of boolean type beacuse we have to return only true and false
{
        //If (pair of 3) matches the particular person wins
    for(int i=0;i<3;i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])        //checking horizontally or checking vertially
        {
            return true;
        }
    }
        //now we will check for diagonal element
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
        {
            return true;
        }
    for(int i=0;i<3;i++)        //If any position is not filled game is still going on
    {                           //beacuse will still be going till every positionis not filled
        for(int j=0;j<3;j++)
        {
            if(space[i][j] != 'x' && space[i][j] != '0')
            {
                return false;
            }
        }
    }
   //Condition to check if the game is Draw 
   tie=true;
   return false;
}

int main()
{
    cout<<"Enter the Name of the First Player"<<endl;
    getline(cin,n1);
    cout<<endl<<"Enter the Name of the Second Player"<<endl;
    getline(cin,n2);
    cout<<endl;
    cout<<n1<<" is the player1 so he/she will play First\n";
    cout<<n2<<" is the player2 so he/she will play Second\n";
    


    //Now we have to call these 3 Functions One by One
    while(!functionthree())     //Keep on Iterating till function 3 return false
    {
        functionone();
        functiontwo();
        functionthree();
    }
    if(token=='x' && tie== false)             // Means last turn was of player 2 and the game was not tie and is Ended
    {
        cout<<n2<<" Wins!!"<<endl;
    }
    else if(token=='0' && tie== false)
    {
        cout<<n1<<" Wins!!"<<endl;
    }
    else                                     //Execute if Game is Draw
    {
        cout<<"It's a draw!"<<endl;
    }
}