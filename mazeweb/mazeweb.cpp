// mazeweb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "maze.h"
using namespace std;
const int mazesize = 30;
int moves = 0;
int bestmoves = 0;
maze map[mazesize][mazesize];
SDL_Surface *screen;
int with = 820;
int hight = 820;
int bpp = 32;
bool win = false;
int beginx = 0;
int beginy = 0;
int numFrames = 0;
int mousex = 0;
int mousey = 0;
bool currentlyred = true;
bool checkwin()
{
            if (moves >= mazesize*mazesize)
            {
				cout<<"draw"<<endl;
                return true;
            }
            //check vertical
            for (int i = mazesize - 1; i >= 0; i--)
            {
                for (int j = mazesize - 1; j >= 4; j--)
                {
                    if (map[i][j].red && map[i][j - 1].red && map[i][j - 2].red && map[i][j - 3].red)
                    {
						cout<<"red wins"<<endl;
                        return true;
                    }
                    if (map[i][j].yelow && map[i][j - 1].yelow && map[i][j - 2].yelow && map[i][j - 3].yelow)
                    {
                        cout<<"yelow wins"<<endl;
                        return true;
                    }
                }
            }
            for (int i = mazesize - 1; i >= 4; i--)
            {
                for (int j = mazesize - 1; j >= 0; j--)
                {
                    if (map[i][j].red && map[i - 1][j].red && map[i - 2][j].red && map[i - 3][j].red)
                    {
						cout<<"red wins"<<endl;
                        return true;
                    }
                    if (map[i][j].yelow && map[i-1][j].yelow && map[i-2][j].yelow && map[i-3][j].yelow)
                    {
                        cout<<"yelow wins"<<endl;
                        return true;
                    }
                }
            }
            for (int i = mazesize - 1; i >= 4; i--)
            {
                for (int j = mazesize - 1; j >= 4; j--)
                {
                    if (map[i][j].red && map[i - 1][j- 1].red && map[i - 2][j-2].red && map[i - 3][j-3].red)
                    {
						cout<<"red wins"<<endl;
                        return true;
                    }
                    if (map[i][j].yelow && map[i - 1][j-1].yelow && map[i - 2][j-2].yelow&& map[i - 3][j-3].yelow)
                    {
                        cout<<"yelow wins"<<endl;
                        return true;
                    }
                }
            }
            return false;
}
void drawmaze()
{
	//SDL_LockSurface(screen);
	        int space = 25;
            int linethicness = 5;
            int locationx = 20;
            int locationy = 30;
            for (int i = 0; i < mazesize; i++)
            {
                locationy = 30;
                for (int j = 0; j < mazesize; j++)
                {
                    locationy += space;
                    map[i][j].print(locationx ,locationy,space,linethicness);
                }
                locationx += space;
            }
			SDL_UnlockSurface(screen);
			SDL_UpdateRect(screen, 0, 0, with, hight);
}
void geteditminput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	int x, y;
	SDL_GetMouseState(&x, &y);
	if( event.type == SDL_MOUSEBUTTONDOWN )
    {
			int space = 25;
            int linethicness = 5;
            int locationx = 20;
            int locationy = 30;
			int selectedcolum = 0;
            for (int i = 0; i < mazesize; i++)
            {
                locationy = 30;
                for (int j = 0; j < mazesize; j++)
                {
                    locationy += space;
					if (x >= locationx && x <= locationx + space)
					{
						selectedcolum = i;
						cout<<x;
						break;
					}
                }

                locationx += space;
            }
			for (int j = (mazesize - 1); j >= 0; j--)
                {
					if (map[selectedcolum][j].used == false)
					{
						if (currentlyred)
						{
							map[selectedcolum][j].red = true;
							currentlyred = false;
						}
						else
						{
							map[selectedcolum][j].yelow = true;
							currentlyred = true;
						}
						map[selectedcolum][j].used = true;
						break;
					}
                }
	}
}
void looplogic()
{
	geteditminput();
	drawmaze();
	checkwin();
}
void editloop()
{
	geteditminput();
	drawmaze();
}
extern "C"
{
	int blankstart()
{
	cout<<"begin"<<endl;
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	screen = SDL_SetVideoMode(with, hight, bpp, SDL_SWSURFACE);  
	if ( screen == NULL ) 
	{
		cout<<"no canvas"<<endl;
	}
	drawmaze();
	cout<<"start"<<endl;
	emscripten_set_main_loop(looplogic,0,0);
	return 0;
}
}
//-s EXPORTED_FUNCTIONS='["_startall", "startall"]'
maze::maze()
		{
			used = false;
			red = false;
			yelow = false;
		}
maze::~maze()
{
}
void maze::print(const int x, const int y, const int size, const int linethicness)
        {
				if (yelow)
				{
				    SDL_Rect p = {x + 0, y + 0, size, size};
                    SDL_FillRect(screen, &p,SDL_MapRGB( screen->format, 0xFF, 0xA5, 0x00 ));
				}
				else if (red)
				{
				    SDL_Rect p = {x + 0, y + 0, size, size};
                    SDL_FillRect(screen, &p,SDL_MapRGB( screen->format, 0xFF, 0x00, 0x00 ));
				}
				else
				{
					SDL_Rect p = {x + 0, y + 0, size, size};
                    SDL_FillRect(screen, &p,SDL_MapRGB( screen->format, 0xF2, 0xF2, 0xF0 ));
				}
        }