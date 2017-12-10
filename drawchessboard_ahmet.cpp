/*
   Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>
   This file is created by : Nitin Jain (nitin.j4@samsung.com)
*/

/* Sample program:  Draw a Chess Board  by using SDL_CreateSoftwareRenderer API */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "sdl_tools.cpp"
#include "time_ahmet.cpp"
class sdl_gui_text{

public :
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    SDL_DisplayMode mode;
    SDL_Color foregroundColor= {205,205,0};
    SDL_Color backgroundColor= {0,25,0};
       char *text_buffer="hello";
     SDL_Rect textLocation= {100,100,0,0};

    
    
int error(){};

int init(){
	text_buffer=(char *)malloc(500);
    sprintf(text_buffer,"%s", now());

};

int draw(){

if(surface==NULL){ /*erroor ..!*/};


    SDL_Delay(30);// slow down to 2.2 fps
     TTF_Init();
    char fnt[800];
    //fnt= (char*)malloc(  1040 );
    sprintf ( fnt ,"%s%s", getenv("PWD") ,"0.ttf");
    TTF_Font* font=TTF_OpenFont("font.ttf",30);
    printf( " %s", fnt );

    SDL_Surface* textSurface=TTF_RenderText_Shaded(font,text_buffer,foregroundColor, backgroundColor);
     SDL_BlitSurface(textSurface,NULL, surface ,&textLocation);


};
}t;

class sdl_gui_bitmap{

public :
  SDL_Surface* bitmap_surface;

    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    SDL_DisplayMode mode;
SDL_Rect destination={	1,100,100,100};
SDL_Rect source={	1,1,400,400};

      SDL_Color foregroundColor= {205,205,0};
    SDL_Color backgroundColor= {0,25,0};
 
     SDL_Rect textLocation= {100,100,0,0};

    char *bmp_location="/sdcard/hello_world.bmp";
    
int error(){};
int draw(){
    bitmap_surface=SDL_LoadBMP(bmp_location);
        draw_bmp();


};

int draw_bmp(  ){

	 	 // Part of the bitmap that we want to draw
/*
*/
		 	 SDL_BlitSurface(bitmap_surface,&source,surface,&destination);
};
SDL_Surface* ahmet_load_bmp(char *file){
return	  SDL_LoadBMP(file);
	
};
}b;


class sdl_home{
public :
	
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    SDL_DisplayMode mode;
int init (){
    /* Enable standard application logging */
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    /* Initialize SDL */
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init fail : %s\n", SDL_GetError());
        return 1;
    }

    SDL_GetDesktopDisplayMode(0, &mode);
    mode.h=mode.h/2;
    mode.w=mode.w/1.5;

    /* Create window and renderer for given surface */
    window = SDL_CreateWindow("Chess Board", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mode.w, mode.h, SDL_WINDOW_SHOWN);
    if(!window)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation fail : %s\n",SDL_GetError());

        return 1;
    }
    surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateSoftwareRenderer(surface);
    if(!renderer)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Render creation for surface fail : %s\n",SDL_GetError());
        return 1;
    }

    /* Clear the rendering surface with the specified color */
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0);
    SDL_RenderClear(renderer);


    /* Draw the Image on rendering surface */
    //char ch[100];
    //sprintf( ch ,"\r\n%s %s\r\n",SDL_GetError(), fnt );
    //SDL_setenv("","");
    //SDL_Log(ch);
    //  system("echo this is it CD=$CD cd=$cd PWD=$PWD pwd=$pwd");
    SDL_Delay(10);
}
} sdl;



/* XPM */
static const char *arrow[] = {
  /* width height num_colors chars_per_pixel */
  "    32    32        3            1",
  /* colors */
  "X c #000000",
  ". c #ffffff",
  "  c None",
  /* pixels */
  "X                               ",
  "XX                              ",
  "X.X                             ",
  "X..X                            ",
  "X...X                           ",
  "X....X                          ",
  "X.....X                         ",
  "X......X                        ",
  "X.......X                       ",
  "X........X                      ",
  "X.....XXXXX                     ",
  "X..X..X                         ",
  "X.X X..X                        ",
  "XX  X..X                        ",
  "X    X..X                       ",
  "     X..X                       ",
  "      X..X                      ",
  "      X..X                      ",
  "       XX                       ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "                                ",
  "0,0"
};

static SDL_Cursor *init_system_cursor(const char *image[])
{
  int i, row, col;
  Uint8 data[4*32];
  Uint8 mask[4*32];
  int hot_x, hot_y;

  i = -1;
  for (row=0; row<32; ++row) {
    for (col=0; col<32; ++col) {
      if (col % 8) {
        data[i] <<= 1;
        mask[i] <<= 1;
      } else {
        ++i;
        data[i] = mask[i] = 0;
      }
      switch (image[4+row][col]) {
        case 'X':
          data[i] |= 0x01;
          mask[i] |= 0x01;
          break;
        case '.':
          mask[i] |= 0x01;
          break;
        case ' ':
          break;
      }
    }
  }
  sscanf(image[4+row], "%d,%d", &hot_x, &hot_y);
  return SDL_CreateCursor(data, mask, 32, 32, hot_x, hot_y);
}



