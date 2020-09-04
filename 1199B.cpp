#include <bits/stdc++.h>

using namespace std;

double h,l;
int main() {
    cin >> h >> l;
    cout.precision(10);
    cout << fixed << (l * l + h * h) / (2 * h) - h << "\n";
    return 0;
}

