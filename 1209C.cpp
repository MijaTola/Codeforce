#include <bits/stdc++.h>

using namespace std;

int n,t;
string s;

int ans[200010];

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;

    while(t--) {

        cin >> n >> s;
        
        for (int i = 0; i < 10; ++i) {
            vector<int> a,b,c,da,db;
            for (int j = 0; j < n; ++j) {
                if((int)(s[j] - '0') < i) a.push_back(j);
                if((int)(s[j] - '0') > i) b.push_back(j);
                if((int)(s[j] - '0') == i) c.push_back(j);
            }
            for (int j = 0; j < (int)c.size(); ++j) {
                if(b.size() and c[j] < b[0]) db.push_back(c[j]);
                else if(a.size() == 0 or c[j] > a.back()) da.push_back(c[j]);
            }
            
            vector<int> cur;
            if(da.size() + db.size() == c.size()) {
                for (int x: a) {
                    ans[x] = 1;
                    cur.push_back(s[x] - '0');
                }
                for (int x: da) {
                    ans[x] = 1;
                    cur.push_back(s[x] - '0');
                }
                for (int x: db) {
                    ans[x] = 2;
                    cur.push_back(s[x] - '0');
                }
                for (int x: b) {
                    ans[x] = 2;
                    cur.push_back(s[x] - '0');
                }
                bool flag = 1;
                for (int j = 1; j < (int)cur.size(); ++j)
                    flag &= cur[j] >= cur[j - 1];
                if(!flag) continue;

                for (int i = 0; i < n; ++i)
                    cout << ans[i];
                cout << "\n";
                goto end;
            }
        }
        cout << "-\n";
        end:;
    }
    return 0;
}

