#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;

    vector<long long> da,db,c,d;
    for (int i = 0; i < n; ++i) {
        int t,a,b;
        cin >> t >> a >> b;
        if(a and b) c.push_back(t);
        else if(a and !b) da.push_back(t);
        else if(!a and b) db.push_back(t);
        else d.push_back(t);
    }


    sort(c.begin(), c.end());
    sort(da.begin(), da.end());
    sort(db.begin(), db.end());


    for (int i = 1; i < (int)da.size(); ++i) 
        da[i] += da[i - 1];


    for (int i = 1; i < (int)db.size(); ++i)
        db[i] += db[i - 1];

    long long ans = 1e15;
    long long sum = 0;

    for (int i = 0; i < min(k, (int)c.size()); ++i) {
        sum += c[i];
        long long dk = i + 1;
        long long left = k - dk;
        if(left > 0 and (int)da.size() >= left and (int)db.size() >= left) {
            long long cur =  sum + da[left - 1] + db[left - 1];
            ans = min(ans, cur);
        }

        if(left == 0) ans = min(ans,sum);
    }
    
    int left = k;
    if(left > 0 and (int)da.size() >= left and (int)db.size() >= left) {
        long long cur =  da[left - 1] + db[left - 1];
        ans = min(ans, cur);
    }

    if(ans == 1e15) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

