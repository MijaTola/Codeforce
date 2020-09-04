#include <bits/stdc++.h>

using namespace std;

int main(){
        
    long long a,b,x,y,z;
    cin >> a >> b >> x >> y >> z;
    cout << max(0ll, 2 * x + y - a) + max(0ll, 3 * z + y - b) << "\n";
    return 0;
}

