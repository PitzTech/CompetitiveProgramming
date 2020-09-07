#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const int tmax = (int)1e3 + 100;

int altura[tmax];

int main() {

  int n, m;
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &altura[i]);
  
  int total = 0;
  for (int i = 1; i < n; i++) {
    if (m >= altura[i - 1])
      altura[i] += m - altura[i - 1];
    else
      altura[i] -= altura[i - 1] - m;
    
    total += abs(m - altura[i - 1]);
  }
 
  printf("%d\n", total);
  return 0;
}
