#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c;
    
    if(x > a) return cout << "NO\n",0;
    a -= x;
    int total = a + b;
    if(y > total) return  cout << "NO\n",0;
    total -= y;
    total += c;
    if(z > total) return cout << "NO\n",0;
    cout << "YES\n";
    return 0;
}

