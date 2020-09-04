#include <bits/stdc++.h>

using namespace std;

int v[100010];
int b[100010];
int c[100010];
int c1[100010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    for (int i = 0; i < n; ++i)
        scanf("%d",v + i);

    for (int i = 1; i < n; ++i){
        int cur = i - 1;
        if(v[cur] <= v[i]) b[i] = b[cur];
        else b[i] = i;
    }
    
    c[n-1] = n - 1;
    for (int i = n - 2; i >= 0; --i){
        int cur = i + 1;
        if(v[cur] <= v[i]) c[i] = c[cur];
        else c[i] = i;
        
        if(v[cur] >= v[i]) c1[i] = c1[cur];
        else c1[i] = i;
    }

    while(m--){
        int l,r;
        scanf("%d %d",&l,&r);
        l--,r--;
        int x = c1[l];
        int left = b[x];
        int right = c[x];
        bool flag = false;
        if(left <= l and r <= right) flag = true;
        right = c[l];
        left = b[r];
        if(r <= right or left <= l) flag = true;
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}

