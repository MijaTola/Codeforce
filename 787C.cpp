#include <bits/stdc++.h>

using namespace std;

int n,da,db;
int v[7010];
int dp1[7010];
int dp2[7010];

int main() {

    cin >> n >> da >> db;

    vector<int> a(da), b(db);
    
    for (auto &x: a)
        cin >> x;

    for (auto &x: b)
        cin >> x;
    

    for (int x: a) 
        dp1[n - x] = dp1[2 * n - x] = 1;
    
    for (int x: b) 
        dp2[n - x] = dp2[2 * n - x] = 0;
   

    
    return 0;
}
