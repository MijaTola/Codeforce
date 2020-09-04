#include <bits/stdc++.h>

using namespace std;

vector<int> da;
vector<int> db;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int ans = 0;
    int da = a;
    int db = b;
    int cur = 0;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x == 1){
            if(da) da--;
            else if(db) db--, cur++;
            else if(cur) cur--;
            else ans++;
        }else{
            if(db) db--;
            else ans += 2;
        }
    }
    cout << ans << "\n";
    return 0;
}

