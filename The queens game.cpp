#include<windows.h>
#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<cstdio>
#include<time.h>
#include "MMSystem.h"
using namespace std;
int q=-1,no,queen=0;

void  gamemenu_controls();
void about_controls(),about();
void rules(),rule_lfr();

int section = 0;
//Game Menu
int gm_index =  1;
void gamemenu()
{
    settextstyle(9, HORIZ_DIR, 8);
    outtextxy(215, 200, "Queen's Game!");
    settextstyle(9, HORIZ_DIR, 5);
    outtextxy(390, 350, "START");
    outtextxy(390, 460,  "ABOUT");
    outtextxy(390, 560,  "RULES OF GAME");
    outtextxy(390, 660,  "EXIT");

    gamemenu_controls();
}

void gamemenu_controls()
{
    while(1)
    {

        if(kbhit())
        {

            if(section == 0)
            {
                char ch;
                ch = getch();
                if(ch == KEY_UP)
                {
                    if(gm_index != 1)
                    {
                        gm_index = gm_index-1;
                    }

                }
                else if(ch == KEY_DOWN)
                {
                    if(gm_index != 4)
                    {
                        gm_index = gm_index+1;
                    }

                }
                else if(ch == '\r')
                {
                    if(gm_index == 1)
                    {
                        void start();
                        break;
                    }
                    else if(gm_index == 2)
                    {
                        about();
                        break;
                    }
                    else if(gm_index == 3)
                    {
                        rules();
                        break;
                    }


                    if(gm_index == 4)
                    {
                        closegraph();
                        exit(0);
                    }

                }

            }
            else
            {
                break;
            }


        }


        if(gm_index == 1)
        {


            settextstyle(9, HORIZ_DIR, 5);
            setcolor(4);
            outtextxy(390, 350, "START");
            setcolor(15);
            outtextxy(390, 460, "ABOUT");
            outtextxy(390, 560,  "RULES OF GAME");
            outtextxy(390, 660,  "EXIT");
        }
        else if(gm_index == 2)
        {


            settextstyle(9, HORIZ_DIR, 5);
            outtextxy(390, 350, "START");
            setcolor(4);
            outtextxy(390, 460, "ABOUT");
            setcolor(15);
            outtextxy(390, 560,  "RULES OF GAME");
            outtextxy(390, 660,  "EXIT");
        }
        else if(gm_index == 3)
        {


            settextstyle(9, HORIZ_DIR, 5);
            outtextxy(390, 350, "START");
            outtextxy(390, 460, "ABOUT");
            setcolor(4);
            outtextxy(390, 560,  "RULES OF GAME");
            setcolor(15);
            outtextxy(390, 660,  "EXIT");
        }
        else if (gm_index ==4)
        {
            settextstyle(9, HORIZ_DIR, 8);
            outtextxy(215, 200, "Queen's Game!");
            settextstyle(9, HORIZ_DIR, 5);
            outtextxy(390, 350, "START");
            outtextxy(390, 460, "ABOUT");
            outtextxy(390, 560,  "RULES OF GAME");
            setcolor(4);
            outtextxy(390, 660,  "EXIT");
            setcolor(15);

        }




    }
}

void about()
{
    section = 2;
    cleardevice();

    settextstyle(9, HORIZ_DIR, 4);
    outtextxy(10, 10, "[enter] for back to main menu");
    settextstyle(9, 0, 8);
    outtextxy(300, 100, "LUDO!");
    settextstyle(9, 0, 3);
    setcolor(4);
    outtextxy(500, 180, "~TEAM LFR!");
    setcolor(15);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(35, 250, "LUDO is a game project");
    outtextxy(35, 300, "made with C++ & BGI Graphics");
    setcolor(4);
    outtextxy(35, 350, "Created by-");
    setcolor(15);
    outtextxy(35, 400, "Lamiya Tahsin Orpa");
    outtextxy(35, 450, "Fairoz Anika");
    outtextxy(35, 500, "Rahanuma Ryaan Ferdous");
    about_controls();

}

void about_controls()
{
    while(1)
    {

        if(kbhit())
        {

            if(section == 2)
            {
                char ch;
                ch = getch();

                if(ch == '\r')
                {

                    section = 0 ;
                    cleardevice();
                    gamemenu();

                }


            }
            else
            {
                break;
            }


        }


    }
}

void rules()
{
    section = 3;
    cleardevice();

    settextstyle(9, HORIZ_DIR, 4);
    outtextxy(10, 10, "[enter] for back to main menu");
    settextstyle(9, 0, 8);
    outtextxy(200, 100, "QUEEN'S GAME!");
    settextstyle(9, 0, 3);
    setcolor(4);
    outtextxy(500, 180, "~TEAM LFR!");
    setcolor(15);
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(4);
    outtextxy(30, 250, "Instructions:");
    setcolor(15);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(30, 300, "1.The player who rolls a 6 first in the game,gets access to the queen.");
    outtextxy(30, 350, "2.The green square are the magical squares, the player who lands on such a ");
    outtextxy(30, 400, " square can cast any of the 2 given spells.");
    outtextxy(30, 450, "3.If a rival player eats the queen, then he gets access to the queen.");
    outtextxy(30, 500, "4.The movement of the tokens have to be controlled by giving the token");
    outtextxy(30, 550, " number on the screen");
    outtextxy(30, 600, "5.There is a timer and if any player fails to make a move within 15 seconds,");
    outtextxy(30, 650, "then he will lose the chance to select from the active tokens and his first token");
    outtextxy(30, 700,"to move will be played.");
    outtextxy(30, 750, "6.The queen has two extra moves- It can move backwards and ");
    outtextxy(30, 800, "choose how many steps to advance or recede once in the whole game.");
    rule_lfr();

}

void rule_lfr()
{
    while(1)
    {

        if(kbhit())
        {

            if(section == 3)
            {
                char ch;
                ch = getch();

                if(ch == '\r')
                {

                    section = 0 ;
                    cleardevice();
                    gamemenu();

                }


            }
            else
            {
                break;
            }


        }


    }
}


struct goti
{
    int pos;
    int  status;
    char cllr;
    int sum;
    int queen;
};
struct user
{
    struct goti g[4];
    int def;
    int color;
    int win;
    int blocked;
};

int color_g[4]= {1,4,6,8};
int ary[2][52]= {0};
int diamond(int);
int  home(int,int,int);
int red_hm[2][6];
int grn_hm[2][6];
int blu_hm[2][6];
int ylw_hm[2][6];
int magic=0,d=1;


void home_assgn(void);

void layout(void);
int movement(int,int,int );
void play(void);
int home_moveback(int clr,int first,int pos);
void smile();
void sad();


