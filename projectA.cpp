#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y);

int main()
{
	system("mode con: cols=50 lines=25");
	
	int key;
	int x=10,y=5;
	int ox,oy;
	
	gotoxy(x,y);
	printf("��");
	
	gotoxy(12,2);
	printf("exit");
	
	while(1)
	{
		key = getch();
		ox=x;
		oy=y;
		switch(key)
		{
			case 119: y--; break;
			case 97: x-=2; break;
			case 115: y++; break;
			case 100: x+=2; break;
		}
		
		if(x>15){x=ox;}
		if(y>10){y=oy;}
		if(x<5){x=ox;}
		if(y<1){y=oy;}
		
		gotoxy(20,20);
		printf(" x:%d y:%d",x,y);
		
		// x�� 13�� �����鼭 y�� 3�� ������ �ݺ������� �������ͼ� "Ż�⼺��"�� ����ض� 
		if(12==x && 2==y){ break;} 
		
		
		gotoxy(ox,oy);
		printf("  ");
		
		gotoxy(x,y);
		printf("��");
		
	 } 
	 
	 gotoxy(x,y);
	  printf("Ż�⼺��");
	  
	  while(1){}
	  
	 
	 return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
