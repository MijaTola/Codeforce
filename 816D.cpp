#include <bits/stdc++.h>

using namespace std;

vector<int> v[2000100];
const int mod = 1e9 + 7;
int main(){
       
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        v[0].push_back(x);
    }
    int cur = 0;
    bool flag = true;
    while((int)v[cur].size() > 1){
        for (int i = 0; i < (int)v[cur].size() - 1; ++i){
            if(flag) v[cur + 1].push_back(  (mod + v[cur][i] + v[cur][i + 1]) % mod);
            else v[cur+1].push_back((mod +v[cur][i] - v[cur][i + 1])%mod);
            flag = !flag;
        }
        cur++;
    }
    cout << v[cur][0] << "\n";
    return 0;
}

