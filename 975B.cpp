#include <bits/stdc++.h>

using namespace std;

int v[15];
int b[15];
int main(){
    
    for (int i = 0; i < 14; ++i) 
        cin >> v[i];

    long long ans = 0;
    for (int i = 0; i < 14; ++i) {

        int pos = (i + 1) % 14;
        int cur = v[i];
        if(cur <= 0) continue;
        for (int j = 0; j < 14; ++j)
            b[j] = v[j];
        b[i] = 0;

        int div = cur / 14;
        for (int j = 0; j < 14; ++j)
            b[j] += div;

        int mod = cur % 14;
        while(mod) {
            b[pos]++;
            mod--;
            pos = (pos + 1) % 14;
        }
        

        long long sum = 0;
        for (int j = 0; j < 14; ++j)
            if(b[j] % 2 == 0) sum += b[j];

        ans = max(ans,sum);
    }
    cout << ans <<"\n";
    return 0;
}

