#include <bits/stdc++.h>

using namespace std;

bool vis[100010];

int main() {
    memset(vis, 0, sizeof vis);
    int a,b;
    cin >> a >> b;
    long long lim = a + b;
    long long i;
    for (i = 1; i * (i + 1) / 2 <= lim; ++i) {}

    long long mx = max(a,b);
    int pos = i - 1;
    lim = pos;
    vector<int> aa;
    while(mx > 0 and pos) {
        if(mx - pos >= 0) {
            aa.push_back(pos);
            vis[pos] = 1;
            mx -= pos;
        }
        pos--;
    }
    vector<int> bb;
    int s = 0;
    for (int i = 1; i <= lim and s <= min(a,b); ++i) {
        if(!vis[i]) { 
            s+= i;
            bb.push_back(i);
        }
    }


    if(max(a,b) == a) {
        cout << aa.size() << "\n";
        for (int i = 0; i < (int)aa.size(); ++i)
            cout << aa[i] << " ";
        cout << "\n";

        cout << bb.size() << "\n";
        for (int i = 0; i < (int)bb.size(); ++i)
            cout << bb[i] << " ";
        cout << "\n";
    } else {
        cout << bb.size() << "\n";
        for (int i = 0; i < (int)bb.size(); ++i)
            cout << bb[i] << " ";
        cout << "\n";

        cout << aa.size() << "\n";
        for (int i = 0; i < (int)aa.size(); ++i)
            cout << aa[i] << " ";
        cout << "\n";


    }


    return 0;
}

