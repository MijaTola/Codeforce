#include <bits/stdc++.h>

using namespace std;

int v[100010];
int b[100010];

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> v[i];
    
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        
        int pos = 0;

        while(v[pos] == b[pos]) pos++;
        
        set<int> s;

        bool flag = 1;
        while(b[pos] != v[pos] and pos < n) {
            flag &= b[pos] >= v[pos];
            s.insert(b[pos] - v[pos]);
            v[pos] = b[pos];
            pos++;
        }

        for (int i = 0; i < n; ++i)
            flag &= v[i] == b[i];
    
        puts(flag and s.size() <= 1 ? "yes" : "no");


    }
    return 0;
}

