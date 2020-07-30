#include <bits/stdc++.h>

using namespace std;

int const N = 1e6;

#define inf 0x3f3f3f3f

struct node_t {
    int maxPrefixSum_value, maxSuffixSum_value, TotalSum_value, maxSubArraySum_value;
    int maxPrefixSum_sz, maxSuffixSum_sz, TotalSum_sz, maxSubArraySum_sz;
    node_t()
    {
        maxPrefixSum_value = maxSuffixSum_value = TotalSum_value = maxSubArraySum_value = -inf;
        maxPrefixSum_sz = maxSuffixSum_sz = TotalSum_sz = maxSubArraySum_sz = 1;
    }
};

node_t segtree[300000];

int banco[100200];

node_t mergeNodes(node_t leftChild, node_t rightChild)
{
    node_t parentNode;

    parentNode.TotalSum_value = leftChild.TotalSum_value + rightChild.TotalSum_value;
    parentNode.TotalSum_sz = leftChild.TotalSum_sz + rightChild.TotalSum_sz;

    if (leftChild.maxPrefixSum_value > leftChild.TotalSum_value+rightChild.maxPrefixSum_value)
    {
        parentNode.maxPrefixSum_value = leftChild.maxPrefixSum_value;
        parentNode.maxPrefixSum_sz = leftChild.maxPrefixSum_sz;
    } else if (leftChild.maxPrefixSum_value == leftChild.TotalSum_value+rightChild.maxPrefixSum_value)
    {
        parentNode.maxPrefixSum_value = leftChild.TotalSum_value+rightChild.maxPrefixSum_value;
        parentNode.maxPrefixSum_sz = max(leftChild.TotalSum_sz, leftChild.TotalSum_sz+rightChild.maxPrefixSum_sz);
    } else {
        parentNode.maxPrefixSum_value = leftChild.TotalSum_value+rightChild.maxPrefixSum_value;
        parentNode.maxPrefixSum_sz = leftChild.TotalSum_sz+rightChild.maxPrefixSum_sz;
    }

    if (rightChild.maxSuffixSum_value > rightChild.TotalSum_value+leftChild.maxSuffixSum_value)
    {
        parentNode.maxSuffixSum_value = rightChild.maxSuffixSum_value;
        parentNode.maxSuffixSum_sz = rightChild.maxSuffixSum_sz;
    } else if (rightChild.maxSuffixSum_value == rightChild.TotalSum_value+leftChild.maxSuffixSum_value)
    {
        parentNode.maxSuffixSum_value = rightChild.maxSuffixSum_value;
        parentNode.maxSuffixSum_sz = max(rightChild.maxSuffixSum_sz, rightChild.TotalSum_sz+leftChild.maxSuffixSum_sz);
    } else { //O maior elemento for maior ou igual (valor)
        parentNode.maxSuffixSum_value = rightChild.TotalSum_value+leftChild.maxSuffixSum_value;
        parentNode.maxSuffixSum_sz = rightChild.TotalSum_sz+leftChild.maxSuffixSum_sz;
    }

    if (rightChild.maxSubArraySum_value > leftChild.maxSubArraySum_value)
    {
        parentNode.maxSubArraySum_value = rightChild.maxSubArraySum_value;
        parentNode.maxSubArraySum_sz = rightChild.maxSubArraySum_sz;
    } else if (rightChild.maxSubArraySum_value < leftChild.maxSubArraySum_value)
    {
        parentNode.maxSubArraySum_value = leftChild.maxSubArraySum_value;
        parentNode.maxSubArraySum_sz = leftChild.maxSubArraySum_sz;
    } else {
        parentNode.maxSubArraySum_value = leftChild.maxSubArraySum_value;
        parentNode.maxSubArraySum_sz = max(leftChild.maxSubArraySum_sz, rightChild.maxSubArraySum_sz);
    }

    if (parentNode.maxSubArraySum_value < leftChild.maxSuffixSum_value + rightChild.maxPrefixSum_value) {
        parentNode.maxSubArraySum_value = leftChild.maxSuffixSum_value + rightChild.maxPrefixSum_value;
        parentNode.maxSubArraySum_sz = leftChild.maxSuffixSum_sz + rightChild.maxPrefixSum_sz;
    }

    if (parentNode.maxSubArraySum_value == leftChild.maxSuffixSum_value + rightChild.maxPrefixSum_value)
    {
        parentNode.maxSubArraySum_value = leftChild.maxSuffixSum_value + rightChild.maxPrefixSum_value;
        parentNode.maxSubArraySum_sz = max(leftChild.maxSuffixSum_sz + rightChild.maxPrefixSum_sz, parentNode.maxSubArraySum_sz);
    }

    return parentNode;
}

void build(int node, int i, int j)
{
    if (i == j)
    {
        segtree[node].maxSuffixSum_value = banco[i];
        segtree[node].maxPrefixSum_value = banco[i];
        segtree[node].maxSubArraySum_value = banco[i];
        segtree[node].TotalSum_value = banco[i];
        segtree[node].maxSuffixSum_sz = 1;
        segtree[node].maxPrefixSum_sz = 1;
        segtree[node].maxSubArraySum_sz = 1;
        segtree[node].TotalSum_sz = 1;
        return;
    }

    int middle = (i+j)/2;

    build(node*2, i, middle);
    build(node*2+1, middle+1, j);

    segtree[node] = mergeNodes(segtree[2*node], segtree[2*node+1]);
}

node_t query(int node, int l, int r, int L, int R)
{
    if (l == L && r == R)
        return segtree[node];

    int middle = (l+r)/2;

    if (R <= middle) //Se a busca estiver completamente no nó da esquerda
        return query(node*2, l, middle, L, R);
    if (L > middle) //Se a busca estiver completamente no nó da direita
        return query(node*2+1, middle+1, r, L, R);

    return mergeNodes(query(node*2, l, middle, L, middle),
                      query(node*2+1, middle+1, r, middle+1, R)
                      );
}

int main()
{
    int t, n ,q;
    scanf("%d", &t);//cin >> t;
    while(t--)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            scanf("%d", &banco[i]); //cin >> banco[i];

        build(1, 1, n);

        //cin >> q;
        scanf("%d", &q);
        while(q--)
        {
            int a, b; scanf("%d %d", &a, &b);//cin >> a >> b;
            node_t intervalo = query(1, 1, n, a, b);
            cout << intervalo.maxSubArraySum_value << " " << intervalo.maxSubArraySum_sz << endl;
        }
    }
    return 0;
}
