#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class SegTreeLazy{
private:
	typedef long long Node;
	vector<Node> st;
	vector<long long> lazy;
	vector<int> v;
	int n;
	Node neutral = 0;
	inline Node join(Node a, Node b){
		return a + b;
	}
	inline void upLazy(int &node, int &i, int &j){
		if (lazy[node] != -1){
			st[node] = lazy[node] * (j - i + 1);
			if (i != j){
				lazy[(node << 1)] = lazy[node];
				lazy[(node << 1) + 1] = lazy[node];
			}
			lazy[node] = -1;
		}
	}
	void build(int node, int i, int j){
		if (i == j){
			st[node] = v[i];
			return;
		}
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		build(l, i, m);
		build(r, m + 1, j);
		st[node] = join(st[l], st[r]);
	}
	Node query(int node, int i, int j, int a, int b){
		upLazy(node, i, j);
		if ((i > b) or (j < a))
			return neutral;
		if ((a <= i) and (j <= b)){
			return st[node];
		}
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		return join(query(l, i, m, a, b), query(r, m + 1, j, a, b));
	}
	void update(int node, int i, int j, int a, int b, int value){
		upLazy(node, i, j);
		if ((i > j) or (i > b) or (j < a))
			return;
		if ((a <= i) and (j <= b)){
			lazy[node] = value;
			upLazy(node, i, j);
		}else{
			int m = (i + j) / 2;
			int l = (node << 1);
			int r = l + 1;
			update(l, i, m, a, b, value);
			update(r, m + 1, j, a, b, value);
			st[node] = join(st[l], st[r]);
		}
	}
public:
	template <class MyIterator>
	SegTreeLazy(MyIterator begin, MyIterator end){
		n = end - begin;
		v = vector<int>(begin, end);
		st.resize(4 * n + 5);
		lazy.assign(4 * n + 5, -1);
		build(1, 0, n - 1);
	}
	//0-indexed [a, b]
	Node query(int a, int b){
		return query(1, 0, n - 1, a, b);
	}
	//0-indexed [a, b]
	void update(int a, int b, int value){
		update(1, 0, n - 1, a, b, value);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];		

	SegTreeLazy st(v.begin(), v.end());
		
	for(int i=0; i<q; i++){
		int op;		
		cin >> op;
		if(op == 1){
			int a, b, k;
			cin >> a >> b >> k;
			a--; b--;
			st.update(a, b, k);
		}else{
			int a, b;
			cin >> a >> b;
			a--; b--;
			cout << st.query(a, b) << endl;
		}
	}
	return 0;
}