void flood_fill(int x,int y,int newColor,int oldColor)
{
    int c;
    c=getpixel(x,y);
    if(c==oldColor)
    {
        setcolor(newColor);
        putpixel (x,y,newColor);
        flood_fill(x+1,y,newColor,oldColor);
        flood_fill(x,y+1,newColor,oldColor);
        flood_fill(x-1,y,newColor,oldColor);
        flood_fill(x,y-1,newColor,oldColor);
    }
}

void hor(int x,int y,int c)
{
    int i=0;
    for(i=0; i<5; i++)
    {
        flood_fill(x+i*45,y,c,0);
    }
}

void ver(int x,int y,int c)
{
    int i=0;
    for(i=0; i<5; i++)
    {
        flood_fill(x,y+i*45,c,0);
    }
}

void cir(int x,int y,int c)
{
    int r=19;

}
void path_init()
{

    int i=0,j,k=0;
    for (j =0; j<53; j++)
        ary[2][j]=0;

    for( j=0; j<=15; j++)
    {

        if(j==6)
        {
            int m=0,p=0;
            for(int l=6; l<19; l++)
            {
                if(l<=11)
                {
                    ary[i][l]=323;
                    ary[i+1][l]=278-m*45;
                    ary[i][l+26]=413;
                    ary[i+1][l+26]=456+m*45;
                    m++;
                }

                else if(l==12)
                {
                    ary[i][l]=368;
                    ary[i+1][l]=53;
                    ary[i][38]=368;
                    ary[i+1][38]=683;
                    ary[i][51]=53;
                    ary[i+1][51]=368;
                }

                else
                {
                    ary[i][l]=413;
                    ary[i+1][l]=53+p*45;
                    ary[i][l+26]=323;
                    ary[i+1][l+26]=683-p*45;
                    p++;
                }

            }
            j+=2;
            k+=13;
        }
        else
        {
            if(j==15)
            {
                ary[i][j+10]=683;
                ary[i+1][j+10]=368;
            }

            else
            {
                ary[i][k]=53+j*45;
                ary[i+1][k] = 323;
                ary[i][50-k]=53+j*45;
                ary[i+1][50-k]=413;
                k++;
            }
        }
    }

}

int main()
{
    initwindow(1100,900,"Menu");
    PlaySound(TEXT("got3.wav"), NULL, SND_ASYNC);
    gamemenu();

    struct user student[4];
    initwindow(1100,900,"Queen's Game");


    layout();

    path_init();

    home_assgn();

    play();
    getch();
    closegraph();

}

void layout(void)
{
    int i=0,x,y,j;
    setcolor(12);
    rectangle(30,30,705,705);
    line(300,30,300,705);
    line(345,30,345,300);
    line(345,435,345,705);
    line(435,345,705,345);
    line(390,30,390,300);
    line(390,435,390,705);
    line(435,30,435,705);
    line(30,300,705,300);
    line(30,345,300,345);
    line(435,345,705,345);
    line(30,390,300,390);
    line(435,390,705,390);
    line(30,435,705,435);
    line(300,300,435,435);
    line(300,435,435,300);

    setcolor(LIGHTMAGENTA);
    circle(98,323,12);
    circle(98,323,20);
    flood_fill(98,323,LIGHTMAGENTA,BLACK);
    circle(323,143,12);
    circle(323,143,20);
    flood_fill(323,143,LIGHTMAGENTA,BLACK);
    circle(413,98,12);
    circle(413,98,20);
    flood_fill(413,98,LIGHTMAGENTA,BLACK);
    circle(593,323,12);
    circle(593,323,20);
    flood_fill(593,323,LIGHTMAGENTA,BLACK);
    circle(638,413,12);
    circle(638,413,20);
    flood_fill(638,413,LIGHTMAGENTA,BLACK);
    circle(413,593,12);
    circle(413,593,20);
    flood_fill(413,593,LIGHTMAGENTA,BLACK);
    circle(323,638,12);
    circle(323,638,20);
    flood_fill(323,638,LIGHTMAGENTA,BLACK);
    circle(143,413,12);
    circle(143,413,20);
    flood_fill(143,413,LIGHTMAGENTA,BLACK);


    for(i=0; i<15; i++)
    {
        if(i>=6&&i<=9)
            continue;
        line(30+i*45,300,30+i*45,435);
    }
    for(i=0; i<15; i++)
    {
        if(i>=6&&i<=9)
            continue;
        line(300,30+i*45,435,30+i*45);

    }
    x=83,y=83;
    cir(x,y,9);
    cir(x+405,y,2);
    cir(x,y+405,1);
    cir(x+405,y+405,14);

    readimagefile("arr.jpg",32,32,297,297);
    readimagefile("deer.jpg",437,437,705,705);
    readimagefile("st.jpg",32,437,298,706);
    readimagefile("tra.jpg",437,32,706,295);

    flood_fill(77,302,11,0);//1
    flood_fill(302,122,11,0);//2
    flood_fill(392,77,11,0);//3
    flood_fill(572,302,11,0);//4
    flood_fill(617,392,11,0);//5
    flood_fill(392,572,11,0);//6
    flood_fill(302,617,11,0);//7
    flood_fill(122,392,11,0);//8
    flood_fill(302,212,3,0);//magic squares
    setcolor(14);
    setlinestyle(0,0,3);
    rectangle(302,212,343,253);
    setcolor(7);
    setlinestyle(0,0,3);
    rectangle(305,213,340,250);


    flood_fill(437,302,3,0);
    setcolor(14);
    setlinestyle(0,0,3);
    rectangle(437,302,478,343);
    setcolor(7);
    setlinestyle(0,0,3);
    rectangle(440,305,475,340);


    flood_fill(437,392,3,0);
    setcolor(14);
    setlinestyle(0,0,3);
    rectangle(437,392,478,433);
    setcolor(7);
    setlinestyle(0,0,3);
    rectangle(440,395,475,430);


    flood_fill(257,392,3,0);
    setcolor(14);
    setlinestyle(0,0,3);
    rectangle(257,392,298,433);
    setcolor(7);
    setlinestyle(0,0,3);
    rectangle(260,395,295,430);

    setlinestyle(0,0,1);
    hor(83,368,1);
    hor(458,368,6);
    ver(368,83,4);
    ver(368,458,8);
    readimagefile("ir2.jpg",300,300,434,434);


    setcolor(9);

}


