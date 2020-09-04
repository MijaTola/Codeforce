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

using namespace std;

typedef long long ll;

int main(){
    int a,b,n; cin >> a >> b >> n;
    a *= 10;
    bool flag = false;
    for (int i = 0; i < 10; ++i){
        //cout << a+i << endl;
        if((a+i)%b == 0) {
            flag =  true;
            a += i;
            break;
        }
    }
    if(!flag) return cout << -1 << endl,0;

    cout << a;
    for (int i = 0; i < n-1; ++i) cout << 0;
    cout << endl;
    return 0;
}

