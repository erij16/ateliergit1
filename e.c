#include "e.h"
void initialiser(camera *c)
{
c->image=IMG_Load("bg_level1.png");
c->pos_image.x=0;
c->pos_image.y=0;
c->pos_camera.x=0;
c->pos_camera.y=0;
c->pos_camera.w=1200;
c->pos_camera.h=670;
c->sens=2;
}
void afficher(camera *c,SDL_Surface *screen)
{
SDL_BlitSurface(c->image,&c->pos_camera,screen,&c->pos_image);
}

void scrolling(camera *c)
{

if(c->sens==0)
{

c->pos_camera.x+=15;
if(c->pos_camera.x>=5624-1200)
c->pos_camera.x=5624-1200;


}
if(c->sens==1)
{

c->pos_camera.x-=15;
if(c->pos_camera.x<=0)
c->pos_camera.x=0;

}
if(c->sens==3)
{
c->pos_camera.y=15;

}
if(c->sens==4)
{
c->pos_camera.y=0;

}
}
void free_m(camera *c)
{
SDL_FreeSurface(c->image);
}
