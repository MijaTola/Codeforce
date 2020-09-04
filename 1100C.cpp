#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);
double n,r;
int main() {
    cin >> n >> r;

    double a = 0.0;
    double b = 1000;
    double angle = 2 * pi / n;

    for (int i = 0; i < 1000; ++i) {
        double mid = (a + b) / 2;
        double R = mid + r;
        double chord = 2 * R * sin(angle / 2);
        double dis = R - (chord / 2);
        if(dis >= r) b = mid;
        else a = mid;
    }

    cout.precision(10);
    cout << fixed << b << "\n";
    return 0;
}

