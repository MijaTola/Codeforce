#include <bits/stdc++.h>

using namespace std;

int v[110];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,d;
        cin >> n >> d;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
    

        for (int i = 1; i < n and d; ++i) {
            while(v[i] and d) {
                if(d >= i) {
                    d -= i;
                    v[0]++;
                    v[i]--;
                } else break;
            }
        }
        cout << v[0] << "\n";
    }
    return 0;
}

