#include <bits/stdc++.h>

using namespace std;

int n,m;

int c[110][110];
int c1[110][110];
vector<pair<char,pair<int,int> > > v;
vector<pair<char,int >> ans;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    
    for (int i = 0; i < n; ++i){
        int mn = 1e9;
        for (int j = 0; j < m; ++j){
            mn = min(mn,c[i][j] - c1[i][j]);
            if(mn < 0) return cout << "-1\n",0;
        }
        v.push_back(make_pair('r',make_pair(i,mn)));
        for (int j = 0; j < m; ++j)
            c1[i][j] += mn;
    }

    for (int i = 0; i < m; ++i){
        int mn = 1e9;
        for (int j = 0; j < n; ++j){
            mn = min(mn,c[j][i] - c1[j][i]);
            if(mn < 0) return  cout <<"-1\n",0;
        }
        v.push_back(make_pair('c',make_pair(i,mn)));
        for (int j = 0; j < n; ++j)
            c1[j][i] += mn;
    }

    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if(c[i][j] != c1[i][j]) return cout << "-1\n",0;

    for (int i = 0; i < (int)v.size(); ++i){
        char c = v[i].first;
        int p = v[i].second.first;
        int j = v[i].second.second;
        while(j--){
            ans.push_back(make_pair(c,p));
        }
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < (int)ans.size(); ++i){
        if(ans[i].first == 'r') cout << "row ";
        else cout << "col ";
        cout << ans[i].second + 1<< "\n";
    }
    return 0;
}

