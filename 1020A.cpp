#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,h,a,b,q;
    cin >> n >> h >> a >> b >> q;

    while(q--) {
        int fa,ta,fb,tb;
        cin >> ta >> fa >> tb >> fb;
        long long ans = 0;

        if(ta == tb) {
            cout << abs(fa - fb) << "\n";
            continue;
        }
        if(a <= fa and fa <= b) {
            ans += abs(ta - tb);
            ans += abs(fa - fb);
        } else {
            if(abs(a - fa) < abs(b - fa)) {
                ans += abs(a - fa);
                fa = a;
            } else {
                ans += abs(b - fa);
                fa = b;
            }
            ans += abs(ta - tb);
            ans += abs(fa - fb);
        }
        cout << ans << "\n";
    }
    return 0;
}

