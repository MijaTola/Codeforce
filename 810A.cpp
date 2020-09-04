#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,k;
    cin >> n >> k;
    
    double a = 0.0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        a += x;
    }
    double dk = k - 0.5;
    int ans = 0;
    while(double(a / (n + ans)) < dk){
        ans++; a += k;
    }
    cout << ans << "\n";
    return 0;
}

