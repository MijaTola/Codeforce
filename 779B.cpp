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

queue<pair<string,int> > q;
set<string> vis;

long long f(string x){
    long long ans = 0;
    for (int i = 0; i < (int)x.size(); i++){
        ans += (int)(x[i]-'0');
        ans *= 10ll;
    }
    return ans/10ll;
}
int main(){
    int k;
    string n;
    cin >> n >> k;
    
    q.push(make_pair(n,0));
    long long p = 1;
    for (int i = 0; i < k; ++i) 
        p *= 10ll;
    
    while(!q.empty()){
        string u = q.front().first;
        int c = q.front().second;
        long long  num = f(u);
        q.pop();
        if(num == 0 and u.size() == 1) return cout << c << "\n",0;
        else if(num%p == 0 and num != 0) return cout << c << "\n",0;
        if(vis.count(u)) continue;
        vis.insert(u);
        for (int i = 1; i <= (int)u.size(); ++i){
            string a = u.substr(0,i-1);
            string b = u.substr(i,(int)u.size());
            q.push(make_pair(a+b,c+1));
        }
    }
    cout << "0\n";
    return 0;
}

