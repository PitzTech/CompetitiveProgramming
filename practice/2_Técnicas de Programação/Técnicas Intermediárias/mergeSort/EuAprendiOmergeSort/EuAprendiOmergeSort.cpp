#include <bits/stdc++.h>

#define INF LONG_MAX
using namespace std;

void mergeSort(vector<long> &v){
    if(v.size() == 1) return;

    vector<long> u1, u2;

    for(int i = 0; i < v.size()/2; i++) 
        u1.push_back(v[i]);
    for(int i = v.size()/2; i < v.size(); i++) 
        u2.push_back(v[i]);    

    mergeSort(u1);
    mergeSort(u2);

    u1.push_back(INF);
    u2.push_back(INF);

    int ini1 = 0, ini2 = 0;
    for(int i = 0; i < v.size(); i++){
        if(u1[ini1] < u2[ini2])
            v[i] = u1[ini1++];
        else
            v[i] = u2[ini2++];
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long> lista(n);
    for(int i = 0; i < n; i++)
        cin >> lista[i];

    mergeSort(lista);
    reverse(lista.begin(), lista.end());

    for(int el : lista)
        cout << el << " ";

    return 0;
}