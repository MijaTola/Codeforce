#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,x,y;
        cin >> n >> x >> y;
        int s = x + y;

        int val = n + 1;
        
        int a = -1, b = -1;

        if(s >= val) b = n, a = 2;
        if(s < val) a = 1, b = (n + 1) / 2;

        cout << a << " " << b<< "\n";
    }

   
    

    return 0;
}

