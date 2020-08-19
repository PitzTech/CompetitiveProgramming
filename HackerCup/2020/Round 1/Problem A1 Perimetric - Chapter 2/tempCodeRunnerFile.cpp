coords[i-2].l %= DL;
            coords[i-1].l %= DL;
            coords[i-2].h %= DH;
            coords[i-1].h %= DH;

            coords[i].l = ((AL*coords[i-2].l + BL * coords[i-1].l + CL) % DL)+1;
            coords[i].l = ((AH*coords[i-2].h + BH * coords[i-1].h + CH) % DH)+1;