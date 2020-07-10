#pragma once 
#include "Struct.h"
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>

#define Enter 13
//const int WHITE=15;
#define PASSWORD "abcdef"
//const int WHITE=15;
#define AQUA 3
#define PURPLE 5
#define LIGHT_AQUA 11
#define LIGHT_YELLOW 14
#define LIGHT_GREEN 10 
#define BLACK 0
#define WHITE 7
#define GREEN 2
#define BRIGHT_WHITE 15
#define BLUE 1
#define LIGHT_RED 12



char* Pwd () {
	char S[40];
	int i=0;
	while ((S[i]= getch()) != Enter ) {
		printf ("%c", '*') ;
		i++ ;
	}
	S[i]='\0';
	return S;
}

int CheckPwd () {
	int dem =0;
	for ( dem =1 ; dem <=3 ; dem++) {
		printf( "Password :");
		if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
		else printf ( "\nPassword sai. Hay nhap lai\n")  ;
	}
	return 0;
}

void gotoxy(short x,short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

int wherex( void ) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void ) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
//Clear to end of line
void clreol( ) {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
	                            info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

void SetColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//xoa noi dung console
void cls(HANDLE hConsole) {
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		return;
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
	                                dwConSize, coordScreen, &cCharsWritten))
		return;
	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		return;
	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
	                                dwConSize, coordScreen, &cCharsWritten))
		return;
	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(hConsole, coordScreen);
}

void clrscr_f() {
	system("cls");
}

void clrscr() {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hCon);
}

void normalBGColor()
{
	SetColor(LIGHT_YELLOW);
	SetBGColor(AQUA);
}

void normalTextColor() {
	SetColor(LIGHT_YELLOW);
}

void anConTro() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

void hienConTro() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
//resize console
void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//an hien con tro
void ShowCur(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

char getCursorChar() {  /// Function which returns character on console's cursor position
	char c = '\0';
	CONSOLE_SCREEN_BUFFER_INFO con;
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hcon != INVALID_HANDLE_VALUE &&
	        GetConsoleScreenBufferInfo(hcon, &con)) {
		DWORD read = 0;
		if (!ReadConsoleOutputCharacterA(hcon, &c, 1,
		                                 con.dwCursorPosition, &read) || read != 1
		   )
			c = '\0';
	}
	return c;
}

char readChar(int x, int y) { /// Function which reads character at specific coordinates
	gotoxy(x, y);
	char ccccc = getCursorChar();
	return ccccc;
}

