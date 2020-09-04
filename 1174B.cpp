#include <bits/stdc++.h>

using namespace std;

vector<int> pa,pb;
int v[100010];
int main() {
    
    int n;
    cin >> n;
    int a = 0 , b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] & 1) a++;
        else b++;
    }
    
    if(a and b) {
        sort(v, v + n);
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) cout << v[i] << " ";
    cout << "\n";
 
    
    return 0;
}

