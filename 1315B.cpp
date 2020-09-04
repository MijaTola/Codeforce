#include <bits/stdc++.h>

using namespace std;

int a,b,p;
string s;


bool ver(int k) {
    int last = '$';
    long long cost = 0;
    for (int i = k; i < (int)s.size() - 1; ++i) {
        if(last != s[i]) {
            cost += (s[i] == 'A' ? a : b);
        }
        last = s[i];
    }
    return cost <= p;
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> a >> b >> p >> s;

        int a = -1, b = s.size();

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) b = mid;
            else a = mid;
        }
        cout << b + 1 << "\n";

    }
    return 0;
}

