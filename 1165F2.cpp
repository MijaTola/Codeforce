#include <bits/stdc++.h>

using namespace std;

int dk[200010];
int ck[200010];
vector<int> s[200010];

int main() {
    
    int n,m;
    cin >> n >> m;
    
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> dk[i];
        total += dk[i];
    }

    for (int i = 0; i < m; ++i) {
        int d,t;
        cin >> d >> t;
        s[t].push_back(d);
    }

    for (int i = 1; i<= n; ++i) {
        sort(s[i].begin(), s[i].end());
    }

    int a = -1, b = 1e6;

    auto check = [&] (int k) {
        vector<pair<int,int> > sales;
        for (int i = 1; i <= n; ++i) {
            ck[i] = dk[i];
            auto pos = upper_bound(s[i].begin(), s[i].end(), k) - s[i].begin() - 1;
            if(!s[i].size() or pos < 0) continue;
            sales.emplace_back(s[i][pos], i);
        }

        sort(sales.begin(), sales.end());
        int used = 0;
        for (int i = 0; i < (int)sales.size(); ++i) {
            int current = sales[i].first - used;
            if(current <= 0) continue;
            int mn = min(ck[sales[i].second], current);
            used += mn;
            ck[sales[i].second] -= mn;
        }
        
        int needed = 0;
        int left = k - used;

        for (int i = 1; i <= n; ++i)
            needed += ck[i];
        
        return 2 * needed <= left;
    };
    

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(check(mid)) b = mid;
        else a = mid;
    }

    cout << b << "\n";
    return 0;
}

