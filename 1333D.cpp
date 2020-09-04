#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k;
    string s;
    cin >> n >> k >> s;

    int mx = 0;

    for (int i = 0, cur = 0; i < n; ++i) {
       if(s[i] == 'L')
           mx += i - cur++;
    }
    
    if(mx < k) return cout << "-1\n", 0;
    
    int cnt = 0;
    bool flag = 1;
    int ini = 0;
    string t = s;

    while(flag) {
        flag = 0;
        int end = -1;
        for (int i = 0; i < n; ++i) {
            if(t[i] == 'L' and i - end > 1) {
                flag = 1;
                swap(t[i], t[i - 1]);
                end = i;
                ini++;
            }
            if(t[i] == 'L')
                end = i;
        }
        cnt += flag;
    }

    if(k < cnt) return cout << "-1\n",0;
    
    vector<vector<int> > ans;

    while(mx > k) {
        vector<int> cur;
        int last = -1;
        int cnt = 0;
        for (int i = 0; i < n and mx - (cnt - 1) > k; ++i) {
            if(s[i] == 'L' and i - last > 1) {
                cur.push_back(i - 1);
                swap(s[i], s[i - 1]);
                last = i;
                cnt++;
            }
            if(s[i] == 'L') last = i;
        }
        mx -= (cnt - 1);
        ans.push_back(cur);
    }

    vector<int> pos;
    for (int i = 0; i < n; ++i) 
        if(s[i] == 'L') pos.push_back(i);
    

    int r = 0;
    for (int cur: pos) {
        vector<int> v;
        while(cur > r) 
            ans.push_back({--cur});
        r++;
        if(v.size()) ans.push_back(v);
    }

    for (auto v: ans) {
        cout << v.size() << " ";
        for (auto x: v)
            cout << x + 1<< " ";
        cout << "\n";
    }
    return 0;
}

