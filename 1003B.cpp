#include <bits/stdc++.h>

using namespace std;

int a,b,x; 
int dp[110][110][210][4];

int f(int da, int db, int dx, int flag) {
    if(!da and !db) return dx == x;
    int &ans = dp[da][db][dx][flag];
    if(ans != -1) return ans;
    ans = 0;
    if(da) ans |= f(da - 1, db, dx + (flag != 0 and flag != 2), 0);
    if(db) ans |= f(da, db - 1, dx + (flag != 1 and flag != 2), 1);
    return ans;
}

void r(int da, int db, int dx, int flag) {
    if(!da and !db) return;
    if(da and f(da - 1, db, dx + (flag != 0 and flag != 2), 0)) {
        cout << 0;
        r(da - 1, db, dx + (flag != 0 and flag != 2), 0);
        return;
    }
    if(db and f(da, db - 1, dx + (flag != 1 and flag != 2), 1)) {
        cout << 1;
        r(da, db - 1, dx + (flag != 1 and flag != 2), 1);
        return;
    }
}
int main(){
    memset(dp, -1, sizeof dp);
    cin >> a >> b >> x;
    f(a,b,0,2);
    r(a,b,0,2);
    cout << "\n";
    return 0;
}

