#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int N = 1005;

ii v[N];
int n;
int dp[N][N];
bool mark[N][N];

int f(int id, int p){
	if(p == 0) return 0;
	if(id == n) return 1e9;
	if(mark[id][p]) return dp[id][p];
	mark[id][p] = 1;
	int x = f(id+1, p-1) + v[id].ss;
	int y = f(id+1, p);
	if(x <= v[id].ff){
		return dp[id][p] = min(x, y);
	}
	return dp[id][p] = y;

}	

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &v[i].ff, &v[i].ss);
		swap(v[i].ff, v[i].ss);
	}
	sort(v, v + n);
	reverse(v, v + n);
	for(int i = n; i >= 0; i--){
		cerr << f(0, i) << endl;
		if(f(0, i) < (int)1e9){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}