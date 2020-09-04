#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        ans += x;
    }

    long long p = ans / (n - 1);
    cout << p << "\n";

    return 0;
}

