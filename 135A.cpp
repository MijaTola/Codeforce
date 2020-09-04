#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    
    int n;
    cin >> n;
    for (int i = 0; i< n; ++i) cin >> v[i];

    sort(v,v + n);
    
    int cur = 1;
    while(cur == v[n - 1]) cur++;
    v[n - 1] = cur;
    sort(v,v + n);
    
    for (int i = 0; i < n; ++i) 
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}

