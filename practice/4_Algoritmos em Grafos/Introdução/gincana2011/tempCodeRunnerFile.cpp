or(int i = 0; i < amigos[x].size(); i++){
                if(times[y].find(i) != times[y].end()){
                    times[y].insert(x);
                    times[y].insert(amigos[x].begin(),amigos[x].end());
                    encontrou = true;
                }
            }