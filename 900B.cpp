#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int main() {
    long long a, b;
    int c;
    cin >> a >> b >> c;
    for (int i = 1; i < 100000; ++i) {
        a *= 10;
        if(a / b == c) return cout << i << "\n",0;
        a %= b;
    }
    cout << "-1\n";
    return 0;
}

//1 2 5 3 4 6