void smile()
{
    setcolor(RED);

    circle(1000, 300, 40);
    circle(990,290,5);
    circle(1010,290,5);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(1000,300,RED);

    setfillstyle(SOLID_FILL, BLACK);


    fillellipse(310, 85, 2, 6);
    fillellipse(290, 85, 2, 6);

    ellipse(1000, 305, 205, 335, 20, 9);
    ellipse(1000, 305, 205, 335, 20, 10);
    ellipse(1000, 305, 205, 335, 20, 11);

    delay(800);
    floodfill(1000,300,BLACK);

}

void sad()
{
    setcolor(RED);

    circle(1000, 300, 40);
    circle(990,290,5);
    circle(1010,290,5);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(1000,300,RED);

    setfillstyle(SOLID_FILL, BLACK);


    fillellipse(310, 85, 2, 6);
    fillellipse(290, 85, 2, 6);

    ellipse(1000, 315, 0, 180, 20, 10);
    delay(400);
    floodfill(1000,300,BLACK);
}
void crown(int rx, int ry, int clr)
{
    setcolor(YELLOW);
    line(rx+6,ry-4,rx+5,ry+5);
    line(rx+5,ry+5,rx-4,ry+5);
    line(rx-4,ry+5,rx-7,ry-4);
    line(rx-7,ry-4,rx-3,ry-1);
    line(rx-3,ry-1,rx,ry-4);
    line(rx,ry-4,rx+3,ry-1);
    line(rx+3,ry-1,rx+6,ry-4);
    //  if(clr!= YELLOW)
    // setfillstyle(SOLID_FILL,clr);
    flood_fill(rx,ry,YELLOW,clr);
}


int movement(int first,int last,int clr)
{
    int num=6,temp=0,q,rx,ry,magic_color,prs,q2;


    //update play
    // move the graph
    // end of function
    // new turn to player


    for(q=first; q<=last; q++)
    {
        PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
        if(q==7 or q==19 or q==31 or q==45)
            magic_color=3;
        else if(q==1 or q==9 or q==14 or q==22 or q==27 or q==35 or q==40 or q==48)
        {
            if(q==last and getpixel(ary[0][q],ary[1][q])!=LIGHTMAGENTA)
                magic_color=getpixel(ary[0][q],ary[1][q]);
            else
                magic_color=LIGHTMAGENTA;
        }
        else
            magic_color=0;

        if(q==52)
        {
            last=last-52;
            movement(0,last,clr);

            q=0;
            return 0;
        }

        prs=getpixel(ary[0][q],ary[1][q]);
        setcolor(clr);
        rx=ary[0][q];
        ry=ary[1][q];
        delay(200);
        circle(rx,ry,12);
        flood_fill(rx,ry,clr,magic_color);
        if(queen==1 and prs==magic_color)
            crown(rx,ry,clr);

        delay(200);
        if(queen==1)
        {
            flood_fill(rx,ry,clr,YELLOW);
        }

        if(prs!=clr||q==first)
        {


            setcolor(magic_color);
            circle(rx,ry,12);

            flood_fill(rx,ry,magic_color,clr);


        }
    }

    setcolor(clr);
    circle(rx,ry,12);
    flood_fill(rx,ry,clr,magic_color);
    if(queen==1)
        crown(rx,ry,clr);

}


int move_back(int first,int last,int clr)
{
    int num=6,temp=0,q,rx,ry,magic_color,prs;
    rx=ary[0][first];
    ry=ary[1][first];
    flood_fill(rx,ry,clr,14);

    for(q=first; q>=last; q--)
    {
        PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
        if(q==7 or q==19 or q==31 or q==45)
            magic_color=3;
        else if(q==1 or q==9 or q==14 or q==22 or q==27 or q==35 or q==40 or q==48)
            magic_color=LIGHTMAGENTA;
        else
            magic_color=0;
        if(q==52)
        {
            last=52-last;
            move_back(0,last,clr);

            q=0;
            return 0;
        }

        prs=getpixel(ary[0][q],ary[1][q]);


        setcolor(clr);
        rx=ary[0][q];
        ry=ary[1][q];
        delay(200);
        circle(rx,ry,12);
        flood_fill(rx,ry,clr,magic_color);
        if(prs==magic_color)
            crown(rx,ry,clr);

        delay(200);

        flood_fill(rx,ry,clr,14);

        if(prs!=clr||q==first)
        {
            setcolor(magic_color);
            circle(rx,ry,12);

            flood_fill(rx,ry,magic_color,clr);
        }
    }

    setcolor(clr);
    circle(rx,ry,12);
    flood_fill(rx,ry,clr,magic_color);
    crown(rx,ry,clr);
}


void text(float rx, float ry, char str[])
{
    setcolor(MAGENTA);
    rectangle(rx-15,ry-15,rx+15,ry+15);
    setfillstyle(SOLID_FILL,MAGENTA);
    floodfill(rx,ry,MAGENTA);
    setcolor(CYAN);
    outtextxy(rx+50,ry-10,str);

}

void text_fill(float rx, float ry,float rx1, float ry1)
{
    setcolor(RED);
    rectangle(rx,ry,rx1,ry1);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(rx+5,ry+5,RED);
    setcolor(BLACK);
    rectangle(rx,ry,rx1,ry1);
}
int three_options(float rx, float ry)
{
    float rx1,ry1,rx2,ry2;
    rx1=rx;
    ry1=ry+50;
    rx2=rx;
    ry2=ry+100;
    while(1)
    {

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            POINT cursorpos;
            GetCursorPos(&cursorpos);
            if(cursorpos.x>rx-15 and cursorpos.y-26>ry-15 and cursorpos.x<rx+15 and cursorpos.y-26<ry+15)
            {
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                flood_fill(rx,ry,LIGHTMAGENTA,MAGENTA);
                delay(200);
                text_fill(730,380,1090,685);
                return 1;
            }
            if(cursorpos.x>rx1-15 and cursorpos.y-26>ry1-15 and cursorpos.x<rx1+15 and cursorpos.y-26<ry1+15)
            {
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                flood_fill(rx1,ry1,LIGHTMAGENTA,MAGENTA);
                delay(200);
                text_fill(730,380,1090,685);

                return 2;

            }
            if(cursorpos.x>rx2-15 and cursorpos.y-26>ry2-15 and cursorpos.x<rx2+15 and cursorpos.y-26<ry2+15)
            {
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                flood_fill(rx2,ry2,LIGHTMAGENTA,MAGENTA);
                delay(200);
                text_fill(730,380,1090,685);

                return 3;

            }
        }
    }
}

