#include "maze.h"

		maze::maze()
		{
			printf("ctor called");
			playerison = false;
			endpoint = false;
			picetype = all;
		}
        void maze::print(int x, int y,int size, int linethicness,SDL_Surface* screen)
        {
			printf("drawing to screen");
                if (playerison)
                {
                    SDL_Rect p = {x + 0, y + 0, size, size};
                    SDL_FillRect(screen, &p,0x00FF00);
                }
                else if (endpoint)
                {
                    SDL_Rect p = {x + 0, y + 0, size, size};
                    SDL_FillRect(screen, &p,0x0000FF);
                }
				else
				{
					SDL_Rect p = {x + 0, y + 0, size, size};
                    SDL_FillRect(screen, &p,0x020200);
				}
                switch (picetype)
                {
                    case east:{
                        SDL_Rect q = {x + 0, y + 0, size, linethicness};
                        SDL_Rect b = {x + 0, y + size - linethicness, size, linethicness};
                        SDL_FillRect(screen, &q,0x000000);
						SDL_FillRect(screen, &b,0x000000);}
                        break;
                    case eastwastnorth:{
                        SDL_Rect f = {x + 0, y + size - linethicness, size, linethicness};
						SDL_FillRect(screen, &f,0x000000);}
                        break;
                    case eastwestsouth:{
                        SDL_Rect g = {x + 0, y + 0, size, linethicness};
						SDL_FillRect(screen, &g,0x000000);}
                        break;
                    case north:{
                        SDL_Rect c = {x + 0, y + 0, linethicness, size};
                        SDL_Rect d = {x + size - linethicness, y + 0, linethicness, size};
                        SDL_FillRect(screen, &c,0x000000);
						SDL_FillRect(screen, &d,0x000000);}
                        break;
                    case northeast:{
                        SDL_Rect h = {x + 0, y + 0, linethicness, size};
                        SDL_Rect i = {x + 0, y + 0, size, linethicness};
                        SDL_FillRect(screen, &h,0x000000);
						SDL_FillRect(screen, &i,0x000000);}
                        break;
                    case northwest:{
                        SDL_Rect j = {x + size - linethicness, y + 0, linethicness, size};
                        SDL_Rect k = {x + 0, y + 0, size, linethicness};
                        SDL_FillRect(screen, &j,0x000000);
						SDL_FillRect(screen, &k,0x000000);}
                        break;
                    case southeast:{
                        SDL_Rect l = {x + 0, y + size - linethicness, size, linethicness};
                        SDL_Rect m = {x + 0, y + 0, linethicness, size};
                        SDL_FillRect(screen, &l,0x000000);
						SDL_FillRect(screen, &m,0x000000);}
                        break;
                    case southwest:{
                        SDL_Rect n = {x + 0, y + size - linethicness, size, linethicness};
                        SDL_Rect o = {x + size - linethicness, y + 0, linethicness, size};
                        SDL_FillRect(screen, &n,0x000000);
						SDL_FillRect(screen, &o,0x000000);}
                        break;
                    case noenterable:{
                        SDL_Rect p = {x + 0, y + 0, size, size};
						SDL_FillRect(screen, &p,0x000000);}
                        break;
                }
        }
