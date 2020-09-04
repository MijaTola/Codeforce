#include <bits/stdc++.h>

using namespace std;

int ds[27];
int dt[27];
int main(){
    
    int n; cin >> n;

    string s,t;
    cin >> s >> t;
    
    for (int i = 0; i < n; ++i) {
        ds[s[i] - 'a']++;
        dt[t[i] - 'a']++;
    }

    for (int i = 0; i < 27; ++i) 
        if(ds[i] != dt[i]) return cout << "-1\n",0;
    
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if(s[i] != t[i]) {
            int p = i;
            while(s[p] != t[i]) p++;
            while(p > i) {
                swap(s[p],s[p - 1]);
                ans.push_back(p - 1);
                p--;
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] + 1 << " ";
    cout << "\n";
    return 0;
}

