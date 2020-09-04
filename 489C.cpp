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

bool f(int m, int s){
    return s >= 0 and s <= 9* m;
}
int main(){
    int m,s;
    cin >> m >> s;
    int sum = s;
    string mn = "";
    if(!m and !s) return cout << "0 0" << endl,0;
    if((m > 1 and s == 0) or (m == 0 and s > 0)) return cout << "-1 -1" << endl,0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < 10; ++j)
            if((i > 0 or j > 0 or (m == 1 and j == 0)) and f(m-i-1, sum - j)){
                mn += char(j +'0');
                sum -= j;
                break;
            }
    sum = s;
    string mx  = "";
    for (int i = 0; i < m; ++i)
        for (int j = 9; j >= 0; --j)
            if((i > 0 or j > 0 or (m == 1 and j == 0)) and f(m-i-1, sum - j)){
                 mx += char(j +'0');
                 sum -= j;
                 break;
            }
    if(mn == "" or mx == "") cout << "-1 -1" << endl;
    else cout << mn << " " << mx << endl;
    return 0;
}

