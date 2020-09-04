#include <bits/stdc++.h>

using namespace std;

int v[2010], b[2010];
bool a[20000010];
int main(){
    memset(a,false,sizeof a);
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
        scanf("%d",v + i), a[v[i]] = 1;
    for (int i = 0; i < n; ++i)
        scanf("%d",b + i), a[b[i]] = 1;;

    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if(a[b[j] ^ v[i]]) ans++;
        }
    }
    if(ans % 2 != 0) puts("Koyomi");
    else puts("Karen");
    return 0;
    
}

