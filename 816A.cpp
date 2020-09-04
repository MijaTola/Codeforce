#include <bits/stdc++.h>

using namespace std;

bool ver(int x, int y) {
    string a = "";
    string b = "";
    a = to_string(x);
    b = to_string(y);
    if(a.size() < 2) a = "0" + a;
    if(b.size() < 2) b = "0" + b;
    string c = a + b;
    string d = a + b;
    reverse(c.begin(), c.end());
    return c == d;
}
int main() {
    int h,m;
    scanf("%d:%d", &h, &m);
    
    int ans = 0;
    while(true) {
        if(ver(h,m)) 
            return cout << ans << "\n",0;
        m++;
        if(m == 60) h = (h + 1) % 24, m = 0;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
