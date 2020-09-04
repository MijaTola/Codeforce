#include <bits/stdc++.h>

using namespace std;

vector<int> e,o;
long long f(bool flag, long long te, long long to) {
    
    long long ed = 0;
    long long od = 0;
    while(true) {
        if(flag and ed >= (int)e.size()) break;
        if(!flag and od >= (int)o.size()) break;
        if(flag) te -= e[ed++];
        else to -= o[od++];
        flag = !flag;
    }
    return te + to;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x & 1) o.push_back(x);
        else e.push_back(x);
    }
    
    sort(o.rbegin(), o.rend());
    sort(e.rbegin(), e.rend());
    long long s1 = 0, s2 = 0;
    for (int x: o) s1 += x;
    for (int x: e) s2 += x;
    cout << min(f(1, s2, s1) , f(0, s2,s1)) << "\n";
    return 0;
}

