#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main(){
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> v[i];

    
    vector<int> a;
    for (int i = 0; i < n - 1; ++i) {
        if(v[i] >= v[i + 1])a.push_back(v[i]);
    }
    a.push_back(v[n - 1]);
    cout << a.size() << "\n";
    for (int i = 0; i < (int)a.size(); ++i) 
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}

