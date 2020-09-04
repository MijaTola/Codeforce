#include <bits/stdc++.h>

using namespace std;

int n; 
int v[11];

int main(){
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    
    for (int i = 0; i < n; ++i) {
        int cur = v[i];
        int sum = s - cur;
        if(cur != sum and cur and sum) {
            cout << "1\n";
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "-1";
    return 0;
}

