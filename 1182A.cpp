#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n;
    cin >> n;
    if(n & 1LL) return cout << "0\n",0;
    
    cout << (1LL << (n >> 1)) << "\n";
    return 0;
}

