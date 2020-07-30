#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f 
struct Node{
    int maxPrefixSum;
    int maxSuffixSum;
    int totalSum;
    int maxSubarraySum;
    int elements;
    Node(){
        maxPrefixSum = maxSuffixSum = maxSubarraySum = totalSum = -inf;
        elements = 1;
    }
};
Node merge(Node leftChild, Node rightChild){
    Node parentNode;
    // 0 left
    // 1 right
    
    parentNode.maxPrefixSum = max(leftChild.maxPrefixSum, 
                                  leftChild.totalSum +  
                                  rightChild.maxPrefixSum); 
   
    parentNode.maxSuffixSum = max(rightChild.maxSuffixSum, 
                                  rightChild.totalSum + 
                                  leftChild.maxSuffixSum); 
   
    parentNode.totalSum = leftChild.totalSum + 
                          rightChild.totalSum; 

    int totelements;

    if(leftChild.maxSubarraySum > rightChild.maxSubarraySum 
    && leftChild.maxSubarraySum > leftChild.maxSuffixSum + rightChild.maxPrefixSum){
        totelements = leftChild.elements;
        parentNode.maxSubarraySum = leftChild.maxSubarraySum;
    }else if(rightChild.maxSubarraySum > leftChild.maxSubarraySum 
    && rightChild.maxSubarraySum > leftChild.maxSuffixSum + rightChild.maxPrefixSum){
        totelements = rightChild.elements;
        parentNode.maxSubarraySum = rightChild.maxSubarraySum;
    }else{
        if(rightChild.maxSubarraySum == leftChild.maxSubarraySum 
    && rightChild.maxSubarraySum == leftChild.maxSuffixSum + rightChild.maxPrefixSum)
            totelements = max(leftChild.elements,rightChild.elements);
        else
            totelements = leftChild.elements + rightChild.elements;
        parentNode.maxSubarraySum = leftChild.maxSuffixSum +  
                                     rightChild.maxPrefixSum;
    }

    return parentNode; 
}
void constructTreeUtil(Node* tree, int arr[], int start, int end, int index){
    if(start == end){
        //single element
        tree[index].totalSum = arr[start]; 
        tree[index].maxSuffixSum = arr[start]; 
        tree[index].maxPrefixSum = arr[start]; 
        tree[index].maxSubarraySum = arr[start]; 
        tree[index].elements = arr[start];
        return;
    }
    int mid = (start+end)/2;
    constructTreeUtil(tree, arr,start, mid, 2*index);
    constructTreeUtil(tree, arr,mid+1, end, 2*index+1);

    //final sum
    tree[index] = merge(tree[2*index], tree[2*index+1]);
}
Node* constructTree(int arr[], int n){
    int height = (int)(ceil(log2(n)));
    int maxSize = 2*(int)pow(2,height) - 1;
    Node* tree = new Node[maxSize];

    //fill memory
    constructTreeUtil(tree, arr, 0, n-1, 1);
    return tree; //returning the builted tree
}
// get maximum sum sub array
// ss & se start n end indexes of segment of actual node
// qs & qe start n end indexes of queryRange
//returns the maximum subarray sum
Node queryUtil(Node* tree, int ss, int se, int qs, int qe, int index){
    // no overlap
    if(ss > qe || se < qs){
        Node nullNode;
        return nullNode;
    }
    //complete overlap
    if(ss >= qs && se <= qe)
        return tree[index];
    // partial overlap
    int mid = (ss+se)/2;
    Node left = queryUtil(tree,ss,mid,qs,qe,2*index);
    Node right = queryUtil(tree,mid+1,se,qs,qe,2*index+1);
    
    //merging
    Node res = merge(left,right);
    return res;
}   
int query(Node* tree, int start, int end, int n){
    Node res = queryUtil(tree, 0, n-1, start, end, 1);
    return res.maxSubarraySum;
}
int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int instancia, ncontas, nconsultas;
    pair<int,int> resul;
    pair<int,int> maior;
    scanf("%d", &instancia);
    for(int x = 0; x < instancia; x++){
        scanf("%d", &ncontas);
        int contas[ncontas], arvore[ncontas*4];
        for(int x = 0; x < ncontas; x++)
            scanf("%d", &contas[x]);
        
        Node* Tree = constructTree(contas, ncontas);
        int ini, fim, maxSubarraySum;

        scanf("%d", &nconsultas);
        for(int x = 0; x < nconsultas; x++){
            scanf("%d %d", &ini, &fim);
            if(ini == fim)
                maxSubarraySum = contas[ini-1];
            else
                maxSubarraySum = query(Tree, ini-1, fim-1, ncontas);
            printf("%d\n", maxSubarraySum);
        }
    }
    return 0;
}