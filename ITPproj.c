#include<stdio.h>

void quadrado(int i,int j,int dimx,int dimy, char color[3]){

		if(i>=50 && i <= 100 && j == 50){

    	color[0] = 0;
    	color[1] = 0;
    	color[2] = 0;
    	}
    	if(j>=50 && j <= 100 && i == 50){

    	color[0] = 0;
    	color[1] = 0;
    	color[2] = 0;
    	}
    	if(i>50 && i < 100 && j == 100){

    	color[0] = 0;
    	color[1] = 0;
    	color[2] = 0;
    	}
    	if(j>50 && j < 100 && i == 100){

    	color[0] = 0;
    	color[1] = 0;
    	color[2] = 0;
    	}
}

void retangulo(int xr1,int yr1,int br,int hr, char color[3], FILE *fp){
    int i,j;
    for (i = xr1; i < (xr1+br); ++i){

        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        fwrite(color, 1, 3, fp);
    }
    for (j = yr1; j < (yr1+hr); ++j){

        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        fwrite(color, 1, 3, fp);
    }
    for (i; i > xr1; --i){

        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        fwrite(color, 1, 3, fp);
    }
    for (j; j > yr1; --j){

        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        fwrite(color, 1, 3, fp);
    }

}

int main(){

int L,C,xr1,yr1, br, hr;

static unsigned char color[3];

FILE *arquivo = fopen( "teste.txt", "r+" );
FILE *fp = fopen("image.ppm", "w+");

fscanf(arquivo, "image %d %d",&L, &C);
fscanf(arquivo, "rect %d %d %d %d",&xr1, &yr1, &br,&hr);

fprintf(fp, "P6\n%d %d\n255\n", L, C);

for (int i = 0; i < L; i++){
	for (int j = 0; j < C; j++){
		
		color[0] = 255;
    	color[1] = 255;
    	color[2] = 255;

	fwrite(color, 1, 3, fp);
		
	}
}
//quadrado(i,j,L,C,color);
retangulo(xr1,yr1,br,hr,color,fp);

fclose(arquivo);
fclose(fp);

return 0;

}

