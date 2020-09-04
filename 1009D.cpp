#include <bits/stdc++.h>

using namespace std;

bool p[100010];

int main(){
    memset(p, 0, sizeof p);
    p[0] = p[1] = 1;
    for (int i = 2; i * i < 100010; ++i) {
        int c = i + i;
        if(p[i]) continue;
        while(c < 100010) {
            p[c]++;
            c += i;
        }
    }
    
    return 0;
}

