#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[2010];
int b[2010];
map<int,int> mp;
int main(){
    
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    
    for (int i = 0; i < k; ++i) {
        scanf("%d", b + i);
        mp[b[i]]++;
    }

    set<int> ans;
    for (int i = 0; i < n; ++i) {
        map<int,int> vis;
        int cur = b[0];
        
        cur = b[0];
        for (int j = i; j >= 0; j--) 
            cur -= a[j];
        int ini = cur;
        for (int j = 0; j < n; ++j) {
            vis[cur += a[j]]++;
        }
        bool flag = 1;
        for (auto p: mp) 
            flag &= mp[p.first] <= vis[p.first];
        if(flag) ans.insert(ini);
    }
    printf("%d\n", (int)ans.size());
    return 0;
}

