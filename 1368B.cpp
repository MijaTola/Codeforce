#include <bits/stdc++.h>

using namespace std;

string ans = "codeforces";

int main() {

    long long k;
    cin >> k;

    long long mn = 1e9;
    string res = "";
    int id = 0;
    long long pp = -1;
    for (long long dk = 2; dk < 10000; ++dk) {

        long long cur = 1, cnt = 0;
        while(cur < k) {
            cnt++;
            if(cur > k / dk) break;
            cur *= dk;
        }
            
        int len = ans.size();
        long long p = cnt;
        int sz = 0;
        long long pot = 1;
        while(len-- and p) {
            pot <<= 1LL;
            p--;
            sz += dk;
        }
        
        long long left = 0;
        
        int cnt = 0;
        if(pot < k) {
            pot <<= 1LL;
            cnt++;
            p--;
            len -= dk;
        }

        if(sz + (1 << cnt) + len < mn) {
            mn = sz + left + len;
            id = dk;
            pp = cnt;
        }
    }

    for (int i = 0; i < (int)ans.size() - 1; ++i) {
        if(pp) {
            for (int j = 0; j < id; ++j)
                res += ans[i];
            pp--;
        } else res += ans[i];
    }
 
    for (int i = 0; i < (1 << pp); ++i)
        res += ans.back();

    //cout << res.size() <<" \n";
    cout << res << "\n";

    return 0;
}

