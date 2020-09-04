#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 31; i >= 0; i--) {
        int cnt = 0;

        for (int j = 0; j < n; ++j) {
            cnt += (bool)(v[j] & (1 << i));
        }
            
        if(cnt == 1) {
            for (int j = 0; j < n; ++j) 
                if(v[j] & (1 << i)) 
                    swap(v[0], v[j]);
            break;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}

