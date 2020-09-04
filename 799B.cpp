#include <bits/stdc++.h>

using namespace std;

int a[200500];
int b[200500];
int p[200500];
bool vis[200500];
priority_queue<pair<int,int> > q[3];

int main(){
    memset(vis,false,sizeof vis);    
    int n; 
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) scanf("%d",p+i);
    for (int i = 0; i < n; ++i) scanf("%d",a+i);
    for (int i = 0; i < n; ++i) scanf("%d",b+i);
    
    for (int i = 0; i < n; ++i){
        int da = a[i]-1;
        int db = b[i]-1;
        q[da].push(make_pair(-p[i],i));
        q[db].push(make_pair(-p[i],i));
    }
    int m;
    scanf("%d",&m);
    while(m--){
        int x;
        scanf("%d",&x);
        x--;
        if(q[x].empty()){printf("-1 "); continue; }
        while(vis[q[x].top().second] and !q[x].empty()) q[x].pop();
        if(q[x].empty()){printf("-1 "); continue; }
        vis[q[x].top().second] = true;
        printf("%d ",-q[x].top().first);
    }
    puts("");
    return 0;
}

