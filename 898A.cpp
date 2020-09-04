#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int x = (n / 10) * 10;
    int y = x + 10;

    if(abs(n - x) < abs(n - y)) cout << x;
    else cout << y;
    return 0;
}

