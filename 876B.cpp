#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main(){
    
    int n,k,m;
    cin >> n >> k >> m;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v,v + n);
    
    return 0;
}

