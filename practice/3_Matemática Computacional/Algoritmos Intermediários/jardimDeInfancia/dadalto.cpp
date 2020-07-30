#include <stdio.h>

int x[8], y[8];

int sq(int x) { return x*x; }
int sign(int x) { return (x < 0) ? -1 : 1; }

int dist(int i, int j)
{
	return sq(x[i] - x[j]) + sq(y[i] - y[j]);
}

int cross(int i, int j, int k)
{
	return (x[j]-x[i])*(y[k]-y[i]) - (x[k]-x[i])*(y[j]-y[i]);
}

int main(void)
{
	for(int i = 1; i <= 7; i++)
		scanf("%d %d", &x[i], &y[i]);
	if(dist(1,2) + dist(1,3) <= dist(2,3))
		printf("N\n");
	else if(dist(1,3) != dist(1,2))
		printf("N\n");
	else if(cross(2, 3, 4) != 0 || cross(2, 3, 5) != 0)
		printf("N\n");
	else if(x[2] + x[3] != x[4] + x[5] || y[2] + y[3] != y[4] + y[5])
		printf("N\n");
	else if(dist(2,3) <= dist(4,5))
		printf("N\n");
	else if(dist(2,6) != dist(2,4) + dist(4,6) || dist(3,7) != dist(3,5) + dist(5,7))
		printf("N\n");
	else if(dist(5,7) != dist(4,6))
		printf("N\n");
	else if(sign(cross(2,3,1)) == sign(cross(2,3,6)))
		printf("N\n");
	else
		printf("S\n");
}