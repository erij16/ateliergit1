#ifndef E_H_INCLUDED
#define E_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
struct camera
{
SDL_Surface *image;
SDL_Rect pos_image;
SDL_Rect pos_camera;
int sens;
};
typedef struct camera camera;
void initialiser(camera *c);
void afficher(camera *c,SDL_Surface *screen);
void scrolling(camera *c);
void free_m(camera *c);
#endif // E_H_INCLUDED
