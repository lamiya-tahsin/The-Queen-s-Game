#include<graphics.h>
#include<iostream>
#include<cstdio>
using namespace std;

struct goti
{
    int pos;
    int  status;
    char cllr;
    int sum;
};
struct user
{
    struct goti g[4];
    int def;
    int color;
    int win;
    int blocked;
};

int color_g[4]={9,2,14,1};
int ary[2][52]={0};
int diamond(int);
int  home(int,int,int);
int red_hm[2][6];
int grn_hm[2][6];
int blu_hm[2][6];
int ylw_hm[2][6];
int magic=0;

void home_assgn(void);

void layout(void);
int movement(int,int ,int );
void play(void);

void star(int x,int y)
{
    line(x-7,y-7,x,y+10);
    line(x,y+10,x+7,y-7);
    line(x+7,y-7,x-7,y-7);
    line(x-7,y+7,x+7,y+7);
    line(x+7,y+7,x,y-10);
    line(x,y-10,x-7,y+7);
}

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
    for(i=0;i<5;i++)
    {
        flood_fill(x+i*45,y,c,0);
    }
}

void ver(int x,int y,int c)
{
    int i=0;
    for(i=0;i<5;i++)
    {
        flood_fill(x,y+i*45,c,0);
    }
}

void cir(int x,int y,int c)
{
      int r=19;

      circle(x+42,y+42,r);
      circle(x+42,y+42+83,r);
      circle(x+42+83,y+42,r);
      circle(x+42+83,y+42+83,r);
      flood_fill(x+42,y+42,c,0);
      flood_fill(x+42,y+42+83,c,0);int ary[2][15]={0};
      flood_fill(x+42+83,y+42,c,0);
      flood_fill(x+42+83,y+42+83,c,0);
}
void path_init()
{

    int i=0,j,k=0;
    for (j =0;j<53;j++)
        ary[2][j]=0;

     for( j=0;j<=15;j++)
     {

         if(j==6)
         {
              int m=0,p=0;
             for(int l=6;l<19;l++)
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

    int gd=DETECT;
    int gm;

    struct user student[4];

    //initgraph(&gd,&gm,"");
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
        star(98,323);
        star(323,143);
        star(413,98);
        star(593,323);
        star(638,413);
        star(413,593);
        star(323,638);
        star(143,413);
       rectangle(75,75,255,255);
      rectangle(83,83,248,248);
       rectangle(480,75,660,255);
        rectangle(488,83,653,248);
       rectangle(75,480,255,660);
       rectangle(83,488,248,653);
       rectangle(480,480,660,660);
       rectangle(488,488,653,653);
       for(i=0;i<15;i++)
        {
            if(i>=6&&i<=9)
              continue;
               line(30+i*45,300,30+i*45,435);
        }
        for(i=0;i<15;i++)
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

        flood_fill(353,368,9,0);//home
        flood_fill(368,353,2,0);//home
        flood_fill(368,413,1,0);//home
        flood_fill(413,368,14,0);//home
        flood_fill(32,32,9,0);
        flood_fill(437,32,2,0);
        flood_fill(32,437,1,0);
        flood_fill(437,437,14,0);
        //flood_fill(84,84,15,0);
        readimagefile("game/targaryen.png",83,83,248,248);
        flood_fill(84,489,15,0);
        flood_fill(489,84,15,0);
        flood_fill(489,489,15,0);
        flood_fill(77,302,11,0);//1
        flood_fill(302,122,11,0);//2
        flood_fill(392,77,11,0);//3
        flood_fill(572,302,11,0);//4
        flood_fill(617,392,11,0);//5
        flood_fill(392,572,11,0);//6
        flood_fill(302,617,11,0);//7
        flood_fill(122,392,11,0);//8
        flood_fill(302,212,3,0);//magic squares
        readimagefile("game/sp.jpg",302,212,343,253);
        flood_fill(437,302,3,0);
        readimagefile("game/sp.jpg",437,302,478,353);
        flood_fill(437,392,3,0);
        readimagefile("game/sp.jpg",437,392,478,433);
        flood_fill(257,392,3,0);
        readimagefile("game/sp.jpg",257,392,298,433);
        hor(83,368,9);
        hor(458,368,14);
        ver(368,83,2);
        ver(368,458,1);


    setcolor(9);

}


int movement(int first,int last,int clr)
{
int num=6,temp=0,q,rx,ry,prev,prs=0,t1,t2;


      //update play
      // move the graph
     // end of function
     // new turn to player

      for(q=first;q<=last;q++)
       {

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
            flood_fill(rx,ry,clr,0);
            delay(200);
            if(prs!=clr||q==first){
                    setcolor(0);
                    circle(rx,ry,12);

                    flood_fill(rx,ry,0,clr);
                }
      }

      setcolor(clr);
      circle(rx,ry,12);
      flood_fill(rx,ry,clr,0);

}




void play()

{
    struct user  *student;
    int n,k=1,spell;

    int num;
    printf("\n HOW MANY PLAYERS : ");
    scanf("%d",&n);
    student = (struct user *)malloc(n*sizeof(struct user));
    // intialise the users
    for(int i =0; i< n; i++)
    {

        for(int j=0; j<4; j++)
        {
            student[i].g[j].pos=-1;
            student[i].g[j].sum=0;
            student[i].g[j].status=1;
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

        printf ("\nplayer-%d ::",i);
        if(student[i].blocked)
        {
            student[i].blocked=0;
            printf("Sorry! you've been BLOCKED!!!");
            goto block;
        }
        int num,run,first,getcl,safejone;
        //generate random number and get it in pos
        // and give again chance to same user
        //num
        // find which one user want to play in   run
        //give the extra conditionsssss
        while(1)
        {
            num = (rand() % 6 ) +1;
            printf("\tDICE : %d :",num);
            printf("\n\tTO MOVE : (0,1,2,3)  ::");
            scanf("%d",&run);                     // which goti to move
            if( student[i].g[run].status==0)
            {
                cout<<"it already reached home "<<endl;
                break;
            }

            if(num == 6)
            {
                if(student[i].g[run].pos== -1)
                {
                    student[i].g[run].pos = student[i].def;
                    //  take out from home
                    student[i].g[run].sum=0;
                }

                else
                {

                    student[i].g[run].sum+=num;
                    first = student[i].g[run].pos;

                    getcl=getpixel(ary[0][first+num],ary[1][first+num]);

                    if(getcl==getpixel(310,220))
                        magic=1;

                    if(getcl != 0 && getcl != color_g[i] && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  )
                    {
                        // eat the other player
                        int l,m;
                        for( l=0; l<n; l++) //get the player
                        {
                            if(student[l].color == getcl)
                                break;
                        }
                        if(l!=n)
                        {
                            printf(" :: m %d  :",m);
                            for( m=0 ; m<4; m++) // get the particular player
                            {
                                if( student[l].g[m].pos == first+num)
                                    break;
                            }
                            student[l].g[m].pos =-1;  //  intial stage set
                            printf("goti number %d %d",m,l);
                            flood_fill(ary[0][first+num],ary[1][first+num],0,getcl);
                        }
                    }

                    printf("sum :%d\n",student[i].g[run].sum);
                    if(student[i].g[run].sum > 50)
                    {
                        student[i].g[run].pos=home(color_g[i],first,first+num);
                        if(  student[i].g[run].pos == 6)
                        {
                            cout<<"\t\t\tFINISHED"<<endl;
                            student[i].g[run].status=0;
                            student[i].win+=1;
                        }
                        break;
                    }

                    movement(first,(first+num),color_g[i]);     //yaha temp changes %52.
                    student[i].g[run].pos = (student[i].g[run].pos+num)%52;

                }
                //continue;
            }
            else
            {
                if(student[i].g[run].pos==-1)
                {
                    printf(" \n\t\t::CANNOT MOVE ::");

                    break;
                }
                student[i].g[run].sum+=num;
                first = student[i].g[run].pos;
                getcl=getpixel(ary[0][first+num],ary[1][first+num]);
                if(getcl==3)
                        magic=1;
                if(getcl != 0 && getcl != color_g[i] && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  )
                {
                    int l=0,m=0;
                    for( l=0; l<n; l++)
                    {
                        if(color_g[l] == getcl)
                            break;
                    }
                    if(l!=n){
                    for( m=0 ; m<4; m++)
                    {
                        if( student[l].g[m].pos == first+num)
                            break;
                    }
                    //   printf("goti number %d %d",m,l);
                    student[l].g[m].pos =-1;
                    flood_fill(ary[0][first+num],ary[1][first+num],0,getcl);
                }
                }
                //    printf("sum :%d\n",student[i].g[run].sum);
                if( student[i].g[run].sum >50)
                {
                    printf("  \t \t HOME TIME ");

                    student[i].g[run].pos= home(color_g[i],first,first+num);
                    if(  student[i].g[run].pos == 6)
                    {
                        cout<<"\t\t\t FINISHED"<<endl;
                        student[i].g[run].status=0;
                        student[i].win+=1;
                        if(student[i].win==4)
                        {
                            cout<<"\t\t\t\t*******WINNER IS :"<<i<<"  ******"<<endl;
                            return;
                        }
                    }

                    break;
                }

                movement(first,(first+num),color_g[i]);
                student[i].g[run].pos=(student[i].g[run].pos+num)%52;

                if(magic!=1)
                    break;
            }
            if(magic && num!=6)
            {
                int op;
                magic=0;
                printf("Cast a spell:\n1. roll again\n2. Block an opponent\nSpell: ");
                scanf("%d",&spell);
                if(spell==2)
                {
                    printf("Enter opponent number: ");
                    scanf("%d",&op);
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
     if(x == 9)
         a = 51;
      else if( x == 2)
         a = 12;
       else if(x == 14)
         a = 25;
        else if (x == 1)
          a == 38;
    return a;
}


void home_assgn()
{


       for(int i=0;i<6;i++)
       {
           red_hm[0][i]=98+45*i;
           red_hm[1][i]=368;

       }


       for(int i=0;i<6;i++)
       {
           grn_hm[0][i]=368;
           grn_hm[1][i]=98+45*i;

       }


       for(int i=0;i<6;i++)
       {
           blu_hm[0][i]=368;
           blu_hm[1][i]=638-45*i;
       }


       for(int i=0;i<6;i++)
       {
           ylw_hm[0][i]=638-45*i;
           ylw_hm[1][i]=368;

       }

}


int home(int clr,int first,int pos)
{
     int ab,remn,tmp,rx,ry;
        int bdb;
         tmp=diamond(clr);
        if(first > 5)
        {movement(first,tmp,clr);
          bdb=0;
        remn=pos-tmp;
        flood_fill(ary[0][tmp],ary[1][tmp],0,clr);
           }
         else{
                  if(pos > 6)
                   {
                      return first;
                     }
                bdb=first;
                 remn=pos;
               }
       //printf(" bdb %d remn %d",bdb,remn);
        switch(clr)
         {
            case 1:    if(bdb > 0)
                         {
                            setcolor(1);
                            rx=blu_hm[0][bdb-1];
                            ry=blu_hm[1][bdb-1];
                            circle(rx,ry,12);
                            flood_fill(rx,ry,1,3);
                          }
                         for(ab=bdb;ab<remn;ab++)
                             { clr=3;
                             setcolor(clr);
                             rx=blu_hm[0][ab];
                             ry=blu_hm[1][ab];
                             delay(200);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,1);
                             delay(200);
                             setcolor(1);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,1,clr);
                             }
                             setcolor(clr);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,1);
                              break;

           case 2:    if(bdb > 0)
                         {
                            setcolor(2);
                            rx=grn_hm[0][bdb-1];
                            ry=grn_hm[1][bdb-1];
                            circle(rx,ry,12);
                            flood_fill(rx,ry,2,3);
                          }
                           for(ab=bdb;ab<remn;ab++)
                             {  clr=3;
                             setcolor(clr);
                             rx=grn_hm[0][ab];
                             ry=grn_hm[1][ab];
                             delay(200);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,2);
                             delay(200);
                             setcolor(2);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,2,clr);
                             }
                             setcolor(clr);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,2);
                              break;

          case 9:        if(bdb > 0)
                         {
                            setcolor(9);
                            rx=red_hm[0][bdb-1];
                            ry=red_hm[1][bdb-1];
                            circle(rx,ry,12);
                            flood_fill(rx,ry,9,3);
                          }
                          for(ab=bdb;ab<remn;ab++)
                             {     clr=3;
                             setcolor(clr);
                             rx=red_hm[0][ab];
                             ry=red_hm[1][ab];
                             delay(200);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,9);
                             delay(200);
                             setcolor(9);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,9,clr);
                             }
                             setcolor(clr);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,9);
                              break;



         case 14:    if(bdb > 0)
                         {
                            setcolor(14);
                            rx=ylw_hm[0][bdb-1];
                            ry=ylw_hm[1][bdb-1];
                            circle(rx,ry,12);
                            flood_fill(rx,ry,14,3);
                          }
                          for(ab=bdb;ab<remn;ab++)
                             { clr=3;
                             setcolor(clr);
                             rx=ylw_hm[0][ab];
                             ry=ylw_hm[1][ab];
                             delay(200);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,14);
                             delay(200);
                             setcolor(14);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,14,clr);
                             }
                             setcolor(clr);
                             circle(rx,ry,12);
                             flood_fill(rx,ry,clr,14);
                              break;

        }


     return ab;

}

