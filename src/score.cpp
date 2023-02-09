#include "header.h"

char scorestring[100];

void int_to_string(int a)
{
    int i=0,j,k;
    char temp;
    while(a!=0)
    {
        scorestring[i]=a%10+'0';
        a=a/10;
        i++;
    }
    if(i==0)
    {
        scorestring[i++]='0';
    }
    scorestring[i]='\0';
    for(j=0,k=i-1;j<=(i/2)-1;j++,k--)
    {
        temp=scorestring[j];
        scorestring[j]=scorestring[k];
        scorestring[k]=temp;
    }
    
}

SDL_Texture* scoreprint( std::string textureText )
{
    if(scoreTexture!=NULL)
    {
        SDL_DestroyTexture(scoreTexture);
    }

    SDL_Color textColor={ 0xFF, 0xFF, 0xFF };
	//Render text surface
	SDL_Surface* scoresurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( scoresurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        scoreTexture = SDL_CreateTextureFromSurface( gRenderer, scoresurface );
		if( scoreTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		//Get rid of old surface
		SDL_FreeSurface(scoresurface);
	}
	
	//Return success
	return scoreTexture;
}