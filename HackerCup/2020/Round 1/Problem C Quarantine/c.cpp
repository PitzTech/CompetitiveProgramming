#include <bits/stdc++.h>

#define MAXN 1000006
using namespace std;

int floors;
int n, k; //rooms, k constants
int A,B,C; // constants

char patient[MAXN];
vector<int> filhos[MAXN];
int pai[MAXN];
int head[MAXN];
int groupSize[MAXN];
vector<int> saudavel;

int maxPessoas = 0;
int possibili = 0;

int find(int x){
    if(head[x] == x) return x;
    return head[x] = find(head[x]);
}

void acharFilhos(int i, int seq = 0){
    //cout << seq << endl;
    if(patient[i] == '#')
        seq = 0;
    else{
        seq++;
        if(seq > 1){
            head[i] = find(pai[i]);
            groupSize[i] = groupSize[head[i]] + groupSize[i];
            possibili = max(groupSize[i] - 1, possibili);
        }
        if(seq > maxPessoas){
            maxPessoas = seq;
            possibili = 1;
        }else if(seq == maxPessoas){
            possibili++;
        }
    } 
    //cout << "size: " << filhos[i].size() << endl; 
    for(int filho : filhos[i]){
        if(filho == i) continue;
        //cout << "indo para " << filho << endl;
        acharFilhos(filho, seq);
    }
}
void findNew(int i){
    if(patient[i] == '*'){
        for(int node : saudavel){
            if(head[node] != head[i]){
                int sumSize = groupSize[node] + groupSize[i];
                if(sumSize > maxPessoas){
                    maxPessoas = sumSize;
                    possibili = 1;
                }else if(sumSize == maxPessoas)
                    possibili++;
            }
        } 
    }
    for(int filho : filhos[i]){
        if(filho == i) continue;
        cout << "indo para " << filho << endl;
        findNew(filho);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> floors;

    for(int floor = 1; floor <= floors; floor++){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> patient[i];

        pai[1] = 1;
        for(int i = 2; i <= k + 1; i++){
            int father;
            cin >> father;
            filhos[father].push_back(i);
            pai[i] = father;
            if(patient[i] == '*'){
                head[i] = i;
                groupSize[i] = 1;
                saudavel.push_back(i);
            }
        }
        cin >> A >> B >> C;
        for(int i = k + 1; i <= n; i++)
            pai[i] = ((A * pai[i-2] + B * pai[i-1] + C) % (i - 1)) + 1;
        
        acharFilhos(1);
        findNew(1);
        
        cout << "Case #" << floor << ": " << maxPessoas << " " << possibili << "\n"; 
    }

    return 0;
}