#include <stdio.h>
#include <string.h>
#define MAX_S 250
#define INF 0x1f1f1f1f
#define MIN(a, b) ((a) < (b) ? (a) : (b)) 
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int g[MAX_S][MAX_S];

int main () {
  memset (g, 0x1f, sizeof(g));

  int m, n;
  int i, j, k;
  int a, b, d;
  int min = INF;
  int max;

  scanf (" %d %d", &n, &m);
  for (i = 0; i < n; i++) g[i][i] = 0;
  for (i = 0; i < m; i++) {
    scanf (" %d %d %d", &a, &b, &d);
    a--; b--;
    g[a][b] = d;
    g[b][a] = d;
  } 
  for (k = 0; k < n; k++) 
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) 
	g[i][j] = MIN(g[i][j], g[i][k] + g[k][j]);

  for (i = 0; i < n; i++) {
    max = 0;
    for (j = 0; j < n; j++) 
      max = MAX(max, g[i][j]);
    min = MIN(min, max);
  }
  printf("%d\n", min);
}
