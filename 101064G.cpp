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

typedef long long ll;

const ll maxn = 1000000000000LL;
int head[100010];
int parent[100010];
ll value[100010];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 100010; ++i) value[i] = maxn;
    int q; cin >> q;
    head[0] = 0;
    parent[0] = 0;
    int pos = 0;
    while(q--){
        pos++;
        char c; cin >> c;
        if(c == 'E'){
            int x,y; cin >> x >> y;
            if(value[x] == maxn){
                head[pos] = pos;
                parent[pos] = pos;
                value[pos] = y;
            }else{
                head[pos] = head[x];
                parent[pos] = x;
              value[pos] = y;
            }
            /*cout << "X: "<<x << " " << head[x] << " " << parent[x] << endl;
            cout << "L: "<<pos << " " << head[pos] << " " << parent[pos] << endl;*/
        }else{
            int x; cin >> x;
            cout << value[head[x]] << "\n";
            head[pos] = head[x];
            parent[pos] = x;
            int v = pos;
            int last = 0;
            while(v != parent[v] and head[x] != v){
                last = v;
                v = parent[v];
            }
            head[pos] = last;
            if(head[pos] == pos) value[pos] = maxn;
            /*cout << "X: "<< x << " " << head[x] << " " << parent[x] << endl;
            cout << "L: "<<pos << " " << head[pos] << " " << parent[pos] << endl;*/
        }
    }
    return 0;
}

