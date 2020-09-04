#include <bits/stdc++.h>

using namespace std;

vector<int> op;
int cl[1000010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        int c = 0;
        for (int j = 0; j < (int)s.size(); ++j) 
            c += s[j] == '(' ? 1 : -1;
        
        if(c > 0) {
            int cur = 0;
            bool flag = 1;
            for (int j = 0; j < (int) s.size(); ++j) {
                cur += s[j] == '(' ? 1 : -1;
                flag &= cur >= 0;
            }
            if(flag and cur >= 0) op.push_back(cur);
        } 
        if(c < 0) {
            int cur = 0;
            bool flag = 1;
            for (int j = s.size() - 1; j >= 0; j--) {
                cur += s[j] == '(' ? 1 : -1;
                flag &= cur <= 0;
            }
            if(flag and cur <= 0) cl[abs(cur)]++;
        }
        if(c == 0) {
            int cur = 0;
            bool flag = 1;
            for (int j = 0; j < (int)s.size(); ++j) {
                cur += s[j] == '(' ? 1 : -1;
                flag &= cur >= 0;
            }
            if(flag) sum++;
        }
    }

    int ans = 0;
    for (int i = 0; i < (int)op.size(); ++i) {
        if(cl[op[i]]) {
            ans++;
            cl[op[i]]--;
        }
    }
    cout << ans + sum / 2 << "\n";
    return 0;
}

