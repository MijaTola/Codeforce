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

using namespace std;

typedef long long ll;
char c[1010][1010];
int dx[1010];
int dy[1010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >>n >> m;
    int total = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            cin >> c[i][j];
            if(c[i][j] == '*'){ 
                total++;
                dx[i]++;
                dy[j]++;
            }
        }
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            int dif = dx[i] + dy[j];
            if(c[i][j] == '*'){
                dif--;
            }
            if(dif == total){
                cout << "YES" << "\n";
                cout << i+1 << " " << j+1;
                return 0;
            }
        }
    }
    cout << "NO" << "\n";
    return 0;
}

