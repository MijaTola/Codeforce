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
    string x; cin >> x;
    string ans = "";
    string address = "";
    bool flag  = false;
    bool first = true;
    for (int i = 0; i < (int)x.size(); ++i){
        if(x[i] == '@' and !flag) {
            //cout << i << " " << x[i] << " adsf" << endl;
            flag= true;
            if((int)address.size() == 0) return cout << "No solution" << endl,0;
            continue;
        }
        if(flag){
            if(x[i] == '@')return cout<< "No solution" << endl,0;
            if(!first) ans += ",";
            first = false;
            ans += address;
            ans += "@";
            ans += x[i];
            flag = false;
            address = "";
            continue;
        }
        address += x[i];
    }
    if(flag or first) return cout << "No solution" << endl,0;
    ans += address;
    cout << ans << endl;
    return 0;
}

