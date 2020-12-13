#include<stdio.h>
#include<string.h>

#ifndef __USER_COLOR__
#define __USER_COLOR__

#define GREEN 0x009801
#define RED 0x009802
#define YELLOW 0x009803
#define BLUE 0x009804
#define MAGENTA 0x009805
#define CYAN 0x009806
#define WHILTE 0x009807
#define GRAY 0x009808
#define BRED 0x009809
#define BGREEN 0x00980a
#define BYELLOW 0x00980b
#define BBLUE 0x00980c
#define BMAGENTA 0x00980d
#define BCYAN 0x00980e
#define BWHITE 0x00980f
#define BLACK 0x009810
char *color(char *str, int colF, int colB);

char *colorF(char *str, int col)
{
	return color(str, col, -1);
}

char *colorB(char *str, int col)
{
	return color(str, -1, col);
}

char *colorFB(char *str, int colF, int colB)
{
	return color(str, colF, colB);
}

char *color(char *str, int colF, int colB)
{
	static char buffer[1024];

	strcpy(buffer, "\x01b[");

	if(colF != -1)
		switch(colF)
		{
			case BLACK:
				strcat(buffer, "30");
				break;
			case GREEN:
				strcat(buffer, "32");
				break;
			case RED:
				strcat(buffer, "31");
				break;
			case YELLOW:
				strcat(buffer, "33");
				break;
			case BLUE:
				strcat(buffer, "34");
				break;
			case MAGENTA:
				strcat(buffer, "35");
				break;
			case CYAN:
				strcat(buffer, "36");
				break;
			case WHILTE:
				strcat(buffer, "37");
				break;
			case GRAY:
				strcat(buffer, "90");
				break;
			case BRED:
				strcat(buffer, "91");
				break;
			case BGREEN:
				strcat(buffer, "92");
				break;
			case BYELLOW:
				strcat(buffer, "93");
				break;
			case BBLUE:
				strcat(buffer, "94");
				break;
			case BMAGENTA:
				strcat(buffer, "95");
				break;
			case BCYAN:
				strcat(buffer, "96");
				break;
			case BWHITE:
				strcat(buffer, "97");
				break;
		}

	if(colB != -1)
		switch(colB)
		{
			case BLACK:
				strcat(buffer, ";40");
				break;
			case GREEN:
				strcat(buffer, ";42");
				break;
			case RED:
				strcat(buffer, ";41");
				break;
			case YELLOW:
				strcat(buffer, ";43");
				break;
			case BLUE:
				strcat(buffer, ";44");
				break;
			case MAGENTA:
				strcat(buffer, ";45");
				break;
			case CYAN:
				strcat(buffer, ";46");
				break;
			case WHILTE:
				strcat(buffer, ";47");
				break;
			case GRAY:
				strcat(buffer, ";100");
				break;
			case BRED:
				strcat(buffer, ";101");
				break;
			case BGREEN:
				strcat(buffer, ";102");
				break;
			case BYELLOW:
				strcat(buffer, ";103");
				break;
			case BBLUE:
				strcat(buffer, ";104");
				break;
			case BMAGENTA:
				strcat(buffer, ";105");
				break;
			case BCYAN:
				strcat(buffer, ";106");
				break;
			case BWHITE:
				strcat(buffer, ";107");
				break;
		}
	
	strcat(buffer, "m");
	strcat(buffer, str);
	strcat(buffer, "\x01b[39;49m");

	return buffer;
}

char *str_(int i, int len)
{
	static char buffer[32];
	sprintf(buffer, "%*d",len, i);
	return buffer;
}

char *str(int i)
{
	return str_(i, 0);
}

#endif
