#include <bits/stdc++.h>

using namespace std;

int a[100010];
int b[100010];

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];
    
    bool flag = 0;
    for (int i = x - 1; i < n; ++i) {
        int pos = upper_bound(b, b + m, a[i]) - b;
        int sz = (m - pos) - y;
        flag |= (sz >= 0);
    }
	
    puts(flag ? "YES": "NO"); 
	return 0;
}
