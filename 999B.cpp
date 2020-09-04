#include <bits/stdc++.h>

using namespace std;

char v[110];
int main(){
    
    int n; cin >> n;
    string s; cin >> s;
    
    for (int i = 0; i < n; ++i) 
        v[i] = s[i];

    for (int i = 0; i < n; ++i) {
        if(n % (i + 1) == 0) {
            reverse(v, v + i + 1);
        }
    }

    for (int i = 0; i < n; ++i) 
        cout << v[i];
    cout << "\n";
    return 0;
}

