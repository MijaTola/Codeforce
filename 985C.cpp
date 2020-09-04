#include <bits/stdc++.h>

using namespace std;

int n,k,l;
int v[100010];
int main() {
    cin >> n >> k >> l ;
    for (int i = 0; i < n * k; ++i)
        cin >> v[i];
    sort(v, v + n * k);
    if(v[n - 1] - v[0] > l) return cout << "0\n",0;
    int pos = upper_bound(v, v + n * k, v[0] + l) - v; 
    pos--;
    
    int cur = n - 1, cnt = 0;
    long long ans = 0;
    while(cur >= 0) {
        if(cur > pos) {cur -= (k - 1), cnt++, cur -= (k - 1);}
        else {
            if(cnt) ans += v[cur], cur--;
            else cnt++, cur -= (k - 1);
        }
    }
    cout << ans << "\n";

    return 0;
}

