#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long u,v;
    cin >> u >> v;

    if(u % 2 != v % 2 or u > v) return cout << "-1\n", 0;
    
    if(u == 0 and v == 0) {
        cout << "0\n";
        return 0;
    }
    if(u == v) {
        cout << "1\n" << u << "\n";
        return 0;
    }
    
    
    long long a2 = (v - u) / 2;

    if(((u + a2) ^ a2) == u) {
        cout << "2\n" << u  + a2 << " " << a2 << "\n";
    } else 
        cout << "3\n" << u << " " << a2 << " " << a2 << "\n";

    return 0;
}

