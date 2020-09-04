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

int v[2010][2010];
long long p1[2010*2];
long long p2[2010*2];
long long f[2] = {-1,-1};
long long x[2],y[2];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            cin >> v[i][j];
            p1[i+j] += v[i][j];
            p2[i-j+n] += v[i][j];
        }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            long long d = p1[i+j]+p2[i-j+n]-v[i][j];
            int t = (i+j)&1;
            if(f[t] < d){
                f[t] = d; 
                y[t] = i + 1;
                x[t] = j + 1;
            }
        }
    cout << f[0]+f[1] << "\n";
    cout << y[0] << " " << x[0] << " " << y[1] << " " << x[1] <<"\n";
    return 0;
}
