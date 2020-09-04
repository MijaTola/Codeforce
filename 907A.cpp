#include <bits/stdc++.h>

using namespace std;

int v[4];
int ans[4];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 4; ++i) cin >> v[i];
    for (int v3 = 1; v3 <= 1000; ++v3) {
        for (int v2 = v3 + 1; v2 <= 1000; ++v2) {
            for (int v1 = v2 + 1; v1 <= 1000; ++v1) {
                if(v[3] * 2 < v3 or v[3] > v3) continue;
                if(v[2] * 2 < v3 or v[2] > v3) continue;
                if(v[1] * 2 < v2 or v[1] > v2) continue;
                if(v[0] * 2 < v1 or v[0] > v1) continue;
                if(v[3] > v1 or v[3] * 2 >= v1) continue;
                if(v[3] > v2 or v[3] * 2 >= v2) continue;
                if(v[3] > v3) continue;
                cout << v1 << " " << v2 << " "<< v3 << "\n";
                return 0;
            }
        }
    }

    cout << "-1\n";
    return 0;
}

