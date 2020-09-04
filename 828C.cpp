#include <bits/stdc++.h>

using namespace std;

int n;
string s[3000010];
int v[4000100];
int pos[4000100];
char c[3000100];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int sz = 0;
    memset(pos, -1, sizeof pos);
    for (int i = 0; i < n; ++i){
        cin >> s[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j){
            int x; cin >> x;
            x--;
            if((int)s[i].size() > v[x]){
                v[x] = (int)s[i].size();
                pos[x] = i;
            }
            sz = max(sz, (int)s[i].size() + x);
        }
    }
    memset(c,'a',sizeof c);
    int cur = 0;
    for (int i = 0; i < sz; ++i){
        int finish = i + v[i];
        if(finish < cur or pos[i] == -1) continue;
        cur = max(cur,i);
        for (int j = max(0,cur - i); j < (int)s[pos[i]].size(); ++j)
            c[cur++] = s[pos[i]][j];
    }

    for (int i = 0; i < sz; ++i)
        cout << c[i];
    cout << "\n";
    return 0;
}
