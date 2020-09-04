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

int parent[1010];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void init(){
    for (int i = 0; i < 1010; ++i) parent[i] = i;
}
void Union(int x,int y){
    int dx = find(x);
    int dy = find(y);
    parent[dx] = dy;
}
vector<pair<int,int> > v;
set<int> s;
int main(){
    int n; scanf("%d",&n);
    int total = 0;
    for (int i = 0; i < n; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(x,y));
    }
    init();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if(v[i].first == v[j].first or v[i].second == v[j].second)
                Union(i,j);

    for (int i = 0; i < n; ++i)
        s.insert(find(i));

    printf("%d\n",(int)s.size() - 1);
    return 0;
}

