    for(int z = shards - 2; z > 1; z--){
                soma = colors[z-1] + colors[z] + colors[z+1];
                if(soma % 'A' != 0 || soma % 'B' != 0){
                    if(colors[z-1] != colors[z] && colors[z] == colors[z+1])
                            colors[z-1] = colors[z];
                    colors.erase(colors.begin() + z, colors.begin() + z + 1);
                    shards -= 2;
                    find = true;
                    break;
                }
            }