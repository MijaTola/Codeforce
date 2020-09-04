#include <bits/stdc++.h>

using namespace std;

int n; 
int v[100010];
int pos[100010];
bool win[100010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    for (int i = n; i >= 1; --i) {
        int p = pos[i];
        int j = p - i;
        int mx = 0;
        bool flag = 0;
        while(j >= 0) {
            if(v[j] > v[p]) {
                flag |= !win[j];
            }
            j -= i;
        }
        j = p + i;
        while(j < n) {
            if(v[j] > v[p])  {
                flag |= !win[j];
            }
            j += i;
        }
        win[p] = flag;
    }
    

    for (int i = 0; i < n; ++i) {
        if(win[i]) cout << "A";
        else cout << "B";
    }
    cout << "\n";
    return 0;
}