int mouse_click(float rx, float ry)
{
    float rx1,ry1;
    rx1=rx;
    ry1=ry+50;
    while(1)
    {

        if(GetAsyncKeyState(VK_LBUTTON))
        {

            POINT cursorpos;
            GetCursorPos(&cursorpos);
            if(cursorpos.x>rx-15 and cursorpos.y-26>ry-15 and cursorpos.x<rx+15 and cursorpos.y-26<ry+15)
            {
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);

                flood_fill(rx,ry,LIGHTMAGENTA,MAGENTA);
                delay(200);
                text_fill(730,380,1090,685);
                return 1;
            }
            if(cursorpos.x>rx1-15 and cursorpos.y-26>ry1-15 and cursorpos.x<rx1+15 and cursorpos.y-26<ry1+15)
            {
                PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
                flood_fill(rx1,ry1,LIGHTMAGENTA,MAGENTA);
                delay(200);
                text_fill(730,380,1090,685);

                return 2;
            }
        }
    }
}

void wow()
{
    setcolor(RED);

    circle(1000, 300, 40);
    circle(990,290,5);
    circle(1010,290,5);
    circle(1000,320,8);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(1000,300,RED);
    setfillstyle(SOLID_FILL, BLACK);
    delay(900);
    floodfill(1000,300,BLACK);
}

void same_pos(int i,int first)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    if(i==0)
    {
        circle(blu_hm[0][first-1],blu_hm[1][first-1],12);
        floodfill(blu_hm[0][first-1],blu_hm[1][first-1],WHITE);
    }
    if(i==1)
    {
        circle(ary[0][first-1],ary[1][first-1],12);
        floodfill(red_hm[0][first-1],red_hm[1][first-1],WHITE);
    }
    if(i==2)
    {
        circle(grn_hm[0][first-1],grn_hm[1][first-1],12);
        floodfill(grn_hm[0][first-1],grn_hm[1][first-1],WHITE);
    }
    if(i==3)
    {
        circle(ylw_hm[0][first-1],ylw_hm[1][first-1],12);
        floodfill(ylw_hm[0][first-1],ylw_hm[1][first-1],WHITE);
    }

}

void play()

