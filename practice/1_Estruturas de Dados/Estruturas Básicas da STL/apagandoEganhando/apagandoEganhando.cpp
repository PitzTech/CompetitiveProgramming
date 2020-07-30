#include <bits/stdc++.h>

#define MAX 100100

using namespace std;

char pilha[MAX], atual;
int topo, numeros, apagar, apagados, x;

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    while(scanf("%d %d", &numeros, &apagar) && (numeros+apagar)){
		
        	apagados = 0;
        	for(x = 0, topo = -1; x < numeros; x++){

	        	scanf(" %c", &atual);
			
            	while(topo > -1 && apagados < apagar && atual > pilha[topo]){
                    topo--;
                    apagados++;
                }
            	if(topo+1 < numeros-apagar) pilha[++topo] = atual;
        	}
		
	        pilha[++topo] = '\0';
        
		printf("%s\n", pilha);
    }
	
    return 0;
}