#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    int n,d;
    cin >> n >> d;
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v, v + n);
    set<int> ans;
    for (int i = 0; i < n; ++i) {
        int d1 = v[i] - d;
        int d2 = v[i] + d;
        bool b1 = 1;
        bool b2 = 1;

        for (int j = 0; j < n; ++j) {
            if(abs(d1 - v[j]) < d) b1 = 0;
            if(abs(d2 - v[j]) < d) b2 = 0;
        }
        if(b1) ans.insert(d1);
        if(b2) ans.insert(d2);
    }
    cout << ans.size() << "\n";

    return 0;
}

