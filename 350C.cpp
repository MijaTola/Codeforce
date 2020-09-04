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

pair<int,int> v[100010];

int manhattan(int x, int y){
    return abs(x)+abs(y);
}
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return manhattan(a.first, a.second) < manhattan(b.first,b.second);
}
int main(){
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        cin >> v[i].first >> v[i].second;
        if(v[i].first == 0 or v[i].second == 0) ans += 4;
        else ans += 6;
    }

    sort(v,v+n,cmp);

    cout << ans << "\n";
    for (int i = 0; i < n; ++i){
        if(v[i].first == 0 or v[i].second == 0){
            if(v[i].first == 0){
             
                if(v[i].second > 0)cout << 1 << " " << abs(v[i].second) << " U\n";
                else cout << 1 << " " << abs(v[i].second) << " D\n";
                
                cout << 2 << "\n";
                
                if(v[i].second > 0)cout << 1 << " " << abs(v[i].second) << " D\n";
                else cout << 1 << " " << abs(v[i].second) << " U\n";
            
            }else{
            
                if(v[i].first > 0) cout << 1 << " " << abs(v[i].first) << " R\n";
                else cout << 1 << " " << abs(v[i].first) << " L\n";
                
                cout << 2 << "\n";
                
                if(v[i].first > 0) cout << 1 << " " << abs(v[i].first) << " L\n";
                else cout << 1 << " " << abs(v[i].first) << " R\n";
            }
                cout << "3\n";
        }else{
            
            if(v[i].first > 0) cout << 1 << " " << abs(v[i].first) << " R\n";
            else cout << 1 << " " << abs(v[i].first) << " L\n";
            
            if(v[i].second > 0) cout << 1 << " "<< abs(v[i].second) << " U\n";
            else cout << 1 << " " << abs(v[i].second) << " D\n";
            
            cout << 2 << "\n";

            if(v[i].first > 0) cout << 1 << " " << abs(v[i].first) <<" L\n";
            else cout << 1 << " " << abs(v[i].first) << " R\n";

            if(v[i].second > 0) cout << 1 << " " << abs(v[i].second) << " D\n";
            else cout << 1 << " " << abs(v[i].second) << " U\n";
            
            cout << 3 << "\n";
        }
    }
    return 0;
}

