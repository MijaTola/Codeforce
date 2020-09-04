#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,r;
        cin >> n >> r;
        long long ans = -1;
        if(r < n) {
            ans=(r * (r+1LL))/2LL;
        }else{
            ans=(n * (n-1LL)/2LL);
            ans++;
        }
        cout<<ans<<"\n";   
    }
    return 0;
}

