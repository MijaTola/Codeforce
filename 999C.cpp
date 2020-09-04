#include <bits/stdc++.h>

using namespace std;

vector<int> v[27];
char c[400010];

int main(){
    memset(c,0,sizeof c);
    int n,k; cin >> n >> k;
    string s; cin >> s;
    
    for (int i = 0; i < (int)s.size(); ++i) 
        v[s[i] - 'a'].push_back(i);
    

    for (int i = 0; i < 27 and k; ++i) {
        for (int j = 0; j < (int)v[i].size() and k; ++j) {
            s[v[i][j]] = '!';
            k--;
        }
    }

    for (int i = 0; i < n; ++i) {
        if(s[i] != '!') cout << s[i];
    }
    cout << "\n";
    return 0;

}

