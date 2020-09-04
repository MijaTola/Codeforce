#include <bits/stdc++.h>

using namespace std;

pair<int,int> v[100010];
int a[100010];
int b[100010];
int main(){
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i){
        scanf("%d",&v[i].first);
        v[i].second = i + 1;
    }

    sort(v,v+n);
    
    int da = 0;
    int db = 0;
    for (int i = 0; i < n; ++i){
        if(i & 1) b[db++] = v[i].second;
        else a[da++] = v[i].second;
    }
    
    printf("%d\n",da);
    
    for (int i = 0; i < da; ++i)
        printf("%d ",a[i]);
    
    puts("");
    printf("%d\n",db);
    for (int i = 0; i < db; ++i)
        printf("%d ",b[i]);

    puts("");
    return 0;
}

