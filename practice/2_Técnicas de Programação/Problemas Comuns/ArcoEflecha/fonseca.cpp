#include <cstdio>

struct node {
	int val;
	node *left, *right;
} nodes[6000000];

int used;
node *get_node() {
	return &nodes[used++];
}

int read(node *root, long long tgt, long long from=0, long long to=10000000000000LL) {
	if (root == NULL) return 0;
	if (to <= tgt) return root->val;
	if (from > tgt) return 0;

	long long mid = (from+to)/2;
	return read(root->left, tgt, from, mid) + read(root->right, tgt, mid+1, to);
}

void update(node *&root, long long tgt, long long from=0, long long to=10000000000000LL) {
	if (tgt < from || to < tgt) return;

	if (root == NULL) root = get_node();
	if (from == to) {
		root->val++;
		return;
	}
	
	long long mid = (from+to)/2;
	update(root->left, tgt, from, mid);
	update(root->right, tgt, mid+1, to);
	root->val = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
}

node *root;

int main() {
	int n;
	scanf("%d", &n);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		long long dst = x*1ll*x + y*1ll*y;
		ans += read(root, dst);
		update(root, dst);
	}

	printf("%lld\n", ans);
}
