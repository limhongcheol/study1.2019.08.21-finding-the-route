#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
	COORD Pos = {x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void setColor(int foreground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = foreground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}
char map1[14][56] = {
	{"1111111111111111111111111111111111111111111111111111111"},
	{"1200000000000000000000000000000000000000000000000000001"},
	{"1001000000000000000000000000000000000000000000000000001"},
	{"1000100000000000000000000000000000000000000000000000001"},
	{"1000010000000000000000000000000000000000000000000000001"},
	{"1000001000000000000000000000000000000000000000000000001"},
	{"1000000100000000000000000000000000000000000000000000001"},
	{"1000000010000000000000000000000000000000000000000000001"},
	{"1000000001000000000000000000000000000000000000000000001"},
	{"1000000000100000000000000000000000000000000000000000001"},
	{"1000000000010000000000000000000000000000000000000000001"},
	{"1000000000001000000000000000000000000000000000000000001"},
	{"1000000000000100000000000000000000000000000000000000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};
void drawmap(int*x, int*y) {
	system("cls");
	int h, w;
	for (h = 0; h < 14; h++) {
		for (w = 0; w < 56; w++) {
			char temp = map1[h][w];
			if (temp == '0') {
				printf(" ");
			}
			else if (temp == '1') {
				printf("@");
			}
			else if (temp == '2') {
				*x = h;
				*y = w;
				printf("o");
			}
		}
		printf("\n");
	}
	//Sleep(3000);
}
void move(int*x, int*y, int _x, int _y) {
	char mapObject = map1[*y + _y][*x + _x];
	if (mapObject != '1') {
		gotoxy(*x, *y);	
		printf(" ");
		gotoxy(*x + _x, *y + _y);
		printf("o");
		*x = *x + _x;
		*y = *y + _y;
	}
}
int main() {
	int a = 0;
	int x=2;
	int y=2;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//커서 없애는 함수
	CONSOLE_CURSOR_INFO ConsoleCursor;//커서 없애는 함수
	ConsoleCursor.bVisible = 0;//커서 없애는 함수
	ConsoleCursor.dwSize = 1;//커서 없애는 함수
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor); //커서 없애는 함수
	drawmap(&x, &y);
	while (a == 0) {
		char temp;
		temp = _getch();
			if (temp == 'w' || temp == 'W') {
				move(&x, &y, 0, -1);
			}
			if (temp == 'A' || temp == 'a') {
				move(&x, &y, -1, 0);
			}
			if (temp == 's' || temp == 'S') {
				move(&x, &y, 0, 1);
			}
			if (temp == 'd' || temp == 'D') {
				move(&x, &y, 1, 0);
			}
		//	else { printf(" "); };
		}
		//for (int title1 = 0; title1 < 15; title1++) {
			//system("cls");
			//printf("\n\n\n\n");
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), title1);
			//printf("임");
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), title1 + 1);
			//printf("진");
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), title1 - 1);
			//printf("석");
		   //Sleep(1000);
		   //}
	return 0;
	}
