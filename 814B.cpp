#include <bits/stdc++.h>

using namespace std;

int n;
int a[1010];
int b[1010];
bool vis[1010];
vector<int> v;
int main(){
    
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
        scanf("%d",a + i);   
    
    for (int i = 0; i < n; ++i)
        scanf("%d",b + i);   
    
    memset(vis,false,sizeof vis);
    for (int i = 0; i < n; ++i){
        if(a[i] != b[i]){v.push_back(i); continue;}
        vis[a[i]] = true;
    }
    
    if(v.size() == 1){
        for (int i = 0; i <= n; ++i)
            if(!vis[i]) a[v[0]] = i;
        for (int i = 0; i < n; ++i)
            printf("%d ",a[i]);
        return 0;
    }

    int c1 = b[v[0]];
    int c2 = a[v[1]];
    if(!vis[c1] and !vis[c2]){
        a[v[0]] = c1;
        a[v[1]] = c2;
        for (int i = 0; i < n; ++i)
            printf("%d ",a[i]);
        return 0;
    }else{
        a[v[0]] = a[v[0]];
        a[v[1]] = b[v[1]];
        for (int i = 0; i < n; ++i)
            printf("%d ",a[i]);
        return 0;
    }
    return 0;
}

