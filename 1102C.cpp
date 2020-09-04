#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    int n,x,y;
    cin >> n >> x >> y;
    
    int c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] <= x) c++;
    }

    if(x > y) return cout << n << "\n",0;
    
    cout << (c + 1)/ 2 << "\n";
    return 0;
}

