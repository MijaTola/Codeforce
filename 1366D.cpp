#include <bits/stdc++.h>

using namespace std;

int p[10000010];
int p2[10000010];
int v[500010];

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
        
    for (int i = 2; i * i < 10000010; ++i) {
        if(p[i] != 0) continue;
        for (int j = i + i; j < 10000010; j += i) {
            p[j] = i;
        }
    }

    int n;
    cin >> n;
    
    vector<pair<int,int> > ans;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        
        int t = p[x];
        while(p[x] and x % t == 0) x /= p[x];
        if(__gcd(x + t, x) == 1) ans.emplace_back(x, t);
        else ans.emplace_back(-1, -1);
    }

    for (auto p: ans)
        cout << p.first << " ";
    cout << "\n";
    for (auto p: ans)
        cout << p.second << " ";
    
    cout << "\n";
   

    return 0;
}

