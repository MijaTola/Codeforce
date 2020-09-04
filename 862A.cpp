#include <bits/stdc++.h>

using namespace std;

bool v[110];
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    
    for (int i = 0; i < n; ++i){
        int k;
        scanf("%d", &k);
        v[k] = 1;
    }
    int ans = 0;
    if(v[x]) ans++;
    for (int i = 0; i < x; ++i){
        if(!v[i]) ans++;
    }
    
    printf("%d\n", ans);
    return 0;
}

