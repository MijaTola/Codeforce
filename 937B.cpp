#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int y,p;
    cin >> p >> y;
    if(p == y) return cout << "-1\n",0;
    int l = min(p, (int)sqrt(y) + 1);
    
    for (int i = y; i >= p; i--) {
        bool f = 0;
        for (int j = 2; j <= l; ++j) 
            f |= (i % j == 0);
        if(!f) return cout << i << "\n",0;
    }
    cout << "-1\n";
    return 0;
}

