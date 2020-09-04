#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a,b,a1,b1, a2,b2;
    cin >> a >> b >> a1 >> b1 >> a2 >> b2;
    
    if(b1 < a1) swap(a1, b1);
    if(b2 < a2) swap(a2, b2);
    
    if(a1 + a2 <= a and max(b1, b2) <= b) return cout << "YES\n",0;
    if(a1 + b2 <= a and max(b1, a2) <= b) return cout << "YES\n",0;
    if(b2 + b2 <= a and max(a1, a2) <= b) return cout << "YES\n",0;
    if(b1 + a2 <= a and max(a1, b2) <= b) return cout << "YES\n",0;
    if(a1 + a2 <= b and max(b1, b2) <= a) return cout << "YES\n",0;
    if(a1 + b2 <= b and max(b1, a2) <= a) return cout << "YES\n",0;
    if(b2 + b2 <= b and max(a1, a2) <= a) return cout << "YES\n",0;
    if(b1 + a2 <= b and max(a1, b2) <= a) return cout << "YES\n",0;
    cout << "NO\n";
    return 0;
}

