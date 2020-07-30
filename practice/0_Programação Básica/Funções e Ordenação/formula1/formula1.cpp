#include <bits/stdc++.h>
using namespace std;

struct Piloto{
    int pontos = 0, id, posi[100];
};
bool pegaPilot(Piloto a, Piloto b){
    if(a.pontos != b.pontos) return a.pontos > b.pontos;
    else return a.id < b.id;
}
int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int gpremios, pilotos, nsispt, sispt[100];
    while(true){
        cin >> gpremios >> pilotos;
        if(gpremios == 0 && pilotos == 0) break;

        Piloto piloto[pilotos];
        
        for(int x = 0; x < gpremios; x++){
            for(int y = 0; y < pilotos; y++){
                cin >> piloto[y].posi[x];
                piloto[y].id = y+1;
            }
        }
        cin >> nsispt;
        for(int x = 0; x < nsispt; x++){
            int ptmax;
            cin >> ptmax;
            for(int p = 0; p < pilotos; p++){
                piloto[p].pontos = 0;
            }
            for(int y = 0; y < ptmax; y++){
                cin >> sispt[y];
                for(int p = 0; p < pilotos; p++){
                    for(int z = 0;z < gpremios; z++){
                        if(piloto[p].posi[z] == y+1){
                            //printf("piloto %d, pta = %d\n",p+1,piloto[p].pontos);
                            if(piloto[p].pontos > 0 && (z > 0 || y > 0)) piloto[p].pontos += sispt[y];
                            else piloto[p].pontos = sispt[y];
                            //printf("piloto %d, pt = %d\n",p+1,piloto[p].pontos);
                        }
                    }
                }
            }
            sort(piloto, piloto+pilotos, pegaPilot);
            for(int z = 0; z < pilotos; z++){
                if(z == 0 || piloto[z].pontos == piloto[0].pontos)
                    cout << piloto[z].id << " ";
            }
            cout << "\n";
        }
    }
}