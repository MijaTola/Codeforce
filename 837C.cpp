#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int n,a,b;

int solve(int n, int m, int x, int y){
    if(n*m > a*b or x*y > a*b) return -1;
    
    //first way
  
    
}
int main(){
    cin >> n >> a >> b;
    
    for (int i = 0; i < n; ++i){
        int x,y; cin >> x >> y;
        v.push_back(x * y);
    }

    int ans = 0;    
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            int cur = v[i] + v[j];
            if(cur > a * b) continue;
            ans = max(ans,cur);
        }
    }
    cout << ans << "\n";
    return 0;
}

