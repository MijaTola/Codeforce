#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;

int main() {

    cin >> n >> k >> s;
    
    int total = 0;

    vector<pair<pair<int,int>, pair<int, char> > > v;

    for (int i = 0; i < n; ++i) {
        char x = s[i];
        if('z' - x > x - 'a') v.push_back({{'z' - x, 'z' - x}, {i, x}}), total += 'z' - x;
        else v.push_back({{x - 'a', 'a' - x}, {i, x}}), total += x - 'a';
    }
    if(total < k) return cout << "-1\n",0;
        
    sort(v.rbegin(), v.rend());
    

    for (auto &p: v) {
        int mn = -1;
        if(k < p.first.first) {
            if(p.first.second < 0) mn = -k;
            else mn = k;
        } else mn = p.first.second;
        k -= abs(mn);
        p.second.second += mn;
    }
    
    vector<pair<int,char> > ans;

    for (auto p: v)
        ans.emplace_back(p.second.first, p.second.second);
    
    sort(ans.begin(), ans.end());

    for (auto p: ans)
        cout << p.second;
    cout << "\n";


    return 0;
}

