#include "header.h"

SDL_Rect star = {1000,232,60,60};
struct start_and_end indicator;
int knifes_counter;
struct weapon knife[80];
char knifestring[500];
SDL_Texture* gKnifeTexture=NULL;

void setup_knifes()
{
    int i;
    for(i=0; i<80; i++)
    {
        knife[i].hit.x = 150;
        knife[i].hit.y = 420;
        knife[i].hit.w = 40;
        knife[i].hit.h = 40;

        knife[i].available = false;
    }
}

void  rendering_knifes()
{
    int i;
    for(i=indicator.start; i<indicator.finish; i++)
    {
        //knife[i].hit.y = y_pos + 40;
        SDL_RenderCopy(gRenderer,knife_texture,NULL,&knife[i].hit);
        knife[i].hit.x += 10;
    }
}

void managing_knife()
{
    if(knife[0].hit.x>=SCREEN_WIDTH)
    {
        int i;

        for(i=0; i<indicator.finish-1 ; i++)
        {
            knife[i].hit.x = knife[i+1].hit.x;
            knife[i].hit.y = knife[i+1].hit.y;
        }

        knife[i].hit.x = 150;
        indicator.finish--;
    }
}

void knives()
{
    if(x_pos +71 >= star.x && x_pos <= star.x + star.w && y_pos<=star.y + star.h)
    {
        Mix_PlayChannel(-1,coinsound,0);
        knifes_counter+=5;
        star.x = 800 + rand()%1500;
        if((star.x>=coin.x && star.x  <= coin.x + coin.w && star.y == coin.y) || (star.x<=coin.x && star.x + star.w >=coin.x && star.y == coin.y))
        {
            star.x += 100;
        }
    }

    star.x -=6;
    if(star.x + star.w <=0)
    {
        star.x = 800 + rand()%1500;
        if((star.x>=coin.x && star.x  <= coin.x + coin.w && star.y == coin.y) || (star.x<=coin.x && star.x + star.w >=coin.x && star.y == coin.y))
        {
             star.x += 100;
        }
    }
}

void int_to_string_knife(int a)
{
    int i=0,j,k;
    char temp;
    while(a!=0)
    {
        knifestring[i]=a%10+'0';
        a=a/10;
        i++;
    }
    if(i==0)
    {
        knifestring[i++]='0';
    }
    knifestring[i]='\0';
    for(j=0,k=i-1;j<=(i/2)-1;j++,k--)
    {
        temp=knifestring[j];
        knifestring[j]=knifestring[k];
        knifestring[k]=temp;
    }
}

SDL_Texture* knifeprint( std::string textureText )
{
   if(gKnifeTexture!=NULL)
   {
       SDL_DestroyTexture(gKnifeTexture);
   }

   SDL_Color textColor={ 0xFF, 0xFF, 0xFF };
	//Render text surface
	SDL_Surface* knifesurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( knifesurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        gKnifeTexture = SDL_CreateTextureFromSurface( gRenderer, knifesurface );
		if( gKnifeTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		//Get rid of old surface
		SDL_FreeSurface(knifesurface);
	}
	
	//Return success
	return gKnifeTexture;
}
    