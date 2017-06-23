#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void screen();
void fill(const int,const int,const int,const int);
void square(const int,const int,const int,const int);
void line(const int,const int,const int,const int);

int main()
{
	int driver = VGA;
	int mode = VGAHI;
	
	initgraph(&driver,&mode,"..\\Bgi");
	
	screen();
	
	for(int i = 0; i < 15; i++)
	{
		setcolor((i + 1));
		square((141 + i),(69 + i), (499 - i), (427 - i)); 
	}
	setcolor(9);
	for(int j = 0; j < 19; j++)
	{
		square((156 + j), (84 + j), (484 - j), (412 - j));
	}
	setcolor(12);
	square((156 + j),(84 + j), (484 - j),(412 - j));
	for(int k = 0; k < 9; k++)
	{
		line((176 +(k * 36)),104,(176 + (k * 36)),392);
		line(176,(104 + (36 * k)),464,(104 + (36 * k)));
	}
	setcolor(15);
	for(int l = 0; l < 8; l++)
	{
		for(int m = 0; m < 8;m++)
		{
			if(((m % 2) + (l % 2)) == 1)
			{
				fill((176 + (m * 36)), (104 + (l * 36)), (212 + (m * 36)), (140 + (l * 36)));
			}				
		}
	}
	char English[8][3] = {"H","G","F","E","D","C","B","A"};
	char Numbers[8][3] = {"1","2","3","4","5","6","7","8"};
	getch();
	return 0;
}

void square(const int i, const int j, const int k, const int l)
{ 
   line(i, j, k, j); 
   line(k, j, k, l); 
   line(k, l, i, l); 
   line(i, l, i, j); 
}

void fill(const int i, const int j, const int k, const int l)
{ 
   int ymin=((j >= l)? l : j); 
   int ymax=((j <= l)? l : j);
   
   for(int count = (ymin + 1); count < ymax; count++)
   {	
      line((i + 1), count,(k - 1), count); 
   }
}

void line(const int i, const int j, const int k, const int l)
{ 
   int color =getcolor();
   
   int i2 = i;
   int j2 = j; 
   int k2 = k; 
   int l2 = l;
   
   if(i > l) 
   { 
      i2 = k; 
      j2 = l; 
      k2 = i; 
      l2 = j;
   }
   
   int x = abs(k2 - i2);
   int y = abs(l2 - j2); 
   
   int add_sub = ((l2 >= j2) ? 1 : -1);
   
   if(x  > y) 
   { 
      int y2 = (2 * y); 
      int 2y_2x = (2 * (y - x)); 
      int z = ((2 * y) - x); 
      int x = i2; 
      int y = j2;
	  
      putpixel(x,y,color); 
	  
      while(x < k2) 
      { 
         x++;
		 
         if(z < 0) 
         {
			 z += 2y;
	     }
         else 
         { 
           y += add_sub;
           z += 2y_2x; 
         } 
		 
         putpixel(x,y,color); 
      } 
   } 
   
   else 
   { 
      int x2 = (2 * x); 
      int 2x_2y = (2 * (x - y)); 
      int z = ((2 * x) - y); 
      int x = i; 
      int y = j;
	  
      putpixel(x,y,color);
	  
      while(y != l2) 
      { 
         y += add_sub;
		 
         if(z < 0) 
         {
	         z += x2;
         }
         else
         { 
             x++;
             z += 2x_2y;
         } 
		 
         putpixel(x,y,color);
      }
   }
} 

void screen( ) 
{
	setfillstyle(1, 1);
	bar(262, 26, 365, 38);
	settextstyle(0, 0, 1);
	
	setcolor(15);
	
	outtextxy(5, 5, "******************************************************************************");
	outtextxy(5, 17, "*-**************************************************************************-*");
	outtextxy(5, 29, "*------------------------------               -------------------------------*");
	outtextxy(5, 41, "*-**************************************************************************-*"); 
	outtextxy(5, 53, "*-**************************************************************************-*"); 
	setcolor(11); 
	outtextxy(270 , 29, "Game Board"); 
	setcolor(15); 
	
	for(int count = 0; count <= 30; count++) 
	{
		outtextxy(5, (65 + (count * 12)), "*-*                                                                *-*");
	}
	outtextxy(5, 438,"*-**************************************************************************-*"); 
	outtextxy(5, 450,"*-------------------------                          -------------------------*"); 
	outtextxy(5, 462,"******************************************************************************"); 
	
	setcolor(12); 
	outtextxy(229, 450, "Press any Key to exit."); 
}
