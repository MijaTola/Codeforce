#include <bits/stdc++.h>

using namespace std;

int a[27];
int g[26];
int main(){
    memset(g,-1,sizeof g);
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
    
    for (int i = 0; i < (int)s.size(); ++i)
        a[s[i] - 'A']++;
    
    for (int i = 0; i < (int)s.size(); ++i){
        bool flag = false;
        int val = s[i] - 'A';
        for (int j = 0; j < k; ++j){
            if(g[j] == val){
                g[j] = val;
                flag = true;
                a[val]--;
                if(!a[val]) g[j] = -1;
                break;
            }
        }
        if(flag) continue;
        for (int j = 0; j < k; ++j){
            if(g[j] == -1){
                flag = true;
                g[j] = val;
                a[val]--;
                if(!a[val]) g[j] = -1;
                break;
            }
        }
        if(!flag) return puts("YES"),0;
    }
    puts("NO");
    return 0;
}

