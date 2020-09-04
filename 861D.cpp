#include <bits/stdc++.h>

using namespace std;

map<string,pair<int,int> > mp;
string ans[70010];
int main(){
    int n;
    cin >> n;

    for (int l = 0; l < n; ++l){
        string s; 
        cin >> s;
        set<string> st;
        for (int i = 0; i < (int)s.size(); ++i){
            for (int j = i; j < (int)s.size(); ++j){
                string cur = "";
                for (int k = i; k <= j; ++k){
                    cur += s[k];
                }
                if(st.count(cur)) continue;
                st.insert(cur);
                mp[cur].first++;
                mp[cur].second = l;
            }
        }
    }

    for (pair<string,pair<int,int> > p: mp){
        if(p.second.first == 1){
            if((int)ans[p.second.second].size() == 0  or (int)ans[p.second.second].size() > (int)p.first.size()){
                ans[p.second.second] = p.first;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
    return 0;
}

