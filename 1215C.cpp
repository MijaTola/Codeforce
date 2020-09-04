#include <bits/stdc++.h>

using namespace std;

int n;
string s,t;
vector< pair<int,int> > ans;
queue<int> ab,ba;
int main() {
    cin >> n >> s >> t;
    
    for (int i = 0; i < n; ++i) {
        if(s[i] != t[i]) {
            if(s[i] == 'a')ab.push(i + 1);
            else ba.push(i + 1);
        }
    }

    while(ab.size() >= 2) {
        int x = ab.front();
        ab.pop();
        int y = ab.front();
        ab.pop();
        ans.push_back({x,y});
    }

    while(ba.size() >= 2) {
        int x = ba.front();
        ba.pop();
        int y = ba.front();
        ba.pop();
        ans.push_back({x,y});
    }
    
    if(ba.size() and ab.size()) {
        int x = ab.front();
        ab.pop();
        int y = ba.front();
        ba.pop();
        ans.push_back({x,x});
        ans.push_back({x,y});
    }
    if(ab.size() or ba.size()) return cout << "-1\n",0;

    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";
    return 0;
}

