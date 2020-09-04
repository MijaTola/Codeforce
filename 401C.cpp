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

int main(){
    int n,m; cin >> n >> m;

    if(n-1 > m or m > 2*(n+1)) return cout << -1,0;
    
    if(n == m+1){
        for (int i = 0; i < n+m; ++i)
            cout << i%2;
    }else{

        while(m-2 >= n and m and n){
            cout << 1;
            m--;
            if(m > 0) cout << 1; m--;
            if(n > 0) cout << 0; n--;
        }
        if(n > m and n and m){
            for (int i = 0; i < m+n; ++i)
                cout << i%2;
        }else if(m >= n and n and m){
            for (int i = 1; i <= n+m; ++i)
                cout << i%2;
        }else if(m <= 2) for (int i = 0; i < m; ++i) cout << "1";
        else cout << "-1";
    }
    return 0;
}

