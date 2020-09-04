#include <bits/stdc++.h>

using namespace std;


int main(){

    long long a,b,m,n,x,y;
    cin >> a >> b >> m >> n >> x >> y;
    
    bool flag = 0;
    if(a - m - x >= 0 and b - n - y >= 0) flag = 1;
    if(a - n - x >= 0 and b - m - y >= 0) flag = 1;
    if(a - m - y >= 0 and b - n - x >= 0) flag = 1;

    if(flag and a * b > m * n + x * y) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
