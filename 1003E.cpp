#include <bits/stdc++.h>

using namespace std;

int n,d,k;
int nd = 1;
vector<pair<int,int> > v;
bool f(int p) {
    if(p == k) return 1;
    if(nd == n) return 1;
    if(nd > n) return 0;
    

    int c = p == 1 ? 0 : 1;
    
    int ans = 1;

    int u = nd;

    while(c < d) {
        c++;
        if(nd + 1 <= n) {
            v.emplace_back(u, nd + 1);
            nd++;
            ans |= f(p + 1);
        }
    }

    return 1;
}

int main() {
    cout << "here\n";
    cin >> n >> d >> k;
    swap(d,k);
    cout << (f(1) and nd == n ? "YES" : "NO") << "\n";

    for (auto p: v)
        cout << p.first << " " << p.second << "\n";

    return 0;
}

