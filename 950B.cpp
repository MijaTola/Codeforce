#include <bits/stdc++.h>

using namespace std;

int b[100010];
int v[100010];

int getv(int i, int j) {
    return v[j] - v[i];
}
int getb(int i, int j) {
    return b[j] - b[i];
}

int main(){
    
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int j = 0; j < m; ++j) 
        cin >> b[j];
    
    for (int i = 1; i < n; ++i) 
        v[i] += v[i - 1];
    
    for (int i = 1; i < m; ++i) 
        b[i] += b[i - 1];

    int pv = 0, pb = 0;
    int ev = -1, eb = -1;
    int ans = 0;

    while(pv < n and pb < m) {
        if(getv(ev,pv) == getb(eb,pb)) {
            ans++;
            ev = pv;
            eb = pb;
            pv++,pb++;
        }else if(getv(ev,pv) > getb(eb,pb)) pb++;
        else pv++;
    }
    cout << ans << "\n";
    return 0;
}

