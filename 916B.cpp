#include <bits/stdc++.h>

using namespace std;

int v[100];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long double n,k;
    cin >> n >> k;
    vector<int> ans;
    while(n and k) {
        bool found = 0;
        for (int i = -61; i <= 61; i++) {
            long double p = pow(2LL,i);
            if(k * p >= n) {
                found = 1;
                int d = n / p;
                if(!d) return cout << "No\n",0;
                int x = p * d;
                n -= x;
                k -= d;
                v[i + 50] += d;
                break;
            }
        }
        if(!found) return cout << "No\n",0;
    }
    cout << "Yes\n";
    for (int i = 100; i >= 0; --i){
        while(v[i]) {
            cout << i - 50 << " ";
            v[i]--;
        }
    }
    cout << "\n";
    return 0;
}
