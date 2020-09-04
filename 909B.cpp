#include <bits/stdc++.h>

using namespace std;

int n;
int v[110];
int main(){
    
    scanf("%d",&n);
    
    set<pair<int,int> > s;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            s.insert({i,j});
        }
    }
    
    int ans = 0;
    while(s.size() >= 1) {
        auto s1 = *s.begin();
        int a = s1.first;
        int b = s1.second;
        s.erase({a,b});
        s.erase({b,n - a});
        ans++;
    }

    if((int)s.size()) ans++;
    printf("%d\n", ans);
    return 0;
}

