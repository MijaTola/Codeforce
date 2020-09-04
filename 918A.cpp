#include <bits/stdc++.h>

using namespace std;

int v[1100];
int main(){
    
    int a = 1;
    int b = 0;
    int c = 0;
    while(a < 1000) {
        c = a + b;
        if(c <= 1000)
        v[c] = 1;
        a = b;
        b = c;
    }

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) 
        if(v[i]) cout << 'O';
        else cout << 'o';
    return 0;
}

