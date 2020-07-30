#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAXN 1000

using namespace std;

int height[MAXN];

int main() {
	int n, want_height;

	scanf("%d %d", &n, &want_height);

	for (int i = 0; i < n; i++) scanf("%d", &height[i]);

	int result = 0;

	for (int i = 0; i+1 < n; i++) {
		int diff = want_height - height[i];
		height[i] += diff;
		height[i+1] += diff;
		result += abs(diff);
	}

	if (height[n-1] != want_height) result = -1;

	printf("%d\n", result);

	return 0;
}
