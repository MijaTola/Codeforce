#include <bits/stdc++.h>

using namespace std;

string s[100010];
string ss;
vector<pair<int,int> > v;

int b[100010];
int main(){

    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s[i];
        int ds = 0, dh = 0;
        for (int j = 0; j < (int)s[i].size(); ++j) {
            if(s[i][j] == 's') ds++;
            else dh++;
        }

        int dif = ds - dh;
        if(ds and !dh) v.push_back(make_pair(1e9,i));
        else if(!ds and dh) v.push_back(make_pair(-1e9,i));
        else v.push_back(make_pair(dif,i));
    }

    sort(v.rbegin(),v.rend());
    
    ss = "";
    for (int i = 0; i < (int)v.size(); ++i) 
        ss += s[v[i].second];
    
    for (int i = ss.size() - 1; i >= 0; --i) {
        if(ss[i] == 'h') b[i] = 1;
        b[i] += b[i + 1];
    }
    long long ans = 0;
    for (int i = 0; i < (int)ss.size(); ++i) {
        if(ss[i] == 's') {
            ans += b[i + 1];
        }
    }
    cout << ans << "\n";
    return 0;
}

