#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,m;
    cin >> n >> m;
    
    if(n > 63) cout << m;
    else cout << m % (long long) pow(2,n);
    return 0;
}

