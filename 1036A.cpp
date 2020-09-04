#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long ans = k / n;
    if(k % n != 0) ans++;
    cout << ans << "\n";
    return 0;
}

