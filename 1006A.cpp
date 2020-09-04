#include <bits/stdc++.h>

using namespace std;

int v[1010];
set<int> s;
int main(){

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s.insert(v[i]);
    }

        for (int p: s) {
            for (int i = 0; i < n; ++i) {
                if(v[i] == p) {
                    if(p & 1) v[i]++;
                    else v[i]--;
                    s.insert(v[i]);
                }
            }
        }
    for (int i = 0; i < n; ++i)
        cout << v[i] <<  " ";
    return 0;
}

