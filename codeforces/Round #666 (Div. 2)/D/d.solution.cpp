#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
//template begins
#define int long long int
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
#define itt vector<int>:: iterator
#define pb push_back
#define mp make_pair
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define db long double
#define itp vector<pair<int,int> >:: iterator
#define ff first
#define ss second
#define endl "\n"
typedef pair<int,int> pii;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
    order_of_key()  - The number of items in a set that are strictly smaller than our item
    Rest same as set
*/
const int inf=1000000000000000000;
const long double pi = 3.14159265358979323846264338;
const long long mod = 1000000007;
// const long long mod = 998244353;
 
int pow(int x, unsigned int y, int p){
    int res=1;
    x=x%p;
    if (x==0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int invmod(int a,int m){
	return pow(a,m-2,m);
}
//template ends
 
signed main(){
	ios
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(all(a));
		int flag=1;
		if(n%2==0)
			flag=0;
		int cnt=0;
		for(int i=0;i<n-1;i++)
		{
			cnt+=a[i];
		}
		if(a[n-1]>cnt)
		{
			cout<<"T"<<endl;
			continue;
		}
		cnt+=a[n-1];
		cnt-=n;
		if(cnt%2!=0)
			flag=1-flag;
		if(flag)
		{
			cout<<"T"<<endl;
		}
		else{
			cout<<"HL"<<endl;
		}
	}
}