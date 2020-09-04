#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n;
string s;
vector<int> v;
int dp[200010][2];
int f(int pos, bool flag) {
    if(pos == (int)v.size()) return flag;
    int &ans = dp[pos][flag];
    if(ans != -1) return ans;
    ans = 0;
    ans = (ans + f(pos + 1, flag)) % mod;
    for (int i = 0; i < v[pos]; ++i) ans = (ans + f(pos + 1, 1)) % mod;
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    stack<char> st;
    string t = "";
    for (char x: s) {
        if(st.empty()) {
            st.push(x);
            t += x;
        } else {
            if(st.top() == x and x == 'b') continue;
            if(x != 'a' and x != 'b') continue;
            t += x;
            st.push(x);
        }
    }
    int c = 0 ;
    for (int i = 0; i < (int)t.size(); ++i) {
        if(t[i] == 'a') c++;
        else {
            v.push_back(c);
            c = 0;
        }
    }
    if(c) v.push_back(c);
    cout << f(0,0) << "\n";
    return 0;
}
