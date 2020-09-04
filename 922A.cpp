#include <bits/stdc++.h>

using namespace std;

int main(){
    // c o   
    int x,y;
    cin >> x >> y;
    
    if(y == 0) return cout << "No\n",0;
    if(y == 1) {
        if(x == 0) cout << "Yes\n";
        else cout << "No\n";
        return 0;
    }
    int dif = x - y + 1;
    if(dif >= 0 and dif % 2 == 0) return cout << "Yes\n",0;
    
    cout << "No\n";
    return 0;
}

