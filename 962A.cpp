#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main(){
    
    int n; cin >> n;
    int a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        a += v[i];
    }

    double mid = a / 2;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        b+= v[i];
        if(2 * b >= a) return cout << i  + 1 << "\n",0;
    }
    return 0;
}

