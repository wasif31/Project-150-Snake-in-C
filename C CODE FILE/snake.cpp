#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;


                        // Prototype of Functions:

void check();
void finish();
void win();
void welcomeArt();
void highscore();
                    //Declaration of GLOBAL VARIABLES.

int m[500],n[500],con=5,tim,score=0,d;
clock_t start,stop;



int  main()
{

    freopen("GameData.dat","r",stdin);
     cin >> d;
    int gd=DETECT,gm,maxx,maxy,x=13,y=14,p,q,spd=80;
    int startx = 13,starty=14;
    char ch;
    initgraph(&gd,&gm,"..\bgi");

    //This is the HOMWE page design:

    setcolor(CYAN);


    settextstyle(3,0,6);
    outtextxy(150,2,"SNAKE GAME");
    setcolor(3);

    settextstyle(3,0,1);
    outtextxy(20,80," Use Arrow Keys To Direct The Snake ");
    outtextxy(20,140," Avoid The Head Of Snake Not To Hit Any Part Of Snake");
    outtextxy(20,170," Pick The Beats Untill You Win The Game ");
    outtextxy(20,220," Press 'Esc' Anytime To Exit ");
    outtextxy(20,250," Press Any Key To Continue ");
    outtextxy(20,280," Collect 100 to WIN the Game ");

     welcomeArt();

    // Press any key without ESC to start the game:

    ch=getch();
    if(ch==27)
        exit(0);
    cleardevice();

    // Starting of Game Logic:

    maxx=getmaxx();
    maxy=getmaxy();
    p=rand() % maxx;
    int temp=p%13;
    p=p-temp;
    q=rand() % maxy;
    temp=q%14;
    q=q-temp;


    start=clock();
    int a=4,i=0,j,t;
    int bonus=400;
    bool isbonus = false;

    while(1)
    {



                       //Structure of Game Page:
       if(score >0 && score%4==0) isbonus = true;
 else{ bonus = 500;
 isbonus = false;
 }
 if(!isbonus || bonus == 0){
        setcolor(BLACK);
 outtextxy(250,10,"BONUS!!! 888");
 setcolor(RED);
        setfillstyle(SOLID_LINE,RED);
        rectangle(0,0,645,475);
 setcolor(GREEN);
 setfillstyle(SOLID_FILL,GREEN);
 circle(p,q,5); //x position,y position,size
 floodfill(p,q,GREEN);
 }
 else
 {
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,WHITE);
 circle(p,q,5);
 floodfill(p,q,WHITE);

 char spp[1000];
 setcolor(BLACK);
 sprintf(spp,"BONUS!!! %d",bonus);
 outtextxy(250,10,"BONUS!!! 888");
 setcolor(YELLOW);
 outtextxy(250,10,spp);
// clears

                        //Control KEY:
}
        if( kbhit() )
   {
     ch=getch(); if(ch==0) ch=getch();
     if(ch==72&& a!=2) a=1; //down
     if(ch==80&& a!=1) a=2; //up
     if(ch==75&& a!=4) a=3; //left
     if(ch==77&& a!=3) a=4; //right
      }
       else
     {
     if(ch==27 //escape
     ) break;

        }

        if(i<20)
        {
 		   m[i]=x;
 		   n[i]=y;
 		   i++;
        }

        if(i>19)
        {
            for(j=con-2;j>=0;j--)
            {
                m[j+1]=m[j];
                n[j+1]=n[j];
            }
		    m[0]=x;
		    n[0]=y;



                      // Game Interface Structure:

            setcolor(BLUE);
            setfillstyle(SOLID_FILL,WHITE);
            circle(m[0],n[0],8);
            floodfill(m[0],n[0],BLUE);
            setcolor(LIGHTBLUE);
		    for(j=1;j<con;j++)
            {
                setfillstyle(SOLID_FILL,BLACK);
                circle(m[j],n[j],5);
                floodfill(m[j],n[j],LIGHTBLUE);
            }
            delay(spd);

            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            //clearviewport();
            circle(m[0],n[0],8);
            floodfill(m[0],n[0],BLACK);

		   /*setcolor(RED);
		   setfillstyle(SOLID_FILL,BLACK);
		   //clearviewport();
		   circle(m[con-1],n[con-1],5);
		   floodfill(m[j],n[j],BLACK);*/
             clearviewport();
        }
        stop=clock();
        t=(stop-start)/CLK_TCK;
        settextstyle(3,0,3);
     setcolor(WHITE);
     char arr[1000];
     sprintf(arr,"HIGHSCORE %d",(int)d);
     outtextxy(430,00,arr);
     sprintf(arr,"SCORE %d",score);
     outtextxy(00,00,arr);
        tim=t;
        char arre[1000];
        sprintf(arre,"Time: %d sec.",tim);
        outtextxy(220,440,arre);
        check();
        if(x==p&&y==q){


            putch('\a');
        }
        if(x==p&&y==q)
        {
            setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLUE);
 circle(p,q,5);
 floodfill(p,q,BLACK);


    con++;score++;
    if(score%5==0 && score>0)score+=bonus;

		 		      if(con>490) win();
     p=rand()%maxx; temp=p%13;  p=p-temp;
     q=rand()%maxy; temp=q%14;   q=q-temp;
		 		    }
    if(a==1)  y =  y-14; if(y<0) { temp=maxy%14;y=maxy-temp;}
    if(a==2)  y =  y+14; if(y>maxy) y=0;
    if(a==3)  x =  x-13; if(x<0) { temp=maxx%13;x=maxx-temp;}
    if(a==4)  x =  x+13; if(x>maxx) x=0;
    if(a==0){  y = y+14 ;  x=x+13; }
    if(isbonus){
    if(bonus>0)
    bonus-=10;
    if(bonus==0){
         setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLUE);
 circle(p,q,15);
 floodfill(p,q,BLACK);
    }
    }
    if(spd <10) spd = 10;
		 }

 }


                      //CHECK FUNCTION:

