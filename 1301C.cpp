#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    auto get = [](long long x) -> long long{
        return (x * (x + 1)) / 2ll;
    };
    while(t--) {
        long long n,m;
        cin >> n >> m;
       
        if(m == 0) {
            cout << "0\n";
            continue;
        }

        long long zeros = n - m;
        long long groups = m + 1;

        long long k = zeros / groups;

        cout << get(n) - get(k) * groups - (k + 1) * (zeros % groups) << "\n";


    }   
    return 0;
}

