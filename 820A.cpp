#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int c,v0,v1,a,l;
    scanf("%d %d %d %d %d",&c,&v0,&v1,&a,&l);
    int cur = v0;
    int ans = 1;

    for (int i = 1; cur < c; ++i){
        int t = min(v1,v0 + i * a) - l;
        cur +=  t;
        ans++;
    }

    printf("%d\n",ans);
}

