#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>

void gotoligcol( int lig, int col )
{

COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
int main()
{
    int key;
    int x,y,dx,dy,xold,yold;
    srand(time(NULL));
    x=rand()%41;
    y=rand()%41;
    dx=1;
    dy=0;
   do{
        gotoligcol(0, 50);
        printf("x=%d", x);
        gotoligcol(1, 50);
        printf("y=%d", y);
        xold=x;
        yold=y;

        x+=dx;
        if(x>40) x=0;
        if(x<0) x=40;
        y+=dy;
        if(y>40) y=0;
        if(y<0) y=40;

        gotoligcol(yold,xold);
        printf(" ");

        gotoligcol(y,x);
        printf("X");
        Sleep(50);

        if(kbhit()){
                key=getch();
                switch(key){
                    case 75 :dx=-1;dy=0;
                               break;
                    case 77 :dx=1;dy=0;
                               break;

                    case 72 :dx=0;dy=-1;
                               break;
                    case 80 :dx=0;dy=1;
                               break;
                }
        }
   }while(key!='q');
    return 0;
}
