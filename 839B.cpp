#include <bits/stdc++.h>

using namespace std;

int v[110];
int n,k;

int main(){
    cin >> n >> k;
    
    for (int i = 0; i < k; ++i)
        cin >> v[i];
    
    sort(v, v + n); reverse(v, v + n);
    
    return 0;
}
