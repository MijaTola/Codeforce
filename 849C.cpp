#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    if(n == 0) {
        return cout << "abc\n", 0;
    }
    int dis = 26;
    
    vector<int> v;

    while(n > dis) {
        long long a = 0, b = n;
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(mid * (mid + 1) / 2 <= n) a = mid;
            else b = mid;
        }
        v.push_back(a + 1);
        n -= a * (a + 1) / 2;
        dis--;
    }

    while(n--) 
        v.push_back(2);

    for (int i = 0; i < (int)v.size(); ++i) {
        while(v[i]--) cout << (char)(i + 'a');
    }
    
    cout << "\n";

    return 0;
}

