#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "e.h"
int main(int argc,char *argv[])
{
    SDL_Surface *screen =NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Event event;
    screen=SDL_SetVideoMode(1200,670, 32,SDL_HWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("game",NULL);
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    Mix_Music *musique=NULL;
    musique=Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(musique,-1);


    camera c;
initialiser(&c);
int continuer=1;
    while(continuer == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;

            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE://pour quitter
                continuer=0;

                break;

	    case SDLK_RIGHT :
		{
			c.sens=0;
		}break;

	    case SDLK_LEFT :
		{
			c.sens=1;	
		}break;
            case SDLK_UP:
		{
			c.sens=3;
                        	
		}break;
            case SDLK_DOWN:
		{
			c.sens=4;
                        	
		}break;

            }
            break;
          case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
		case SDLK_RIGHT :
		{
			c.sens=2;
		}break;

	    	case SDLK_LEFT :
		{
			c.sens=2;		
		}break;
                case SDLK_UP:
		{
                        
			c.sens=2;
                        	
		}break;
                case SDLK_DOWN:
		{
                        
			c.sens=2;
                        	
		}break;
                

                
            }
            break;
	   
        }

       afficher(&c,screen);
       scrolling(&c);
       SDL_Flip(screen);
       SDL_Delay(20);
}

free_m(&c);
 SDL_Quit();

    return EXIT_SUCCESS ;
}
