#include <bits/stdc++.h>

#define MAXN 50010
using namespace std;

int nodes,edges;
int grau[MAXN];
int marc[MAXN];
bool ciclo;
vector<int> myv[MAXN];
vector<int> resp;
priority_queue<int, vector<int>, greater<int> > heap;

int main(){
    
    cin >> nodes >> edges;
    
    for(int i = 1;i<=edges;i++){
        int a,b;
        cin >> a  >> b; a++; b++;
        grau[b]++;
        myv[a].push_back(b);
    }
    
    for(int i = 1;i <= nodes;i++) 
        if(grau[i] == 0) 
            heap.push(i);
        
    int cont = 0;
    while( !heap.empty() ){
        
        cont++;
        int l = myv[heap.top()].size();
        int cara = heap.top();
        heap.pop();
        
        for(int i = 0; i < l; i++ ){
            grau[ myv[cara][i] ]--;
            if(grau[myv[cara][i]] == 0) 
                heap.push(myv[cara][i]);
        }
        resp.push_back(cara);
    }
    
    if(cont < nodes) 
        cout << "*\n";
    else 
        for(int i = 0;i<nodes;i++) 
        cout <<  (resp[i]-1) << "\n";
    
    return 0;
}