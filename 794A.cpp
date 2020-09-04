#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,n;
    scanf("%d %d %d %d",&a,&b,&c,&n);    
    
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int x; scanf("%d",&x);
        if(a > b and a < c and x > b and x < c) ans++;   
    }
    printf("%d\n",ans);
    return 0;
}

