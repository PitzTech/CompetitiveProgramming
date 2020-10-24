#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;

int s1[MAXN], s2[MAXN], dp[MAXN][MAXN];

int lcs(int a, int b){ //longest common subsequence
    if(dp[a][b] >= 0) return dp[a][b];
    if(!a || !b) return dp[a][b] = 0;

    if(s1[a] == s2[b]) return 1 + lcs(a-1, b-1);
    return dp[a][b] = max(lcs(a-1,b), lcs(a,b-1));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> s1[i];
    for(int i = 1; i <= m; i++)
        cin >> s2[i];

    memset(dp, -1, sizeof(dp));

    int nseq = lcs(n,m);
    cout << n - nseq << " " << m - nseq;

    return 0;
}