#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,k,a,b;
    cin >> n >> k >> a >> b;
    int x = n;
    int ans = 0;

    while(n > 1) {
        while(n % k != 0) n--, ans+=a;
        if(b < (n - 1) * a) {
            n /= k;
            ans+=b;
        }else {
            ans += (n - 1) * a;
            break;
        }
    }
    cout << min(ans,(x - 1) * a) << "\n";
    return 0;
}

