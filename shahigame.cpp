#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
#include<windows.h>

using namespace std ;
int height=30,width=50;
int x=23,y=28,fx=x,fy=y;
int count2;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};
direction DIR;


void draw()
{   int count1=0;
    for(int i=0;i<height;i++)
    {   gotoxy(15,10+i);
        for(int j=0;j<width;j++)
        {
           if(i==0||i==height-1)
              printf("O");
           else if(j==0||j==width-1)
           { printf("O");

           }


           else if(x==j&&y==i)
           {
              printf("=%c=",char(202));

           }

 else if(fx==j&&fy==i)
           {  if(i!=height-2)
              printf("*");

           }

           else
        {     if(i==height-2&&count1<=1)
                      count1++;
                else
                    printf(" ");

           }


        }

        printf("\n");
    }

}




void input()
{
  if(_kbhit())
     {

     switch(_getch())
     {
case 'a':
      case 'A':DIR=LEFT;
             break;
      case 's':
      case 'S':DIR=RIGHT;
             break;

      case 'w':
        case 'W':DIR=UP;
               break;


//case 'T':gamestatus=true;
     }


     }

}
void logic()
{
  switch(DIR)
 {

   case LEFT:x--;break;
   case RIGHT:x++;break;
    default:break;

 }
    if(x<=1)
        x=1;
    if(x>=width-1)
        x=width-2;
}


void shoot()
{
 switch(DIR)
    {
        case UP:if(count2==0)
              { Sleep(1000);
                  fx=x;
                  fy--;
                  count2++;

                 }

   //case DOWN:y++;break;
   default :if(count2!=0)
              { printf("m working");
                  fy--;
                count2++;
                  if(fy==0)
                     {count2=0;
                     fy=28;}
              }


            break;

}



}


int main()
{

int ch=1000;
//draw();
Sleep(1000);
while(ch)
    {
    draw();

input();
logic();
shoot();

shoot();

shoot();

logic();
input();
ch--;
    }










return 0 ;}
