#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n,k;
    cin >> n >> k;

    long long cur = k / 2LL + 1;
       

    long long mn = min(n, k - 1);
    cout << max(mn - cur + 1,0LL) << "\n";
    return 0;
}

