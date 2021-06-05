#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
void instruct();
void main()
{
	clrscr();
	int gd=DETECT,gm;
	long int x=300,ry1[10000],ry2[10000],i=0,c=0; //ry1 and ry2 here are for the co-ordinates of the white lines on the road
	long int car=0,cx[10000],cy[10000],I=0,l=210,u=370,so=500,go=0,score=0,m=0; //cx and cy are for the x and y co-ordinates of the cars, 'so' acts as a parameter for the sound function, go is to run the car till terminated, score is to count the number of cars overtaken.
	char ch='s';
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	instruct();
	label:
	if(go!=0)
		ch=getch();
	while(ch!='t')
	{
		go=1;
		//sound(so);
		setcolor(GREEN);
		rectangle(x,426,x+20,450);//player's car
		//road
		setcolor(BLUE);
		rectangle(200,-10,400,1000);
		//white lines in the middle of the road
		setcolor(WHITE);
		if (c==0)
		{
			ry1[0]=-20;
			ry2[0]=-2;
		}
		if(c%100==0 && c!=0)
		{
			i++;
			ry1[i]=-20;
			ry2[i]=-2;
		}
		for(int j=0;j<=i;j++)
		{
			ry1[j]++;
			ry2[j]++;
			line(300,ry1[j],300,ry2[j]);
		}
		c++;
		if(i==9999)
			i=0;
		setcolor(RED);
		//obstacle cars
		if(car==0)
		{
			cy[0]=0;
			cx[0]=random(u-l+1)+l;
		}
		if(car%50==0 && car!=0) //the white lines loop is %100, and here it is %50 as to get more cars on the screen.
		{
			I++;
			cx[I]=random(u-l+1)+l;
			cy[I]=0;
		}
		for(int J=0;J<=I;J++)
		{
			cy[J]+=2;
			rectangle(cx[J],cy[J],cx[J]+20,cy[J]+25);
			if(cy[J]+24==426 && cx[J]>=x && cx[J]<=x+24||cy[J]+24==426 && cx[J]+24<=x+24 && cx[J]+24>=x)
			{ //this loop is to check if the cordinates of the players car touch or match that of the obstacles which is out(game over)
				goto GO;
			}
			else if(cx[J]==x+20 &&cy[J]+20>=426&&cy[J]<=450)
			{
				goto GO;
			}
			else if(cx[J]+20==x&&cy[J]+20>=426&&cy[J]<=450)
			{
				goto GO;   //GO here is when the player is out
			}
			if(cy[m]>426)
			{
				score++;
				m++;
			}
		}
		car++;
		if(I==9999)
			I=0;
		if(x==200||x+20==400)
		{
			GO:
			//nosound();
			for(int z=0;z<=3;z++)
			{

				//sound(250);
				setcolor(z);
				settextstyle(0,0,0+z);//text font=0, direction=0 (HORIZ_DIR=default), character size
				outtextxy(100,300,"GAME OVER!!!");
				delay(1000);
				cleardevice();   //clears graphics

			}
			//nosound();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYOU HAVE OVERTAKEN  "<<score<<" CARS\n";
			cout<<"SCORE:"<<score*10;
			delay(5000);
			exit(1);
		}
		if(kbhit()) //checks if the console entered is valid or not
		{
			goto label;
		}
		if(ch!='s')
			switch(ch)
		{
			case 'a':x--;
					break;
			case 'A':x--;
					break;
			case 'd':x++;
					break;
			case 'D':x++;
					break;
			case 'P':
			case 'p':while(!kbhit())
				outtextxy(300,300,"GAME PAUSED");
				break;

			default:while(!kbhit())  //if what you have entered is not valid, i.e as per instructions, then it shows game paused.
				outtextxy(300,300,"INVALID\n Press a or d to continue");
				break;
		}
		delay(10);
		cleardevice();
		so+=20;
		if(so==1000)
			so=500;  //repetition of sound
		}//while loop ends
		cleardevice();
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\nYOU HAVE CHOSEN TO TERMINATE";
		cout<<"YOU HAVE OVERTAKEN "<<score<<" CARS";
		cout<<"\nSCORE "<<score*10;
		//nosound();
		getch();
		}
		void instruct()
		{
			for(int i=0;i<=50;i++)
			{
				//instructions
				settextstyle(0,0,3);
				setcolor(WHITE);
				rectangle(95,110,635,340);
				setcolor(CYAN);
				outtextxy(101,130,"A -> LEFT");
				outtextxy(101,160,"D -> RIGHT");
				outtextxy(101,190,"S -> CONTINUE IN ");
				outtextxy(101,220,"     A STRAIGHT LINE ");
				outtextxy(101,250,"T -> TERMINATE");
				outtextxy(101,280,"P -> PAUSE");
				outtextxy(101,310,"PRESS A OR D TO RESUME");
				delay(50);
			}
			settextstyle(0,0,0);
		}