void check()
{
    int a;
    for(a=1;a<con;a++)

    if(m[0]==m[a] && n[0]==n[a])
        finish();
    else
        continue;
   }

                      //GAME END FUNCTION:

void finish()

{

    freopen("GameData.dat","w",stdout);

    int j,i;
    setcolor(WHITE);
    for(i=0;i<5;i++)
    {
        //setbkcolor(GREEN);
        delay(500);
        cleardevice();
        delay(500);
        for(j=0;j<=con;j++)
        {
            setfillstyle(SOLID_FILL,RED);
            circle(m[j],n[j],5);
            floodfill(m[j],n[j],WHITE);
        }

    }

    clearviewport();
    setcolor(BLUE);
    settextstyle(0,0,1);
    outtextxy(110,20,":'######::::::'###::::'##::::'##:'########:\n");
	outtextxy(110,35,"'##... ##::::'## ##::: ###::'###: ##.....::\n");
	outtextxy(110,50," ##:::..::::'##:. ##:: ####'####: ##:::::::\n");
	outtextxy(110,65," ##::'####:'##:::. ##: ## ### ##: ######:::\n");
	outtextxy(110,80," ##::: ##:: #########: ##. #: ##: ##...::::\n");
	outtextxy(110,95," ##::: ##:: ##.... ##: ##:.:: ##: ##:::::::\n");
	outtextxy(110,110,". ######::: ##:::: ##: ##:::: ##: ########:\n");
	outtextxy(110,125,":......::::..:::::..::..:::::..::........::\n");
	outtextxy(110,150,":'#######::'##::::'##:'########:'########::'####:\n");
	outtextxy(110,165,"'##.... ##: ##:::: ##: ##.....:: ##.... ##: ####:\n");
	outtextxy(110,180," ##:::: ##: ##:::: ##: ##::::::: ##:::: ##: ####:\n");
	outtextxy(110,195," ##:::: ##: ##:::: ##: ######::: ########::: ##::\n");
	outtextxy(110,210," ##:::: ##:. ##:: ##:: ##...:::: ##.. ##::::..:::\n");
	outtextxy(110,225," ##:::: ##::. ## ##::: ##::::::: ##::. ##::'####:\n");
	outtextxy(110,240,". #######::::. ###:::: ########: ##:::. ##: ####:\n");
	outtextxy(110,255,":.......::::::...:::::........::..:::::..::....::\n");


    char arr[1000];
    sprintf(arr,"  YOUR SCORE: %d ",score);
    setcolor(RED);
    settextstyle(3,0,1);
    outtextxy(200,300,arr);
    char arre[1000];
    sprintf(arre,"     Time: %d sec.",tim);
    setcolor(RED);
    settextstyle(3,0,1);
    outtextxy(200,330,arre);
    setcolor(RED);
    settextstyle(3,0,1);
    outtextxy(400,440,"Press Any KEY to EXIT");
    setcolor(RED);
    settextstyle(3,0,1);
    outtextxy(15,440,"Game Modded by WASIF & RAFA");
    getch();
    if(d < score)
    cout << score << endl;
    else cout << d << endl;
    exit(0);
}

                        //WIN FUNCTION:

