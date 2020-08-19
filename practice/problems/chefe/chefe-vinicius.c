#include <stdio.h>
#include <assert.h>

#define MINN 1
#define MAXN 2000
#define MINM 0
#define MAXM 200000
#define MINQ 1
#define MAXQ 2000
#define MINIDADE 1
#define MAXIDADE 1000

#define INF 0x3f3f3f3f

int m,n,q;

int adj[MAXN][MAXN];
int idade[MAXN];
int temp[MAXN];

void processa()
{
	int i, j, k;
	
	for (k=0; k< n; k++)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				if (adj[i][j] > adj[i][k]+ adj[k][j])
					adj[i][j] = 0;
			}
		}
	}
	
}

int acha(int a)
{
	int resp = MAXIDADE+1;
	int i;
	

	for (i=0; i<n; i++)
	{
		if (!adj[i][a])
		{
			if (idade[i] < resp)
				resp = idade[i];
		}
	}
	if (resp > MAXIDADE)
		return 0;
	return resp;
}

int main()
{
	int i, j, a, b;
	char c;
	
	while (scanf("%d %d %d",&n, &m, &q) == 3)
	{
		assert(MINN <= n && n <= MAXN);
		assert(MINM <= m && m <= MAXM);
		assert(MINQ <= q && q <= MAXQ);

		
		for (i=0; i<n; i++)
		{
			scanf("%d", &idade[i]);
			assert(MINIDADE <= idade[i] && idade[i]<= MAXIDADE);
		}

		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
				adj[i][j] = INF;
		}
		
		for (i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);
			a--; b--;
			adj[a][b] = 0;
		}
		
		
		processa();
		
		
		for (i=0; i<q; i++)
		{
			scanf(" %c", &c);
			if (c == 'P')
			{
				scanf("%d", &a);
				a--;
				j=acha(a);
				if (j==0)
				  printf("*\n");
				else
				  printf("%d\n", j);

			}
			else
			{
				assert(c == 'T');
				scanf("%d %d", &a, &b);
				a--; b--;
				for (j=0; j<n; j++)
				{
					temp[j] = adj[a][j];
					adj[a][j] = adj[b][j];
					adj[b][j] = temp[j];
				}
				for (j=0; j<n; j++)
				{
					temp[j] = adj[j][a];
					adj[j][a] = adj[j][b];
					adj[j][b] = temp[j];
				}
			}
		}
	}
	return 0;
}

