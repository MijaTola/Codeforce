#include <bits/stdc++.h>

using namespace std;
int n;
string x;


int main() {
    cin >> n >> x;
    
    int t = 0;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        t += (x[i] - '0');
        s.insert(x[i] - '0');
    }
    if(s.size() == 1) return cout << "YES\n",0;
    bool ans = 0;
    for (int i = 1; i < t; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += x[j] - '0';
            if(sum == i) 
                sum = 0;
        }
        ans |= (sum == 0);
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

