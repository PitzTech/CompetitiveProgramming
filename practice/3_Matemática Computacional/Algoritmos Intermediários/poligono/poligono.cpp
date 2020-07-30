/*
condição de existencia de poligono?
sum-max_L>max_L.
Pro triângulo:
a+b+c-a>a
Max_l é o maior lado
Aí o problema se reduz a ordenação
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
int dist(int x,int y,int X,int Y){
    return (x-X)(x-X)+(y-Y)(y-Y);
}*/
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    sort(A,A+n);
    int sum[n];

    sum[0]=A[0];
    for(int i=1;i<n;i++){
        sum[i]=A[i]+sum[i-1];
    }
    int maxi=0;
    for(int i=2;i<n;i++){
        if(A[i]<sum[i]-A[i]){
            maxi=i+1;
        }
    }
    cout<<maxi<<endl;

}