#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v,v + n);
    
    long double media = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        media += v[i];
    }
    int pos = 0;
    while(media / n < 4.5) {
        ans++;
        media -= v[pos++];
        media += 5.0;
    }
    cout << ans << "\n";
    return 0;
}

