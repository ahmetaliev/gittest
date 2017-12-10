int i=0;
	int draw_line_ahmet( SDL_Renderer *renderer ){
//	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
//SDL_RenderClear(renderer);// fill the scene with white
SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
// the rect color (solid red)
SDL_Rect rect;// the rectangle0
rect.x=sin(i/50.0)*100.0+100.0;;
i=i+1;
rect.y= cos(i/50.0)*100.0+100.0;; ;
rect.w=1000;
rect.h=5;
SDL_RenderFillRect(renderer,&rect);
//SDL_RenderPresent(renderer);// copy to screen

/* Got everything on rendering surface,
 		   now Update the drawing image on window screen */
};


class SDL_GFX{
public:
SDL_Renderer *renderer ;

int line(int x,int y, int x2,int  y2){
SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
SDL_Rect rect;// the rectangle0
int i=0;
while ( i<10 ){
	rect.x=x+(i*(x2/10) );
	rect.y= y +(i*(y2/10) );
	rect.w=10;
	rect.h=10;
	SDL_RenderFillRect(renderer,&rect);


	i=i+1;
};



};



}sdl_gfx;

int draw_line( SDL_Renderer *renderer ){
//	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
//SDL_RenderClear(renderer);// fill the scene with white
SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
// the rect color (solid red)
SDL_Rect rect;// the rectangle0
rect.x=sin(i/50.0)*100.0+100.0;;
i=i+1;
rect.y= cos(i/50.0)*100.0+100.0;; ;
rect.w=1000;
rect.h=5;
SDL_RenderFillRect(renderer,&rect);
//SDL_RenderPresent(renderer);// copy to screen

/* Got everything on rendering surface,
 		   now Update the drawing image on window screen */
};



void DrawChessBoard(SDL_Renderer * renderer)
{
	int row = 0,coloum = 0,x = 0;
	SDL_Rect rect, darea;

	/* Get the Size of drawing surface */
	SDL_RenderGetViewport(renderer, &darea);

	for(; row < 8; row++)
	{
		coloum = row%2;
		x = x + coloum;
		for(; coloum < 4+(row%2); coloum++)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);

			rect.w = darea.w/8;
			rect.h = darea.h/8;
			rect.x = x * rect.w;
			rect.y = row * rect.h;
			x = x + 2;
			SDL_RenderFillRect(renderer, &rect);
		}
		x=0;
	}
}


int draw_bmp_ahmet( SDL_Surface* bitmap_surface, SDL_Surface *surface ){

	 	 // Part of the bitmap that we want to draw
SDL_Rect source;
source.x=0;
source.y=0;
source.w=300;
source.h=300;
SDL_Rect destination;
destination.x=100;
destination.y=100;
destination.w=100;
destination.h=100;
		 	 SDL_BlitSurface(bitmap_surface,&source,surface,&destination);
	


};



SDL_Surface* load_bmp(char *file){
return	  SDL_LoadBMP(file);
	
}
