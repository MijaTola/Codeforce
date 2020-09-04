#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string a,b,c;
        cin >> a >> b >> c;
        
        bool flag = 1;
        for (int i = 0; i < (int)a.size(); ++i) 
            flag &= (a[i] == c[i] or c[i] == b[i]);

        if(flag) puts("YES");
        else puts("NO");
        
    }
    return 0;
}

