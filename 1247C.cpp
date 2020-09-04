#include <bits/stdc++.h>

using namespace std;

long long A[1000000]; 

int main() {
    long long n,x;
    cin >> n >> x;

    auto f = [] (long long n, int k) {
        auto sum = k;
        fill(A, A + k, 1);
        for (int i = k - 1; i >= 0; --i) { 
            while (sum + A[i] <= n) { 
                sum += A[i]; 
                A[i] *= 2LL; 
            } 
        } 
        return sum == n;
    };

    for (int i = 0; i < 10000; ++i) {
        long long b = n - x * i;
        if(f(b,i)) return cout << i << "\n",0;
    }

    cout << "-1\n";
    return 0;
}

