#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    scanf("%d %d", &n, &k);

    int cnt = 0;

    for (int i = 1; i <= n; ++i) 
        for (int j = i + 1; j <= n; ++j)
            cnt++;

    if(cnt <= k) return puts("no solution"),0;

    int p = 0;

    vector<int> v;
    for (int i = 1; i <= 2000; ++i) {
        p += i;
        v.push_back(p);
    }
    reverse(v.begin(), v.end());

    vector<pair<int,int> > ans;

    for (int i = 0; i < n; ++i) 
        ans.emplace_back(0, i);
    
    
    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";
    return 0;
}

