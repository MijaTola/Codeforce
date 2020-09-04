#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
    
    cin >> n;
    
    int b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x > 0) b += x;
        else c += x;
    }
    cout << b + abs(c) << "\n";
    return 0;
}

