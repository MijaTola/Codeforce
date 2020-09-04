#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int c[200010];
int ans[200010];
string s;
priority_queue<pair<int,pair<int,int> > > pi,pe;

int main(){
    memset(c,0,sizeof c);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        pi.push({0,{-v[i],i}});
    }

    string s; cin >> s;

    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '0') {
            int no = pi.top().first;
            int wd = pi.top().second.first;
            int id = pi.top().second.second;
            pi.pop();
            ans[i] = id;
            pe.push({100,{-wd,id}});
        } else {
            int no = pe.top().first;
            int wd = pe.top().second.first;
            int id = pe.top().second.second;
            pe.pop();
            ans[i] = id;
        }
    }

    for (int i = 0; i < (int)s.size(); ++i) 
        cout << ans[i] + 1<< " ";
    cout << "\n";

    return 0;
}

