#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int ans = 0;
    
    int c = n / 100;
    n %= 100;
    c += n / 20;
    n %= 20;
    c += n / 10;
    n %= 10;
    c += n / 5;
    n %= 5;
    c += n;
    cout << c << "\n";
    return 0;
}

