#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
void f(set<int> s, vector<int> v) {
    if(s.empty()) {
        bool flag = 0;
        if(ans.size() == 0) flag = 1;
        else {
        for (int i = 0; i < (int)v.size(); ++i) {
            if(v[i] > ans[i]) {
                flag = 1;
                break;
            } else if(ans[i] > v[i]) break;
        }
        }
        if(flag) {
            ans.clear();
            ans = v;
        }
        return;
    }
    set<int> ss = s;
    for (int x: s) {
        ss.erase(x);
        int gcd = 0;
        for (int y: ss) 
            gcd = __gcd(gcd,y);
        v.push_back(gcd);
        f(ss,v);
        ss.insert(x);
        v.pop_back();
    }
}
int main() {
    int n; cin >> n;
    
    set<int> s;
    for (int i = 1; i <=n; ++i)
        s.insert(i);
    if(n == 1) return cout << 1 << "\n",0;
    if(n == 3) return cout << "1 1 3\n",0;
    int p = 1;
    int x = n;
    while(n > 0) {
        if(n == 1) cout << p << " ";
        if(n == 2) cout << p << " " << 2 * p << " ", n = 0;
        if(n == 3) cout << p << " " << p << " " << 3 * p << " ", n = 0;
        int d = n / 2;
        int r = n - d;
        n = d;
        for (int i = 0; i < r; ++i)
            cout << p << " ";
        p <<= 1;
    }
    cout << "\n";
    return 0;
}

