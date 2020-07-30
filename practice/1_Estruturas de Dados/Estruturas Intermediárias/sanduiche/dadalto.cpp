/****************************************************************************
 * Arthur Pratti Dadalto
 * OBI 2016
 * "Two pointers" O(N)
 ***************************************************************************/
#include <stdio.h>

int a[2123456];

int main(void)
{
	int n, d, ans = 0;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; a[n+i] = a[i], i++)
		scanf("%d", &a[i]);
	int right = -1, sum = 0;
	for(int i = 0; i < n; i++)
	{
		while(right + 1 < i + n && sum < d)
			sum += a[++right];
		if(sum == d)
			ans++;
		sum -= a[i];
	}
	printf("%d\n", ans);
}