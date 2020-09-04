#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool ver(int u) {
    int ans = 0;
    while(u > 0) {
        ans += u % 10;
        u /= 10;
    }
    return ans == 10;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 15000000; ++i) 
        if(ver(i)) v.push_back(i);
    int x; cin >> x;
    cout << v[x - 1] << "\n";
    return 0;
}

