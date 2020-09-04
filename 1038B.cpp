#include <bits/stdc++.h>

using namespace std;

int n;

bool primes[45010];
vector<int> p;
void criba() {
    memset(primes, 0,sizeof primes);
    for (int i = 2; i * i < 45010; ++i) {
        int c = i + i;
        while(c < 45010) {
            primes[c] = 1;
            c += i;
        }
    }

    for (int i = 2; i <= 45000; ++i) {
        if(!primes[i]) p.push_back(i);
    }
}
int main(){
    criba();
    cin >> n;

    long long s = n * (n + 1) / 2;
    for (int i = 0; i < (int)p.size(); ++i) 
        if(s % p[i] == 0 and p[i] <= n) {
            cout << "Yes\n";
            cout << 1 << " " << p[i] << "\n";
            cout << n - 1 << " ";
            for (int j = 1; j <= n; ++j) {
                if(j == p[i]) continue;  
                cout << j << " ";
            }
            cout << "\n";
            return 0;
        } 
    cout << "No\n";
    return 0;
}

