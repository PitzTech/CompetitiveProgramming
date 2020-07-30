#include <bits/stdc++.h>
using namespace std;

class SegTreeLazy{
private:
    int n;
	vector<int> tree;
	vector<int> lazy;
	vector<int> caixas;
	inline void upLazy(int &node, int &i, int &j){
		if (lazy[node] != -1){
			tree[node] = lazy[node] * (j - i + 1);
			if (i != j){
				lazy[node*2] = lazy[node];
				lazy[node*2 + 1] = lazy[node];
			}
			lazy[node] = -1;
		}
	}
	void build(int node, int i, int j){
		if (i == j){
			tree[node] = caixas[i];
			return;
		}
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		build(l, i, m);
		build(r, m + 1, j);
		tree[node] = tree[l] + tree[r];
	}
	int query(int node, int i, int j, int a, int b){
		upLazy(node, i, j);
		if ((i > b) or (j < a))
			return 0;
		if ((a <= i) and (j <= b)){
			return tree[node];
		}
		int m = (i + j) / 2;
		int l = node*2;
		int r = node*2 + 1;
		return query(l, i, m, a, b) + query(r, m + 1, j, a, b);
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
			int l = node*2;
			int r = node*2 + 1;
			update(l, i, m, a, b, value);
			update(r, m + 1, j, a, b, value);
			tree[node] = tree[l] + tree[r];
		}
	}
public:
	template <class MyType>
	SegTreeLazy(MyType begin, MyType end){
		n = end - begin;
		caixas = vector<int>(begin, end);
		tree.resize(4 * n + 5);
		lazy.assign(4 * n + 5, -1);
		build(1, 0, n - 1);
	}
	int query(int a, int b){
		return query(1, 0, n - 1, a, b);
	}
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
	vector<int> caixas(n);
	for(int i=0; i<n; i++)
		cin >> caixas[i];		

	SegTreeLazy tree(caixas.begin(), caixas.end());
		
	for(int i=0; i<q; i++){
		int op,a,b;		
		cin >> op >> a >> b;
        a--; b--;
		if(op == 1){
			int k;
			cin >> k;
			tree.update(a, b, k);
		}else{
			cout << tree.query(a, b) << '\n';
		}
	}
	return 0;
}
