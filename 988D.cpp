#include <bits/stdc++.h>

using namespace std;

int n;
long long v[200010];
vector<long long> p;
set<long long> s;
int main(){

    for (int i = 0; i < 32; ++i) 
        p.push_back(1LL << i);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s.insert(v[i]);
    }

    sort(v, v + n);

    vector<long long> ans;
    for (int i = 0; i < n; ++i) {
        for (long long x: p) {
            vector<long long> cur;
            cur.push_back(v[i]);
            long long b = v[i] + x;
            long long c = v[i] + 2 * x;
            if(s.count(b)) cur.push_back(b);
            if(s.count(c)) cur.push_back(c);
            if((int)cur.size() > (int)ans.size())
                ans = cur;
        }
    }
    cout << ans.size() << "\n";
    for (int a: ans)
        cout << a << " ";
    cout << "\n";
    return 0;
}

