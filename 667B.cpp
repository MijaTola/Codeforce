#include <bits/stdc++.h>

using namespace std;

long long v[100010];
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    sort(v,v + n);
    reverse(v,v + n);
        
    long long sum = 0;
    for (int i = 1; i < n; ++i) 
        sum += v[i];
    
    cout << v[0] - sum + 1 << "\n";
    return 0;
}