void win()
{
    int j,i;
    setcolor(WHITE);
    for(i=0;i<5;i++)
    {
        for(j=0;j<=con;j++)
        {
            setfillstyle(SOLID_FILL,WHITE);
            circle(m[j],n[j],5);
            floodfill(m[j],n[j],WHITE);
        }
        delay(500);
        cleardevice();
        delay(500);
    }
    setcolor(LIGHTBLUE);

    settextstyle(0,0,1);
    outtextxy(50,140,"'##:::'##::'#######::'##::::'##::::'##:::::'##:'####:'##::: ##:'####:");
	outtextxy(50,155,". ##:'##::'##.... ##: ##:::: ##:::: ##:'##: ##:. ##:: ###:: ##: ####:");
	outtextxy(50,170,":. ####::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ####: ##: ####:");
	outtextxy(50,185,"::. ##:::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ## ## ##:: ##::");
	outtextxy(50,190,"::: ##:::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ##. ####::..:::");
	outtextxy(50,205,"::: ##:::: ##:::: ##: ##:::: ##:::: ##: ##: ##:: ##:: ##:. ###:'####:");
	outtextxy(50,220,"::: ##::::. #######::. #######:::::. ###. ###::'####: ##::. ##: ####:");
	outtextxy(50,235,":::..::::::.......::::.......:::::::...::...:::....::..::::..::....::");
    settextstyle(3,0,1);
    outtextxy(400,420,"Press Any KEY to EXIT");
    delay(500);
    getch();
    exit(0);

}





void welcomeArt()
{
	//clrscr(); //clear the console
	//Ascii art reference: http://www.chris.com/ascii/index.php?art=animals/reptiles/snakes
	printf("\n");
	printf("\t\t    _________         _________ 			\n");
	printf("\t\t   /         \\       /         \\ 			\n");
	printf("\t\t  /  /~~~~~\\  \\     /  /~~~~~\\  \\ 			\n");
	printf("\t\t  |  |     |  |     |  |     |  | 			\n");
	printf("\t\t  |  |     |  |     |  |     |  | 			\n");
	printf("\t\t  |  |     |  |     |  |     |  |         /	\n");
	printf("\t\t  |  |     |  |     |  |     |  |       //	\n");
	printf("\t\t (o  o)    \\  \\_____/  /     \\  \\_____/ / 	\n");
	printf("\t\t  \\__/      \\         /       \\        / 	\n");
	printf("\t\t    |        ~~~~~~~~~         ~~~~~~~~ 		\n");
	printf("\t\t    ^											\n");
	printf("\t		THANKS FOR PLAYING THE SNAKE GAME!			\n");
	printf("\t			    Press Any Key To Exit...	\n");
	printf("\n");


	return;
}
