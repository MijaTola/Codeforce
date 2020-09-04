#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
int t[100010];


int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    for (int i = 0; i < n; ++i)
        cin >> t[i];
    

    for (int i = n - 2; i >= 0; i--) 
        t[i] += t[i + 1];
    
    vector<int> ans;

    for (int i = n - 1; i >= 0; i++) {
    
    }
    
    return 0;
}

