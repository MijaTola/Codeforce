#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a,b,c;
    cin >> a >> b >> c;
    
    if(a != b) 
        cout << 2 * c + 2 * min(a,b) + 1 << "\n";
    else 
        cout << 2 * c + 2 * b<< "\n";
    return 0;
}

