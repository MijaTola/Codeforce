#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
    int n,k;
    cin >> n >> k;
    memset(v,-1,sizeof v);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x] = i;
    }
    vector<int> b;
    for (int i = 0; i < 110; ++i) {
        if(v[i] != -1) b.push_back(v[i]);  
    }
    if((int)b.size() < k) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < k; ++i) 
            cout << b[i] + 1 << " ";
    }
    return 0;
}

