#include <bits/stdc++.h>

using namespace std;

long double x[3];
long double y[3];
int main() {
    
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> y[i];
    
    auto dis = [&] (int i, int j) -> long double {
        return sqrt(1. * (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    };
    
    if(dis(0,1) == dis(1,2) and dis(0,1) + dis(1,2) > dis(0, 2)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

