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

int m[1010][1010];
int main(){
    
    int n,k,d;
    cin >> n >> k >> d;
    bool flag = false;
    long long cur = k;
    for (int i = 0; i < d; ++i){
        if(cur >= n){flag = true; break;}
        cur *= k;
    }
    if(!flag) return cout << -1 << "\n",0;
    
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < d; ++j) m[i][j] = m[i-1][j];
        for (int j = d-1; j >= 0; --j){
            m[i][j] = (m[i][j]+1)%k;
            if(m[i][j]) break;
        }
    }
    for (int i = 0; i < d; ++i){
        for (int j = 0; j < n; ++j)
            cout << m[j][i]+1 << " ";
        cout << "\n";
    }
    return 0;
}

