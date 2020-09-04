#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n,m;
    long long a,b;
    cin >> n >> m >> a >> b;
    
    if(n % m == 0) return cout << "0\n",0;

    long long dif = (n / m) * m;

    cout << min(b * (n - dif), a * (dif + m - n)) <<"\n";
    return 0;
}

