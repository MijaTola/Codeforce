#include <bits/stdc++.h>

using namespace std;

string s;
int dp[11][11][2];
int f(int l, int r, int flag) {
    if(l >= r) return 1;
    int &ans = dp[l][r][flag];
    if(ans != -1) return ans;
    ans = 0;
    if(s[l] == s[r]) ans |= f(l + 1, r - 1, flag);
    else if(flag) {
        ans |= f(l + 1, r, 0);
        ans |= f(l, r - 1, 0);
    }
    return ans;
}

stack<char> b;
queue<char> a;
void build(int l, int r, int flag) {
    if(l >= r) {
        if(l == r) a.push(s[l]);
        return;
    }
    if(s[l] == s[r]) {
        a.push(s[l]);
        b.push(s[l]);
        build(l + 1, r - 1, flag);
    } else if(flag) {
        if(f(l + 1, r, 0)) {
            a.push(s[l]);
            b.push(s[l]);
            build(l + 1, r, 0);
            return;
        }
        if(f(l, r - 1, 0)) {
            a.push(s[r]);
            b.push(s[r]);
            build(l, r - 1, 0);
            return;
        }
    }
}
int main(){
    memset(dp, -1, sizeof dp);
	cin >> s;
    int ans = f(0, s.size() - 1, 1);
    if(!ans) return cout << "NA\n",0;
    build(0, s.size() - 1, 1);
    int sz = a.size() + b.size();

    while(!a.empty()) {
        cout << a.front();
        a.pop();
    }
    if(sz == (int)s.size()) cout << s[s.size() / 2];
    while(!b.empty()) {
        cout << b.top();
        b.pop();
    }
    cout << "\n";
	return 0;
}
