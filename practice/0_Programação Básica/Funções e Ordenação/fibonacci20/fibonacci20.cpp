#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000100

int n, dp[MAXN];

int fib(int x){
  if(dp[x]) return dp[x]; ;
  if(x==0 || abs(x) == 1) return x; 
  dp[x]=fib(x-1)+fib(x-2);
  return dp[x];
}

int main(){
  
  //memset(dp, -1, sizeof(dp));
  
  cin >> n; 
  
  cout << fib(n) << "\n"; 
  
  return 0;
}