int
main(int argc, char *argv[])
{


sdl.init();
char *bm2;
bm2=new char [200];//allocate 200 bytes of memory for the bimap location ..



 struct p{


	int x,y;//start point
	int x2,y2; // end point
    int xd,yd;//differentiation
    int cx,cy;//current 
}pp;

sdl_gui_text t2;
std::stringstream ss;
char *pub;
pub= (char*)malloc(400);
int n=0;
while(1)
    {
	n=n+1;
    SDL_SetRenderDrawColor(sdl.renderer, 0xFF, 0xFF, 0xFF, 0);
    SDL_RenderClear(sdl.renderer);

	SDL_Event e;
        if (SDL_PollEvent(&e))
        {

 if( e.type== SDL_MOUSEMOTION) {
        	      //  	    pp.x = e.motion.x;
        	     //   	    pp.y = e.motion.y;
 //   pp.x2 = e.motion.x;
//    pp.y2 = e.motion.y;
//pp.xd= pp.x-pp.x2;
//pp.yd=pp.y-pp.y2;

 b.draw();
 };
if( e.type== SDL_MOUSEBUTTONDOWN) {
        	     pp.x = e.motion.x;
        	    pp.y = e.motion.y;
//e.button.button;

//       	    std::stringstream ss;
//        	    ss << "MOUSE DOWN!!! X: " << mouseX << " Y: " << mouseY;
 //       	std::cout <<ss.str().c_str();
//        	   SDL_SetWindowTitle(sdl.window, ss.str().c_str());

        	   //  break;
        	}


if( e.type==SDL_MOUSEBUTTONUP) {
    pp.x2 = e.motion.x;
    pp.y2 = e.motion.y;

//ss.str()="";
//ss << "-- UPP -- X: " << pp.xd<< " Y: " << pp.yd;
//std::cout <<  ss.str().c_str();
sprintf(pub,"begin=%i %i end=%i %i",pp.x,pp.y,pp.x2,pp.y2);
t.text_buffer=  pub;//(char *)ss.str().c_str();
//SDL_SetWindowTitle(sdl.window, ss.str().c_str());
// printf("SDL MOTION" );
//  break;
//sdl_gfx.renderer= sdl.renderer;
//sdl_gfx.line(pp.x,pp.y, pp.x,pp.y );
 
}

        	if (e.type == SDL_QUIT)
                 break;
            if (e.key.keysym.sym == SDLK_ESCAPE)
                break;
            if (e.key.keysym.scancode == SDL_SCANCODE_AC_BACK)
                break;
        }
 
//	printf("SDL_FINGERMOTION =%x  SDL_FINGERDOWN=%x SDL_FINGERUP=%x e.tfinger.type=%x key=%x\r\n"
//	, SDL_FINGERMOTION ,SDL_FINGERDOWN,SDL_FINGERUP,  e.tfinger.type ,e.key.type  );

         DrawChessBoard(sdl.renderer);
        // draw_line_ahmet(sdl.renderer);

//  b.destination.x=400;

 sprintf(bm2,"hello_world.bmp"); //set current image adress to something different then the default one..!!
 //set another bitmap
  b.bmp_location=bm2;
   b.surface=sdl.surface;
//   pp.cx=(-pp.xd ) + (b.destination.x ) ;
 //  pp.cy =(-pp.yd ) + ( b.destination.y );
   b.destination.x= 100;
   b.destination.y= 100;
 //  pp.xd=0;
//   pp.yd=0;
   b.draw();


        //SDL_FillRect( surface ,NULL,SDL_MapRGB( surface->format,0,0,0));


   
   t.surface=sdl.surface;
   t.draw();
   
//   t.text_buffer ="this is the word. \r\n";
        //	 	 SDL_Flip(screen);

   t2.surface=sdl.surface;
   t2.draw();
   t2.textLocation.x=0;
   t2.textLocation.y=150;
   //sprintf(pub,"STAT= %i %i\r\n",pp.cx,pp.cy );
   t2.text_buffer=pub;

sdl_gfx.renderer= sdl.renderer;
sdl_gfx.line(10,250, 900,-200 );


sdl_gfx.renderer= sdl.renderer;
sdl_gfx.line(10+n%400,250-n%400, 500+n%400 ,-200+n%400 );


        /* Got everything on rendering surface,
           now Update the drawing image on window screen */
        SDL_UpdateWindowSurface(sdl.window);

    }

    return 0;
}
