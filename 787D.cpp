#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;


int st[4*1000100];
int st1[4*1000100];
long long dis[4*1000100];
vector<pair<int,int> >G[4*1000100];
int n,q,s,cur,w;

void build(int node, int l, int r){
    st[node] = ++cur;
    st1[node] = ++cur;
    if(l == r){
        G[l].push_back(make_pair(st[node],0));
        G[st1[node]].push_back(make_pair(l,0));
        return;
    }
    int mid = (r+l)>>1;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    G[st[2*node]].push_back(make_pair(st[node],0));
    G[st[2*node+1]].push_back(make_pair(st[node],0));
    G[st1[node]].push_back(make_pair(st1[2*node],0));
    G[st1[node]].push_back(make_pair(st1[2*node+1],0));
}


void insert(int node, int l, int r, int i, int j){
    if(i > r or j < l) return;
    if(l >= i and r <= j){
        G[st[node]].push_back(make_pair(cur,w)); return;
    }
    int mid = (l+r)>>1;
    insert(2*node,l,mid,i,j);
    insert(2*node+1,mid+1,r,i,j);
}
void insert2(int node,int l, int r, int i, int j){
    if(i > r or j < l) return;
    if(l >= i and r <= j){ 
        G[cur].push_back(make_pair(st1[node],0)); return;
    }
    int mid = (l+r)>>1;
    insert2(2*node,l,mid,i,j);
    insert2(2*node+1,mid+1,r,i,j);
}

void print(){
    for (int i = 1; i <= cur; ++i){
        cout << i << ": ";
        for (int j = 0; j < (int)G[i].size(); ++j){
            cout << G[i][j].first << " ";
        }
        cout << "\n";
    }
}
int main(){
    for (int i = 0; i < 4*1000100; ++i) dis[i] = LLONG_MAX;
    cin >> n >> q >> s;
    cur = n;
    build(1,1,n);
    while(q--){
        cur++;
        int c,v,u,l,r;
        cin >> c;
        if(c == 1){
            cin >> v >> u >> w;
            insert(1,1,n,v,v);
            insert2(1,1,n,u,u);
        }
        if(c == 2){
            cin >> v >> l >> r >> w;
            insert(1,1,n,v,v);
            insert2(1,1,n,l,r);
        }
        if(c == 3){
            cin >> v >> l >> r >> w;
            insert2(1,1,n,v,v);
            insert(1,1,n,l,r);
        }
    }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > qq;
    qq.push(make_pair(0,s));
    dis[s] = 0;
    
    while(!qq.empty()){
        int u = qq.top().second;
        qq.pop();
        for (int i = 0; i < (int)G[u].size(); ++i){
            int v = G[u][i].first;
            int cost = G[u][i].second;
            if(dis[u]+cost < dis[v]){
                dis[v] = dis[u]+cost;
                qq.push(make_pair(dis[v],v));
            }
        }
    }


    for (int i = 1; i <= n; ++i)
        if(dis[i] != LLONG_MAX) cout << dis[i] << " ";
        else cout << "-1 ";
    return 0;
}

