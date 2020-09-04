#include <bits/stdc++.h>

using namespace std;

int v[300010];

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) 
        cin >> v[i];


    int a1 = n - 1;
    int a2 = 0;
    while(v[a1] == v[0] and a1 > 0) a1--;
    while(v[a2] == v[n - 1] and a2 < n - 1) a2++;
    cout << max((a1 - 0) , (n - 1) - a2 ) << "\n";
    return 0;
}

