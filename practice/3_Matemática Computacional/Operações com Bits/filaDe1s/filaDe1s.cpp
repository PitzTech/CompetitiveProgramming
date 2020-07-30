#include <bits/stdc++.h> 
using namespace std; 
  
char areAllBitsSet(int n){ 

    if (n == 0) 
        return 'N'; 

    while(n > 0){ 
        // if the last bit is not set 
        if ((n & 1) == 0) 
            return 'N'; 
  
        // right shift 'n' by 1 
        n = n >> 1; 
    } 

    return 'S'; 
} 

int main(){ 
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n; 
    scanf("%d", &n);
    printf("%c",areAllBitsSet(n)); 

    return 0; 
} 