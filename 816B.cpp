#include <bits/stdc++.h>

using namespace std;

int v[2000010];
int main(){
    
    int n,k,q;
    scanf("%d %d %d",&n,&k,&q);

    for (int i = 0; i < n; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x]++;
        v[y + 1]--;
    }

    for (int i = 0; i < 2000000; ++i)
        v[i] += v[i - 1];
    
    for (int i = 0; i < 2000000; ++i){
        v[i] = (v[i] >= k);
        v[i] += v[i-1];
    }
    
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",(v[y] - v[x - 1]));
    }
    return 0;
}
