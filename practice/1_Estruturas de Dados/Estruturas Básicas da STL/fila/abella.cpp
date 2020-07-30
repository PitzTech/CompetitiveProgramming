#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n;
  vector<int> queue;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int id;
    scanf("%d", &id);
    queue.push_back(id);
  }

  int m;
  set<int> skip;

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int id;
    scanf("%d", &id);
    skip.insert(id);
  }

  int many = 0;
  for (int i = 0; i < n; i++) {
    if (skip.find(queue[i]) == skip.end()) {
      if (many++ > 0) printf(" ");
      printf("%d", queue[i]);
    }
  }
  printf("\n");

  return 0;
}
