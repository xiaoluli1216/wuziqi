#include<graphics.h>
#include<stdio.h>
#include<math.h>
int flag = 0; //��Ǻ����
int ChessMap[20][20] = { 0 }; //��¼���̵�����
void initGame()
{
	initgraph(667, 500,SHOWCONSOLE);
	IMAGE img;
	loadimage(&img, "bk.jpg");
	putimage(0, 0, &img);
	setlinecolor(BLACK);
	for (int i = 0;i < 20;i++)
	{
		line(0, 25 * i, 500, 25 * i);
		line(i * 25, 0, i * 25, 500);
	}
	line(500, 0, 500, 500);
	settextcolor(BLACK);
	setbkmode(0);
	outtextxy(530, 100, "���1������");
	outtextxy(530, 120, "���2������");
}
int judge(int MapX, int MapY)
{
	int temp = 2 - flag % 2; 
	//�ж�����
	for (int i = MapX-4 , j = MapY;i <= MapX;i++)
	{
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i+1][j] && temp == ChessMap[i+ 2][j]
			&& temp == ChessMap[i+ 3][j] && temp == ChessMap[i+ 4][j])
		{
			return 1;
		}
	}
	for (int i = MapX, j = MapY-4;j <= MapY;j++)
	{
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i][j + 1] && temp == ChessMap[i][j + 2]
			&& temp == ChessMap[i][j + 3] && temp == ChessMap[i][j + 4])
		{
			return 1;
		}
	}
	for (int i = MapX-4, j = MapY - 4;i<=MapX,j <= MapY;i++,j++)
	{
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i+1][j + 1] && temp == ChessMap[i+2][j + 2]
			&& temp == ChessMap[i+3][j + 3] && temp == ChessMap[i+4][j + 4])
		{
			return 1;
		}
	}
	for (int i = MapX - 4, j = MapY + 4;i <= MapX, j >= MapY;i++, j--)
	{
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j - 1] && temp == ChessMap[i + 2][j - 2]
			&& temp == ChessMap[i + 3][j - 3] && temp == ChessMap[i + 4][j - 4])
		{
			return 1;
		}
	}
	return 0;
}
void PlayGame()
{
	int ChessX = 0, ChessY = 0;
	int MapX = 0, MapY = 0; //��¼���̵��±�
	MOUSEMSG Msg;
	HWND hwnd = GetHWnd();
	while (1)
	{
		Msg = GetMouseMsg();
		/*if (Msg.uMsg == WM_LBUTTONDOWN) {
			printf("X:%d\n Y:%d\n", Msg.x, Msg.y);
		}
		else if (Msg.uMsg == WM_RBUTTONDOWN) {
			printf("X:%d\n Y:%d\n", Msg.x, Msg.y);
		}*/
		for (int i = 1;i < 20;i++)
		{
			for (int j = 1;j < 20;j++)
			{
				if (abs(Msg.x - j * 25) < 12 && abs(Msg.y - i * 25) < 12)
				{
					ChessX = j * 25;
					ChessY = i * 25;
					MapX = i;
					MapY = j;
				}
			}
		}
		if (Msg.uMsg == WM_LBUTTONDOWN)
		{
			if (ChessMap[MapX][MapY] != 0)
			{
				MessageBox(hwnd, "�����������ˣ�������ѡ��", "������", MB_OK);
				continue;
			}
			if (flag % 2 == 0)
			{
				setfillcolor(BLACK);
				solidcircle(ChessX, ChessY, 10);
				ChessMap[MapX][MapY] = 1;
			}
			else
			{
				setfillcolor(WHITE);
				solidcircle(ChessX, ChessY, 10);
				ChessMap[MapX][MapY] = 2;
			}
			flag++;
		}
		if (judge(MapX, MapY))
		{
			if (1 == flag % 2)
			{
				MessageBox(hwnd,"���1������ʤ��","Gameover",MB_OK);
				return;
			}else
			{
				MessageBox(hwnd,"���2������ʤ��","Gameover", MB_OK);
				return;
			}
		}
	}
}

int main()
{
	initGame();
	PlayGame();
	getchar();
	return 0;
}