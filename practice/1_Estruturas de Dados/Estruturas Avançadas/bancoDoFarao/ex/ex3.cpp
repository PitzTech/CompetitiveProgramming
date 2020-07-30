#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

#define MAXN 100005
#define pb push_back
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

typedef long long ll;
typedef pair <int, int> pii;

int val[MAXN];

struct Node {
	int sum, left, right, maxSum;
	int size, lSize, rSize, optSize;
};

Node arvore[3 * MAXN];

void merge(Node &no, Node &esq, Node &dir){
	no.sum = esq.sum + dir.sum;
	no.size = esq.size + dir.size;

	if((esq.sum + dir.left) > esq.left){
		no.left = esq.sum + dir.left;
		no.lSize = esq.size + dir.lSize;
	} else if(esq.left > (esq.sum + dir.left)){
		no.left = esq.left;
		no.lSize = esq.lSize;
	} else {
		no.left = esq.left;
		no.lSize = max((esq.size + dir.lSize), esq.lSize);
	}

	if((dir.sum + esq.right) > dir.right){
		no.right = dir.sum + esq.right;
		no.rSize = dir.size + esq.rSize;
	} else if(dir.right > (dir.sum + esq.right)){
		no.right = dir.right;
		no.rSize = dir.rSize;
	} else {
		no.right = dir.right;
		no.rSize = max((dir.size + esq.rSize), dir.rSize);
	}

	if(esq.maxSum > dir.maxSum){
		if(esq.maxSum > (esq.right + dir.left)){
			no.maxSum = esq.maxSum;
			no.optSize = esq.optSize;
		} else if((esq.right + dir.left) > esq.maxSum){
			no.maxSum = esq.right + dir.left;
			no.optSize = esq.rSize + dir.lSize;
		} else {
			no.maxSum = esq.maxSum;
			no.optSize = max(esq.optSize, esq.rSize + dir.lSize);
		}
	} else {
		if(dir.maxSum > (esq.right + dir.left)){
			no.maxSum = dir.maxSum;
			no.optSize = dir.optSize;
		} else if((esq.right + dir.left) > dir.maxSum){
			no.maxSum = esq.right + dir.left;
			no.optSize = esq.rSize + dir.lSize;
		} else {
			no.maxSum = dir.maxSum;
			no.optSize = max(dir.optSize, esq.rSize + dir.lSize);
		}
	}
}

void build(int no, int i, int j){
	if(i == j){
		arvore[no].sum = arvore[no].left = arvore[no].right = arvore[no].maxSum = val[i];
		arvore[no].size = arvore[no].lSize = arvore[no].rSize = arvore[no].optSize = 1;
	}
	else {
		int esq = no * 2, dir = no * 2 + 1;
		int meio = (i + j) / 2;

		build(esq, i, meio);
		build(dir, meio + 1, j);

		merge(arvore[no], arvore[esq], arvore[dir]);
		//arvore[no].left = max(arvore[esq].left, arvore[esq].sum + arvore[dir].left);
		//arvore[no].right = max(arvore[dir].right, arvore[dir].sum + arvore[esq].right);
		//arvore[no].maxSum = max(max(arvore[esq].maxSum, arvore[dir].maxSum), \
		arvore[esq].right + arvore[dir].left);
	}
}

Node consulta(int no, int i, int j, int a, int b){
	if(a == i && j == b){
		return arvore[no];
	}

	int esq = 2 * no, dir = 2 * no + 1; 
	int meio = (i + j) / 2;

	if(b <= meio) return consulta(esq, i, meio, a, b);
	if(a > meio) return consulta(dir, meio + 1, j, a, b);

	Node queryEsq = consulta(esq, i, meio, a, meio); 
	Node queryDir = consulta(dir, meio + 1, j, meio + 1, b); 
	Node res;
	merge(res, queryEsq, queryDir);

	return res; 
}

int main(){
    int t, n, q;
	scanf("%d", &t);

	int a, b;
	Node aux;

	for(int i = 1; i <= t; i++){
		memset(arvore, 0, sizeof(arvore));
		memset(val, 0, sizeof(val));
		scanf("%d", &n);

		for(int j = 1; j <= n; j++){
			scanf("%d", val + j);
		}

		build(1, 1, n);
		scanf("%d", &q);

		for(int j = 1; j <= q; j++){
			scanf("%d%d", &a, &b);
			if(a == b) printf("%d 1\n", val[a]);
			else {
				aux = consulta(1, 1, n, a, b);
				printf("%d %d\n", aux.maxSum, aux.optSize);
			}
		}
	}
	
	return 0;
}