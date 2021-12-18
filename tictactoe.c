#include"stdio.h"
#include"conio.h"
#include"windows.h"

int row,col;
int m,n,turn=2,space=0;
int win=0,draw=0;
char *mark[3][3];
char placemark;
const char player1[10],player2[10];

//---> filling blank spaces in global pointer array i.e mark[][] <----//
void fillvoid()
{
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            mark[row][col]=" ";
        }
    }
}

//------------------> Player Information <----------------------------//
void playerinfo()
{
    printf("\nEnter the Player-1 name: ");
    scanf(" %s",&player1);
    printf("Enter the Player-2 name: ");
    scanf(" %s",&player2);
    system("cls");
}
//-----------> welcome Page and rules of game <-----------------------//
void welpage()
{
    char play;
    printf("\t\tWelcome to TicTacToe Game");
    printf("\n\t\t\t--Rules--");
    printf("\n-> Player-1 having mark 'X' and Player-2 having mark 'O'");
    printf("\n-> Both the Player have to fill the mark according to given sample.");
    printf("\n-> If the adjacent three mark same(diagonally or parallelly) then that player win.");
    printf("\n-> If no such condition occurred then the match draw between the players");
    printf("\n\nPress any key to start the game......... ");
    getch();
    system("cls");//this line clear the screen......
}
//--------------> loading page <-----------------------//
void coordinate(int x,int y)
{
    COORD position;

    position.X=x;
    position.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}
void loading()
{
    int i,z;

    coordinate(23,10);
    printf("loading....");

    coordinate(18,11);
    for(i=1;i<=20;i++)
    {
        for(z=0;z<=100000000;z++);    //to display the character slowly
        printf("%c",177);
    }
    getch();
    system("cls");

}
//------------------> sample board <------------------------//
void sample()
{
    printf("\n 7 | 8 | 9");
    printf("\n --  --  --");
    printf("\n 4 | 5 | 6");
    printf("\n --  --  --");
    printf("\n 1 | 2 | 3\n");
}
//-------------------> play board <------------------------//
void playboard()
{
    printf("\n");
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if((col+1)%3==0)
                printf(" %s ",mark[row][col]);
            else
                printf(" %s |",mark[row][col]);
        }
        printf("\n");
        if(row<2)
        {
            for(col=0;col<3;col++)
                printf(" -- ");
        }
        printf("\n");
    }
}
//-------------------> Placing Mark(X/O) <---------------------//
void m_n()
{
    if(placemark=='7')
        {m=0;n=0;}
    else if(placemark=='8')
        {m=0;n=1;}
    else if(placemark=='9')
        {m=0;n=2;}
    else if(placemark=='4')
        {m=1;n=0;}
    else if(placemark=='5')
        {m=1;n=1;}
    else if(placemark=='6')
        {m=1;n=2;}
    else if(placemark=='1')
        {m=2;n=0;}
    else if(placemark=='2')
        {m=2;n=1;}
    else if(placemark=='3')
        {m=2;n=2;}
    else
        {n=9;}
}
void placing()
{
    if(turn%2==0)
        printf("%s, It's your turn mark('X')...",player1);
    else
        printf("%s, It's your turn mark('O')...",player2);
    printf("\n\n-----> According to sample <-----");
    printf("\nEnter the number to place the mark: ");
    scanf(" %s",&placemark);

    m_n();

    if(n!=9 && mark[m][n]==" ")
    {
        if (turn%2==0)
            mark[m][n]="X";
        else
            mark[m][n]="O";
        turn++;
    }

}
//--------------------> Analyzing <---------------------------//

void analyzing()
{
    if (mark[0][0]==mark[1][1] && mark[0][0]==mark[2][2] && mark[0][0]!=" ")
        win++;
    else if (mark[0][2]==mark[1][1] && mark[0][2]==mark[2][0] && mark[0][2]!=" ")
        win++;
    else if (mark[0][0]==mark[1][0] && mark[0][0]==mark[2][0] && mark[0][0]!=" ")
        win++;
    else if (mark[0][1]==mark[1][1] && mark[0][1]==mark[2][1] && mark[0][1]!=" ")
        win++;
    else if (mark[0][2]==mark[1][2] && mark[0][2]==mark[2][2] && mark[0][2]!=" ")
        win++;
    else if (mark[0][0]==mark[0][1] && mark[0][0]==mark[0][2] && mark[0][0]!=" ")
        win++;
    else if (mark[1][0]==mark[1][1] && mark[1][0]==mark[1][2] && mark[1][0]!=" ")
        win++;
    else if (mark[2][0]==mark[2][1] && mark[2][0]==mark[2][2] && mark[2][0]!=" ")
        win++;
}
void checkspace()
{
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            if(mark[row][col]==" ")
                space++;
        }
    }
}
/////////////////////-----> Main Function <------/////////////////////////
void main()
{
    welpage();
    loading();
    playerinfo();
    fillvoid();

    while(1)
    {
        sample();
        playboard();
        placing();
        analyzing();
        if(win==0)
        {
            checkspace();
            if(space==0)
            {
                draw++;
                break;
            }
            space=0;
        }
        else
            break;
        system("cls");
    }

    system("cls");
    playboard();

    if((turn-1)%2==0 && win!=0)
        printf(" %s, You win!\n",player1);
    else if((turn-1)%2!=0 && win!=0)
        printf(" %s, You win!\n",player2);
    else if(draw!=0)
        printf(" Draw match!\n");

//----------------- check for play again or not --------------------//
    char again;

    printf("\n\tdo you want to play again??");
    printf("\npress 'y' or 'Y' for continue or any key to exist...... ");
    scanf(" %s",&again);

    if(again=='y' || again=='Y')
    {
        system("cls");
        win=0;
        draw=0;
        main();
    }
}


