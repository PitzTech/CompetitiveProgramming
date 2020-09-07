#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

int mergeSort(vector<int> &v){
    if(v.size() == 1) return 0;

    int inter = 0;
    vector<int> u1,u2;
    for(int i = 0; i < v.size()/2; i++)
        u1.push_back(v[i]);
    for(int i = v.size()/2; i < v.size(); i++)
        u2.push_back(v[i]);

    inter += mergeSort(u1);
    inter += mergeSort(u2);

    u1.push_back(INF);
    u2.push_back(INF);

    int ini1 = 0, ini2 = 0;
    for(int i = 0; i < v.size(); i++){
        if(u1[ini1] <= u2[ini2])
            v[i] = u1[ini1++];
        else{
            v[i] = u2[ini2++];
            inter += u1.size() - ini1 - 1;
        }
    }
    return inter;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int &i : v)
        cin >> i;

    cout << mergeSort(v);
    return 0;
}