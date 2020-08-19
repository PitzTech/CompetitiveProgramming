#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

#define MAXN 100

int parent[MAXN], _rank[MAXN];

int find(int a) {
  if (a == parent[a]) return a;
  return parent[a] = find(parent[a]);
}

bool join(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return false;
  if (_rank[a] > _rank[b]) swap(a, b);
  parent[a] = b;
  if (_rank[a] == _rank[b]) _rank[b]++;
  return true;
}

int main() {
  int n, nf, nr;

  scanf("%d %d %d", &n, &nf, &nr);

  vector <pair <int, pair <int, int> > > roads;

  for (int f = 0; f < nf + nr; f++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c), a--, b--;
    roads.push_back(make_pair(c, make_pair(a, b)));
  }

  sort(roads.begin(), roads.begin() + nf);
  sort(roads.begin() + nf, roads.end());

  for (int i = 0; i < n; i++) {
    parent[i] = i;
    _rank[i] = 0;
  }

  pair <int, int> res(0, 0);

  for (int j = 0; j < (int)roads.size(); j++) {
    int a = roads[j].second.first, b = roads[j].second.second, c = roads[j].first;
    if (join(a, b)) {
      res.first++;
      res.second += c;
    }
  }

  printf("%d\n", res.second);

  return 0;
}
