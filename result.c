#include <stdio.h>
#include <stdlib.h>
#define N 6


void flip_result(int a, int b)
{
	int u, d, l, r, ur, ul, dr, dl;
	int sum;
	int player;

	u = up_white(a, b);
	d = down_white(a, b);
	l = left_white(a, b);
	r = right_white(a, b);
	ur = upright_white(a, b);
	ul = upleft_white(a, b);
	dr = downright_white(a, b);
	dl = downleft_white(a, b);
	
	sum = u + d + l + r + ur + ul + dr + dl;

	printf("\n\n :: flip result :: \n");
	printf("  W:%i E:%i N:%i S:%i NW:%i NE:%i SW:%i SE:%i \n", l, r, u, d, ul, ur, dl, dr);
	
	if(player%2 == 1) //백돌턴이면
		printf("  White has flipped %i othellos!", sum);
	else //흑돌턴이면
		printf("  Black has flipped %i othellos!", sum);
}
