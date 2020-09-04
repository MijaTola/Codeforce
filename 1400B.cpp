#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);

    int k;
    cin >> k;

    while(k--) {

        long long p,f,cs,cw,s,w;
        cin >> p >> f >> cs >> cw >> s >> w;
        
        long long ans = 0;

        if(w < s) {
            swap(w,s);
            swap(cs,cw);
            swap(p,f);
        }


        for (int i = 0; i <= cs; ++i) {

            long long curP = i;
            long long curF = cs - i;

            long long canP = p / s;
            long long canF = f / s;

            long long totalP = min(canP, curP);
            long long totalF = min(canF, curF);

            long long dp = p - totalP * s;
            long long df = f - totalF * s;
            
            dp /= w;
            df /= w;

            ans = max(ans, totalP + totalF + min(cw,dp + df));
        }

        cout << ans << "\n";
            


    }
    return 0;
}

