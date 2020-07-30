#include <bits/stdc++.h>

using namespace std;

map<string, string> dict;
map<string, string>::iterator it;
string from, to;
char auxil[82], aux2[82];
int t, m, n, fs;

int main () {
    scanf("%d", &t);

    while (t--) {
        dict.clear();

        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            scanf(" %s", auxil);
            from = auxil;
            scanf(" %[a-z ]", auxil);
            to = auxil;

            dict.insert(make_pair(from, to));
        }

        for (int i = 0; i < n; i++) {
            fs = 0;
            scanf(" %[a-z ]", auxil);
            while(sscanf(auxil+fs, "%s", aux2) != EOF) {
                if (fs) {
                    printf(" ");
                    fs++;
                }

                it = dict.find(aux2);
                if (it == dict.end()) {
                    printf("%s", aux2);
                } else {
                    printf("%s", it->second.c_str());
                }
                
                fs += strlen(aux2);
            }
            printf("\n");
        }
        printf("\n");
    }
}