{
    struct user student[4];
    int n,k=1,spell;

    int num;
    text(750,400,"HOW MANY PLAYERS");
    text(750,460,"2 PLAYER");
    text(750,510,"3 PLAYER");
    text(750,560,"4 PLAYER");
    n=three_options(750,460)+1;
    cout<<n;
//  student=(struct user *)malloc(n*sizeof(struct user));

    for(int i =0; i< n; i++)
    {

        for(int j=0; j<4; j++)
        {
            student[i].g[j].pos=-1;
            student[i].g[j].sum=0;
            student[i].g[j].status=1;
            student[i].g[j].queen=-1;
        }
        student[i].win=0;
        student[i].def=k;
        student[i].blocked=0;

        k+=13;
    }
    //gameplaye and movement
    int i=0;



    printf ("GAME STARTED ");
    while(1)
    {
        char s[][10]= {"BLUE","RED","BROWN","GRAY"};
        text(750,460,"PLAYER");
        text(750,510,s[i]);

        delay(2000);
        text_fill(730,380,1090,685);
        printf ("\nplayer-%d ::",i);
        if(student[i].blocked)
        {
            student[i].blocked=0;
            text(750,460,"Sorry! you've been BLOCKED!!!");
            sad();
            PlaySound(TEXT("sad.wav"), NULL, SND_ASYNC);
            delay(1000);
            text_fill(730,380,1090,685);
            goto block;
        }
        int num,run,first,getcl,safejone;

        while(1)
        {
            //cout<<"Enter:";
            //cin>>num;
            num = (rand() % 6 ) +1;
            PlaySound(TEXT("dice.wav"), NULL, SND_ASYNC);
            // delay(100);
            if(num==6)

            {

                readimagefile("ds.jpg",800,200,860,260);
                delay(150);
                readimagefile("ds(rotate).jpg",800,200,860,260);
                delay(150);
                readimagefile("ds.jpg",800,200,860,260);
                delay(150);
                wow();
                delay(500);
            }
            else if(num==5)

            {
                readimagefile("df.jpg",800,200,860,260);
                delay(500);

            }
            else if(num==4)

            {
                readimagefile("dfo.jpg",800,200,860,260);
                delay(500);

            }
            else if(num==3)

            {
                readimagefile("dth.jpg",800,200,860,260);
                delay(500);
            }
            else if(num==2)

            {
                readimagefile("dt.jpg",800,200,860,260);
                delay(500);
            }
            else if(num==1)

            {
                readimagefile("do.jpg",800,200,860,260);
                smile();
                delay(500);
            }
            //  PlaySound(TEXT("dice.wav"), NULL, SND_ASYNC);
            cout<<'\t'<<"Dice: "<<num<<endl;
            clock_t start = clock();

            int sumofpos=0,un=0,w,r,br=1;

            for(r=0; r<4; r++)
            {
                if(student[i].g[r].pos==-1)
                    un++;
                sumofpos+=student[i].g[r].pos;
            }
            if(sumofpos==-4)
            {
                for(int r=0; r<4; r++)
                {
                    if(student[i].g[r].pos==-1 and student[i].g[r].status==1)
                    {
                        run=r;
                        br=0;
                        break;
                    }
                }
            }
            if(br)
                if(un!=0 and num==6)
                {
                    text(750,400,"Do you want to play a new token?");
                    text(750,460,"yes");
                    text(750,510,"no");
                    w=mouse_click(750,460);
                    if(w==1)
                    {
                        for(int r=0; r<4; r++)
                        {
                            if(student[i].g[r].pos==-1)
                            {
                                run=r;
                                br=0;
                                break;
                            }
                        }
                    }
                }
            if(br)
            {
                text(750,460,"LEFT CLICK ON THE TOKEN TO PROCEDE");
                delay(2000);
                text_fill(730,380,1090,685);
            }
            if(br)
                while(1)
                {

                    if (((clock () - start)/ CLOCKS_PER_SEC ) >= 17)
                    {
                        PlaySound(TEXT("timer.wav"), NULL, SND_ASYNC);
                        text(750,460,"TIME OUT: 15 seconds ");
                        delay(2000);
                        text_fill(730,380,1090,685);
                        for(int l=0; l<4; l++)
                        {
                            if(student[i].g[l].pos!=-1)
                            {
                                run=l;
                                break;
                            }
                        }
                        break;

                    }

                    if(GetAsyncKeyState(VK_LBUTTON))
                    {
                        POINT cursorpos;

                        GetCursorPos(&cursorpos);


                        for(r=0; r<4; r++)
                        {
                            float rx,ry;
                            if(student[i].g[r].sum>50)
                            {
                                int bdb=student[i].g[r].pos;
                                if(i==1)
                                {
                                    rx=red_hm[0][bdb-1];
                                    ry=red_hm[1][bdb-1];
                                }
                                else if(i==2)
                                {
                                    rx=grn_hm[0][bdb-1];
                                    ry=grn_hm[1][bdb-1];
                                }
                                else if(i==3)
                                {
                                    rx=ylw_hm[0][bdb-1];
                                    ry=ylw_hm[1][bdb-1];
                                }
                                else if(i==0)
                                {
                                    rx=blu_hm[0][bdb-1];
                                    ry=blu_hm[1][bdb-1];
                                }
                            }
                            else
                            {
                                rx=ary[0][student[i].g[r].pos];
                                ry=ary[1][student[i].g[r].pos];
                            }


                            if(cursorpos.x>=(rx-22.5) and cursorpos.x<=(rx+22.5) and cursorpos.y-26>=(ry-22.5) and cursorpos.y-26<=(ry+22.5) )
                            {
                                run=r;
                                break;
                            }
                        }

                    }
                    br=0;
                    if(run==r)
                        break;

                }

            if(student[i].g[run].queen==1 and student[i].g[run].status!=0)
            {
                int p;
                queen=1;
                text(750,400,"Do you want to use the queen's power?");
                text(750,460,"Yes");
                text(750,510,"No");
                p=mouse_click(750,460);
                if(p==1)
                {
                    text(750,400,"Which power do you want to use?");
                    text(750,460,"Recede");
                    text(750,510,"choose how many steps");
                    p=mouse_click(750,460);
                    if(p==2 and d!=1)
                    {
                        text(750,460,"you have already used this power");
                        delay(500);
                        text_fill(730,380,1090,685);
                    }

                    if(p==1)
                    {
                        num=-num;
                        if(student[i].g[run].pos+num<0 and student[i].g[run].sum<40)
                        {
                            text(750,400,"Cannot recede!!!");
                            delay(500);
                            text_fill(730,380,1090,685);
                            num=-num;
                        }
                    }
                    if(p==2 and d==1)
                    {

                        char ch;
                        while(1)
                        {
                            text(750,400,"Enter number of steps:");
                            if(kbhit())
                            {
                                ch=getch();

                                p=ch-'0';
                                if(ch=='1')
                                    outtextxy(950,390,"1");
                                else if(ch=='2')
                                    outtextxy(950,390,"2");
                                else if(ch=='3')
                                    outtextxy(950,390,"3");
                                else if(ch=='4')
                                    outtextxy(950,390,"4");
                                else if(ch=='5')
                                    outtextxy(950,390,"5");
                                else if(ch=='6')
                                    outtextxy(950,390,"6");
                                if(p<1 or p>6)
                                {
                                    text(750,450,"Invalid input!!!");
                                    p=-1;
                                }
                                delay(500);
                                text_fill(730,380,1090,685);

                                if(p<=6 and p>=1)
                                    break;
                            }
                        }
                        if(p<=6)
                        {
                            d=0;
                            num=p;
                            text(750,460,"ADVANCE");
                            text(750,510,"RECEDE");
                            p=mouse_click(750,460);
                            if(p==2)
                            {
                                num=-num;
                                if(student[i].g[run].pos+num<0 and student[i].g[run].sum<40)
                                {
                                    text(750,400,"Cannot recede!!!");
                                    delay(500);
                                    text_fill(730,380,1090,685);
                                    num=-num;
                                }
                            }//
                        }
                    }
                }
            }
            else
                queen=0;
            // which goti to move
         /*   if( student[i].g[run].status==0)
            {
                text(750,400,"it already reached home ");
                delay(500);
                text_fill(730,380,1090,685);
                break;
            } */

            if(abs(num) == 6)
            {
                if(student[i].g[run].pos== -1)
                {
                    student[i].g[run].pos = student[i].def;
                    //  take out from home
                    student[i].g[run].sum=0;
                    flood_fill(ary[0][student[i].def],ary[1][student[i].def],color_g[i],LIGHTMAGENTA);
                    if(q==-1)
                    {
                        q=i;
                        no=run;
                        student[i].g[run].queen=1;
                        PlaySound(TEXT("queen.wav"), NULL, SND_ASYNC);
                        crown(ary[0][student[i].def],ary[1][student[i].def],color_g[i]);
                    }
                }

                else
                {

                    student[i].g[run].sum+=num;
                    first = student[i].g[run].pos;

                    getcl=getpixel(ary[0][(first+num)%52],ary[1][(first+num)%52]);
                    printf("\n%d\n",getcl);
                    if(getcl==3)
                    {
                        // PlaySound(TEXT("queen.wav"), NULL, SND_ASYNC);
                        magic=1;
                    }
                    if(getcl != 0 && getcl != color_g[i] && getcl!=15 && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  )
                    {


                        // eat the other player
                        if(getcl==14 and q!=i)
                        {
                            sad();
                            PlaySound(TEXT("queen.wav"), NULL, SND_ASYNC);
                            text(750,400,"The queen's power has been transferred!!!");

                            delay(500);
                            text_fill(730,380,1090,685);
                            student[q].g[no].queen=0;
                            student[i].g[run].queen=1;
                            student[q].g[no].pos =-1;
                            flood_fill(ary[0][first+num],ary[1][first+num],color_g[q],getcl);
                            if(first+num == 7 or first+num == 19 or first+num == 31 or first+num == 45)
                            {
                                flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],color_g[q],14);
                                flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],3,color_g[q]);
                            }
                            else
                            {
                                flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],color_g[q],14);
                                flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],0,color_g[q]);
                            }
                            //   if(first+num==1 or first+num==9 or first+num==14 or first+num==22 or first+num==27 or first+num==35 or first+num==40 or first+num==48)
                            //  putpixel(ary[0][first],ary[1][first],color_g[i]);
                            //  else
                            crown(ary[0][first],ary[1][first],color_g[i]);
                            queen=1;
                            d=1;
                            q=i;
                            no=run;
                            delay(200);
                        }
                        else
                        {
                            int l=0,m=0;
                            for( l=0; l<n; l++)
                            {
                                if(color_g[l] == getcl)
                                    break;
                            }
                            if(l!=n)
                            {
                                sad();
                                for( m=0 ; m<4; m++)
                                {
                                    if( student[l].g[m].pos == (first+num)%52)
                                        break;
                                }
                                //   printf("goti number %d %d",m,l);

                                student[l].g[m].pos =-1;
                                if(first+num == 7 or first+num == 19 or first+num == 31 or first+num == 45)
                                    flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],3,getcl);

                                else
                                    flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],0,getcl);
                                PlaySound(TEXT("sad.wav"), NULL, SND_ASYNC);

                            }
                        }
                    }
                    printf("sum :%d\n",student[i].g[run].sum);
                    if(first<6 and student[i].g[run].sum>45 and num<0)
                    {
                        student[i].g[run].pos= home_moveback(color_g[i],first,first+num);
                        for(int l=0; l<n; l++)
                        {
                            for(int m=0; m<4; m++)
                            {
                                if(l==i and m==run)
                                    continue;
                                if(student[l].g[m].pos==first)
                                {
                                    if(first>=45 and first<=51)
                                    {

                                        setcolor(color_g[l]);
                                        circle(ary[0][first],ary[1][first],12);
                                        setfillstyle(SOLID_FILL,color_g[l]);
                                        floodfill(ary[0][first],ary[1][first],color_g[l]);
                                    }


                                    else
                                    {

                                        same_pos(i,first);

                                    }
                                    break;
                                }
                            }
                        }


                        break;
                    }
                    if(student[i].g[run].sum == 56 and first==51 and student[i].win==3 )
                    {
                        student[i].g[run].sum = 50;
                        text(750,400,"CANNOT MOVE!!!");
                        delay(800);
                        text_fill(730,380,1090,685);
                        goto block;
                    }

                    if(student[i].g[run].sum > 50)
                    {
                        student[i].g[run].pos=home(color_g[i],first,first+num);
                        magic=0;

                        //   ***************************************
                        for(int l=0; l<n; l++)
                        {
                            for(int m=0; m<4; m++)
                            {
                                if(l==i and m==run)
                                    continue;
                                if(student[l].g[m].pos==first)
                                {
                                    if(first>=45 and first<=51)
                                    {

                                        setcolor(color_g[l]);
                                        circle(ary[0][first],ary[1][first],12);
                                        setfillstyle(SOLID_FILL,color_g[l]);
                                        floodfill(ary[0][first],ary[1][first],color_g[l]);
                                    }


                                    else
                                    {

                                        same_pos(i,first);

                                    }
                                    break;
                                }
                            }
                        }

                        if(  student[i].g[run].pos == 6)
                        {
                            char s[][10]= {"BLUE","RED","BROWN","GRAY"};
                            text(750,400,s[i]);

                            student[i].g[run].status=0;
                            student[i].g[run].pos=-1;
                            student[i].win+=1;
                            outtextxy(750,460,"NUMBER OF FINISHES");
                            if(student[i].win==1)
                                outtextxy(900,460,"1");
                            else if(student[i].win==2)
                                outtextxy(900,460,"2");
                            else if(student[i].win==3)
                                outtextxy(900,460,"3");
                            delay(2000);
                            text_fill(730,380,1090,685);
                            if(student[i].win==4)
                            {
                                settextstyle(9, HORIZ_DIR, 4);
                                outtextxy(750,460,"WINNER");
                                delay(2000);
                                return;
                            }
                        }

                    }
                    else
                    {
                        if(first+num<first)
                            move_back(first,(first+num),color_g[i]);
                        else
                            movement(first,(first+num),color_g[i]);
                        for(int l=0; l<n; l++)
                        {
                            for(int m=0; m<4; m++)
                            {
                                if(l==i and m==run)
                                    continue;
                                if(student[l].g[m].pos==first)
                                {
                                    setcolor(color_g[l]);
                                    circle(ary[0][first],ary[1][first],12);
                                    setfillstyle(SOLID_FILL,color_g[l]);
                                    floodfill(ary[0][first],ary[1][first],color_g[l]);
                                    if(student[l].g[m].queen==1)
                                        crown(ary[0][first],ary[1][first],color_g[l]);
                                    break;
                                }
                            }
                        }
                        student[i].g[run].pos = (student[i].g[run].pos+num)%52;
                    }

                }
                //continue;
            }
            else
            {
                if(student[i].g[run].pos==-1)
                {
                    text(750,400,"CANNOT MOVE!!!");
                    delay(800);
                    text_fill(730,380,1090,685);
                    break;
                }
                student[i].g[run].sum+=num;
                first = student[i].g[run].pos;
                getcl=getpixel(ary[0][(first+num)%52],ary[1][(first+num)%52]);
                printf("\n%d %d\n",first,first+num);
                if(getcl==3)
                {
                    magic=1;
                }
                if(getcl != 0 && getcl != color_g[i] && getcl!=15 && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  )
                {
                    if(getcl==14 and q!=i)
                    {
                        sad();
                        PlaySound(TEXT("queen.wav"), NULL, SND_ASYNC);
                        text(750,400,"The queen's power has been transferred!!!");

                        delay(500);
                        text_fill(730,380,1090,685);
                        student[q].g[no].queen=0;
                        student[i].g[run].queen=1;
                        student[q].g[no].pos =-1;
                        flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],color_g[q],getcl);
                        if(first+num == 7 or first+num == 19 or first+num == 31 or first+num == 45)
                        {
                            flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],color_g[q],14);
                            flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],3,color_g[q]);
                        }
                        else
                        {
                            flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],color_g[q],14);
                            flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],0,color_g[q]);
                        }
                        //    if(first==1 or first==9 or first==14 or first==22 or first==27 or first==35 or first==40 or first==48)
                        //   putpixel(ary[0][first],ary[1][first],YELLOW);
                        //    else
                        crown(ary[0][first],ary[1][first],color_g[i]);

                        queen=1;
                        d=1;
                        q=i;
                        no=run;
                        delay(200);
                    }
                    else
                    {
                        int l=0,m=0;
                        for( l=0; l<n; l++)
                        {
                            if(color_g[l] == getcl)
                                break;
                        }
                        if(l!=n)
                        {
                            PlaySound(TEXT("sad.wav"), NULL, SND_ASYNC);
                            sad();
                            for( m=0 ; m<4; m++)
                            {
                                if( student[l].g[m].pos == (first+num)%52)
                                    break;
                            }
                            //   printf("goti number %d %d",m,l);

                            student[l].g[m].pos =-1;
                            if(first+num == 7 or first+num == 19 or first+num == 31 or first+num == 45)
                                flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],3,getcl);

                            else
                                flood_fill(ary[0][(first+num)%52],ary[1][(first+num)%52],0,getcl);


                        }
                    }
                }
                printf("sum :%d\n",student[i].g[run].sum);
                if(first<6 and student[i].g[run].sum>45 and num<0)
                {
                    student[i].g[run].pos= home_moveback(color_g[i],first,first+num);
                    for(int l=0; l<n; l++)
                    {
                        for(int m=0; m<4; m++)
                        {
                            if(l==i and m==run)
                                continue;
                            if(student[l].g[m].pos==first)
                            {
                                if(first>=45 and first<=51)
                                {

                                    setcolor(color_g[l]);
                                    circle(ary[0][first],ary[1][first],12);
                                    setfillstyle(SOLID_FILL,color_g[l]);
                                    floodfill(ary[0][first],ary[1][first],color_g[l]);
                                }


                                else
                                {

                                    same_pos(i,first);

                                }
                                break;
                            }
                        }
                    }

                    break;
                }

                if( student[i].g[run].sum >50)
                {
                    printf("  \t \t HOME TIME ");

                    student[i].g[run].pos= home(color_g[i],first,first+num);

                    for(int l=0; l<n; l++)
                    {
                        for(int m=0; m<4; m++)
                        {
                            if(l==i and m==run)
                                continue;
                            if(student[l].g[m].pos==first)
                            {
                                if(first>=45 and first<=51)
                                {

                                    setcolor(color_g[l]);
                                    circle(ary[0][first],ary[1][first],12);
                                    setfillstyle(SOLID_FILL,color_g[l]);
                                    floodfill(ary[0][first],ary[1][first],color_g[l]);
                                }


                                else
                                {

                                    same_pos(i,first);

                                }
                                break;
                            }
                        }
                    }

                    if(  student[i].g[run].pos == 6)
                    {
                        char s[][10]= {"BLUE","RED","BROWN","GRAY"};
                        text(750,400,s[i]);

                        student[i].g[run].status=0;
                        student[i].win+=1;
                        text(750,460,"NUMBER OF FINISHES");
                        if(student[i].win==1)
                            text(800,510,"1");
                        else if(student[i].win==2)
                            text(800,510,"2");
                        else if(student[i].win==3)
                            text(800,510,"3");
                        delay(1000);
                        text_fill(730,380,1090,685);

                        if(student[i].win==4)
                        {
                            settextstyle(9, HORIZ_DIR, 4);
                            outtextxy(750,460,"WINNER");
                            PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
                            delay(2000);
                            return;
                        }
                    }
                    magic=0;
                    break;
                }

                if((first+num<first))
                    move_back(first,(first+num),color_g[i]);
                else
                    movement(first,(first+num),color_g[i]);
                for(int l=0; l<n; l++)
                {
                    for(int m=0; m<4; m++)
                    {
                        if(l==i and m==run)
                            continue;
                        if(student[l].g[m].pos==first)
                        {
                            setcolor(color_g[l]);
                            circle(ary[0][first],ary[1][first],12);
                            setfillstyle(SOLID_FILL,color_g[l]);
                            floodfill(ary[0][first],ary[1][first],color_g[l]);
                            if(student[l].g[m].queen==1)
                                crown(ary[0][first],ary[1][first],color_g[l]);
                            break;
                        }
                    }
                }
                student[i].g[run].pos=(student[i].g[run].pos+num)%52;

                if(magic!=1)
                    break;
            }
            if(magic!=0 && num!=6)
            {
                int op;
                PlaySound(TEXT("ms.wav"), NULL, SND_ASYNC);
                magic=0;
                text(750,400,"Cast a spell");
                text(750,460,"1.roll again");
                text(750,510,"2.Block an opponent");
                spell=mouse_click(750,460);
                if(spell==2)
                {
                    int rx=750,ry=460;
                    if(n==2)
                    {
                        if(i==0)
                            op=1;
                        else
                            op=0;
                    }
                    else if(n==3)
                    {
                        char s[][10]= {"BLUE","RED","BROWN"};
                        text(750,400,"Enter opponent number:");
                        for(int t=0; t<3; t++)
                        {
                            if(t==i)
                                continue;
                            text(rx,ry,s[t]);
                            ry=ry+50;
                        }
                        op=mouse_click(750,460);
                        if(i>=op)
                            op--;

                    }
                    else if(n==4)
                    {
                        char s[][10]= {"BLUE","RED","BROWN","GRAY"};
                        text(750,400,"Enter opponent number:");
                        for(int t=0; t<4; t++)
                        {
                            if(t==i)
                                continue;
                            text(rx,ry,s[t]);
                            ry=ry+50;
                        }
                        op=three_options(750,460);
                        if(i>=op)
                            op--;
                    }
                    student[op].blocked=1;
                    break;
                }
            }

        }

