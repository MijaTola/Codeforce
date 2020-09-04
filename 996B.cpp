#include <bits/stdc++.h>

using namespace std;

int v[200010];
int n;

int main(){
    
    cin >> n;
    int mn = INT_MAX;
    int id = -1;
    for (int i = 0; i < n;++i) {
        cin >> v[i];
        if(v[i] < mn) {
            mn = v[i];
            id = i;
        }
    }
    
    for (int i = 0; i < n; ++i) 
        v[i] -= mn;

    int pos = mn % n;
    int cur = 0;
    while(v[pos] - cur > 0) {
        pos = (pos + 1) % n;
        cur++;
    }
    cout << pos  + 1 << "\n";
    return 0;
}

