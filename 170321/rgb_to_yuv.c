/*
 *抄录与　让你的软件飞起来
 *
 *Y = 0.299R + 0.587G + 0.114B
 *U = -0.147R -0.289G + 0.436B
 *V = 0.615R - 0.515 - 0.100B
 */
#include<stdio.h>

#define SIZE 256
#define XSIZE 640
#define YSIZE 480
#define IMGSIZE XSIZE*YSIZE

typedef struct RGB
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}RGB;

struct RGB in[IMGSIZE];
unsigned char out[IMGSIZE*3];

unsigned char Y_R[SIZE], Y_G[SIZE], Y_B[SIZE];
unsigned char U_R[SIZE], U_G[SIZE], U_B[SIZE];
unsigned char V_R[SIZE], V_G[SIZE], V_B[SIZE];

void table_init()
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		Y_R[i] = (i*1224) >> 12;
		Y_G[i] = (i*2404) >> 12;
		Y_B[i] = (i*467) >> 12;

		U_R[i] = (i*602) >> 12;
		U_R[i] = (i*1183) >> 12;
		U_R[i] = (i*1785) >> 12;

		V_R[i] = (i*2519) >> 12;
		V_R[i] = (i*2109) >> 12;
		V_R[i] = (i*409) >> 12;

	}
}

inline void rgb_to_yuv()
{
	int i;
	for(i=0; i<IMGSIZE; i+=2)
	{
		out[i] = Y_R[i] + Y_G[i] + Y_B[i];
		out[i+IMGSIZE] = U_R[i] +U_G[i] + U_B[i];
		out[i+2*IMGSIZE] = V_R[i] + V_G[i] +V_B[i];

		out[i+1] = Y_R[i+1] + Y_G[i+1] + Y_B[i+1];
		out[i+1+IMGSIZE] = U_R[i+1] +U_G[i+1] + U_B[i+1];
		out[i+1+2*IMGSIZE] = V_R[i+1] + V_G[i+1] +V_B[i+1];
	}
}