block:
        i=(i+1)%n;

    }

}

int diamond(int x)
{
    int a;
    if(x == 1)

        a = 51;
    else if( x == 4)
        a = 12;
    else if(x == 6)
        a = 25;
    else if (x == 8)
        a = 38;
    return a;
}


void home_assgn()
{


    for(int i=0; i<6; i++)
    {
        blu_hm[0][i]=98+45*i;
        blu_hm[1][i]=368;

    }


    for(int i=0; i<6; i++)
    {
        red_hm[0][i]=368;
        red_hm[1][i]=98+45*i;

    }


    for(int i=0; i<6; i++)
    {
        ylw_hm[0][i]=368;
        ylw_hm[1][i]=638-45*i;
    }


    for(int i=0; i<6; i++)
    {
        grn_hm[0][i]=638-45*i;
        grn_hm[1][i]=368;

    }

}


int home(int clr,int first,int pos)
{
    int ab,remn,tmp,rx,ry;
    int bdb;
    tmp=diamond(clr);
    if(first > 5)
    {
        movement(first,tmp,clr);
        bdb=0;
        remn=pos-tmp;
        if(queen==1)
            flood_fill(ary[0][tmp],ary[1][tmp],clr,14);
        flood_fill(ary[0][tmp],ary[1][tmp],0,clr);
    }
    else
    {
        if(pos > 6)
        {
            text(750,400,"CANNOT MOVE!!!");
            delay(800);
            text_fill(730,380,1090,685);
            return first;
        }
        bdb=first;
        remn=pos;
    }

    printf(" bdb %d remn %d",bdb,remn);
    switch(clr)
    {
    case 1:
        if(bdb > 0)
        {
            setcolor(1);
            rx=blu_hm[0][bdb-1];
            ry=blu_hm[1][bdb-1];
            if(queen==1)
                flood_fill(rx,ry,15,14);
            circle(rx,ry,12);
            flood_fill(rx,ry,1,15);
        }
        for(ab=bdb; ab<remn; ab++)
        {

            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            int prs;
            clr=15;
            setcolor(clr);
            rx=blu_hm[0][ab];
            ry=blu_hm[1][ab];
            prs=getpixel(rx,ry);
            delay(200);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,1);
            delay(200);
            if(prs!=clr)
           {setcolor(1);
            circle(rx,ry,12);
            flood_fill(rx,ry,1,clr);
           }
        }
        setcolor(clr);
        circle(rx,ry,12);
        flood_fill(rx,ry,clr,1);
        break;

    case 6:
        if(bdb > 0)
        {
            setcolor(6);
            rx=grn_hm[0][bdb-1];
            ry=grn_hm[1][bdb-1];
            if(queen==1)
                flood_fill(rx,ry,15,14);
            circle(rx,ry,12);
            flood_fill(rx,ry,6,15);
        }
        for(ab=bdb; ab<remn; ab++)
        {
            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            clr=15;
            setcolor(clr);
            rx=grn_hm[0][ab];
            ry=grn_hm[1][ab];
            delay(200);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,6);
            delay(200);
            setcolor(6);
            circle(rx,ry,12);
            flood_fill(rx,ry,6,clr);
        }
        setcolor(clr);
        circle(rx,ry,12);
        flood_fill(rx,ry,clr,6);
        break;

    case 4:
        if(bdb > 0)
        {
            setcolor(4);
            rx=red_hm[0][bdb-1];
            ry=red_hm[1][bdb-1];
            //   if(queen=getpixel(rx,ry)==14)
            if(queen==1)
                flood_fill(rx,ry,15,14);
            circle(rx,ry,12);
            flood_fill(rx,ry,4,15);
        }
        for(ab=bdb; ab<remn; ab++)
        {
            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            clr=15;
            setcolor(clr);
            rx=red_hm[0][ab];
            ry=red_hm[1][ab];
            delay(200);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,4);
            delay(200);
            setcolor(4);
            circle(rx,ry,12);
            flood_fill(rx,ry,4,clr);
        }
        setcolor(clr);
        circle(rx,ry,12);
        flood_fill(rx,ry,clr,4);
        break;



    case 8:
        if(bdb > 0)
        {
            setcolor(8);
            rx=ylw_hm[0][bdb-1];
            ry=ylw_hm[1][bdb-1];
            if(queen==1)
                flood_fill(rx,ry,15,14);
            circle(rx,ry,12);
            flood_fill(rx,ry,8,15);
        }
        for(ab=bdb; ab<remn; ab++)
        {
            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            clr=15;
            setcolor(clr);
            rx=ylw_hm[0][ab];
            ry=ylw_hm[1][ab];
            delay(200);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,8);
            delay(200);
            setcolor(8);
            circle(rx,ry,12);
            flood_fill(rx,ry,8,clr);
        }
        setcolor(clr);
        circle(rx,ry,12);
        flood_fill(rx,ry,clr,8);
        break;
    }
    if(queen==1)
        crown(rx,ry,15);
    return ab;

}

