#include <bits/stdc++.h>

using namespace std;


int main(){
    
    int n;
    cin >> n;
    
    int ans = 1;
    int c = 0;
    while(ans <= n)  {
        ans *= 2;
        c++;
    }
    cout << c << "\n";
    return 0;
}

