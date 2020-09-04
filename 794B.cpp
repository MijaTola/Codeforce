
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,h;
    cin >> n >> h;
    cout.precision(15);
    
    for (int i = 1; i < n; ++i)
        cout<< fixed << sqrt((long double)i/n)*h << " ";
    return 0;
}