int home_moveback(int clr,int first,int pos)
{
    int ab,remn,tmp,rx,ry,queen;
    int bdb;
    bdb=first;
    if(pos<1)
    {
        remn=0;
        tmp=diamond(clr);
    }
    else
        remn=pos-1;
    switch(clr)
    {
    case 1:
        setcolor(1);
        rx=blu_hm[0][bdb-1];
        ry=blu_hm[1][bdb-1];
        circle(rx,ry,12);
        flood_fill(rx,ry,1,15);

        for(ab=bdb-1; ab>=remn; ab--)
        {
            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            setcolor(15);
            rx=blu_hm[0][ab];
            ry=blu_hm[1][ab];
            queen=getpixel(rx,ry);
            if(queen==14)
                flood_fill(rx,ry,15,14);
            delay(200);
            circle(rx,ry,12);
            flood_fill(rx,ry,15,1);
            delay(200);
            setcolor(1);
            circle(rx,ry,12);
            flood_fill(rx,ry,1,15);
        }
        if(pos>=1)
        {
            setcolor(15);
            circle(rx,ry,12);
            flood_fill(rx,ry,15,1);
        }
        break;

    case 6:
        setcolor(6);
        rx=grn_hm[0][bdb-1];
        ry=grn_hm[1][bdb-1];
        circle(rx,ry,12);
        flood_fill(rx,ry,6,15);

        for(ab=bdb-2; ab>=remn; ab--)
        {
            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            // clr=15;
            setcolor(15);
            rx=grn_hm[0][ab];
            ry=grn_hm[1][ab];
            delay(200);
            if(getpixel(rx,ry)==14)
                flood_fill(rx,ry,15,14);
            circle(rx,ry,12);
            flood_fill(rx,ry,15,6);
            delay(200);
            setcolor(6);
            circle(rx,ry,12);
            flood_fill(rx,ry,6,15);
        }
        if(pos>=1)
        {
            setcolor(15);
            circle(rx,ry,12);
            flood_fill(rx,ry,15,6);
        }
        break;

    case 4:
        setcolor(4);
        rx=red_hm[0][bdb-1];
        ry=red_hm[1][bdb-1];
        circle(rx,ry,12);
        flood_fill(rx,ry,4,15);

        for(ab=bdb-1; ab>=remn; ab--)
        {
            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            // clr=15;
            setcolor(15);
            rx=red_hm[0][ab];
            ry=red_hm[1][ab];
            delay(200);
            queen=getpixel(rx,ry);
            printf("%d\n",queen);
            if(queen==14)
            {
                flood_fill(rx+1,ry+1,15,14);
                // flood_fill(rx,ry,9,15);
            }

            circle(rx,ry,12);
            flood_fill(rx,ry,15,4);
            delay(200);
            setcolor(4);
            circle(rx,ry,12);
            flood_fill(rx,ry,4,15);
        }
        if(pos>=1)
        {
            setcolor(15);
            circle(rx,ry,12);
            flood_fill(rx,ry,15,4);
        }
        break;



    case 8:
        setcolor(8);
        rx=ylw_hm[0][bdb-1];
        ry=ylw_hm[1][bdb-1];
        circle(rx,ry,12);
        flood_fill(rx,ry,8,15);

        for(ab=bdb-2; ab>=remn; ab--)
        {
            PlaySound(TEXT("move.wav"), NULL, SND_ASYNC);
            //  clr=15;
            setcolor(15);
            rx=ylw_hm[0][ab];
            ry=ylw_hm[1][ab];
            delay(200);
            if(getpixel(rx,ry)==14)
                flood_fill(rx,ry,15,14);
            circle(rx,ry,12);
            flood_fill(rx,ry,15,8);
            delay(200);
            setcolor(8);
            circle(rx,ry,12);
            flood_fill(rx,ry,8,15);
        }
        if(pos>=1)
        {
            setcolor(15);
            circle(rx,ry,12);
            flood_fill(rx,ry,15,8);
        }
        break;

    }
    if(pos<1)
    {
        move_back(tmp,tmp+pos,clr);
        crown(ary[0][tmp+pos],ary[1][tmp+pos],clr);
    }
    else
        crown(rx,ry,15);

    if(pos>=1)
        return ab+2;
    return tmp+pos;

}
