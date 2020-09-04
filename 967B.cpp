#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    
    int n,a,b;
    cin >> n >> a >> b;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        total += v[i];   
    }
    
    sort(v + 1, v  + n);
    reverse(v + 1, v + n);
    
    int ans = 0;

    if((double)(v[0] * a) / (double)total >= b) {
        return cout << "0\n",0;
    }
    int cur = 0;
    for (int i = 1; i < n; ++i) {
        ans++;
        cur += v[i];
        double S = total - cur;
        double flow = (v[0] * a) / S;

        if(flow >= b) break;
    }
    cout << ans << "\n";
    return 0;
}

