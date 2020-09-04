#include <bits/stdc++.h>

using namespace std;

int v[100];

int main() {

    int n;
    cin >> n;


    for (int i = 0; i < n; ++i)
        cin >> v[i];

    if(n == 1) {
        if(v[0] == 15) cout << "DOWN\n";
        else if(v[0] == 0) cout << "UP\n";
        else cout << "-1\n";
        return 0;
    }

    int cur = 0;

    if(v[1] > v[0]) cur = 1;

    for (int i = 1; i < n; ++i) {
        
        if(v[i] == 0 or v[i] == 15) {
            cur = 1 - cur;
            continue;
        }

        if(cur) {
            if(v[i] <= v[i - 1]) return cout << "-1\n", 0;
        } else {
            if(v[i] >= v[i - 1]) return cout << "-1\n", 0;
        }
    }

    if(cur) cout << "UP\n";
    else cout << "DOWN\n";
    return 0;
}

