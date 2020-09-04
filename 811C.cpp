#include <bits/stdc++.h>

using namespace std;

int n,v[5010],mn[5010], mx[5010], dp[5010];

int f(int pos){
    if(pos == n) return 0;
    if(dp[pos] != -1) return dp[pos];
    int ans = 0;
    if(pos == mn[v[pos]]){
        int cur = 0;
        set<int> s;
        bool flag = true;
        for (int i = pos; i <= mx[v[pos]]; ++i){
            int m1 = mn[v[i]];
            int m2 = mx[v[i]];
            if(m1 < mn[v[pos]] or m2 > mx[v[pos]]){
                cur = 0;
                flag = false;
                break;
            }
            if(!s.count(v[i])){
                cur ^= v[i];
                s.insert(v[i]);
            }
        }
        if(flag) ans = max(ans,f(mx[v[pos]] + 1) + cur);
    }
    ans = max(ans,f(pos + 1));
    return dp[pos] = ans; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 5010; ++i){
        mn[i] = 1e9;
        mx[i] = -1;
        dp[i] = -1;
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int cur = 0;
    set<int> s;
    for (int i = 0; i < n; ++i){
        if(!s.count(v[i])){
            cur ^= v[i];
            s.insert(v[i]);
        }
        mn[v[i]] = min(mn[v[i]],i);
        mx[v[i]] = max(mx[v[i]],i);
    }
   
    cout << max(cur, f(0)) << "\n";
    return 0;
}

