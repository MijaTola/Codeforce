#include <bits/stdc++.h>

using namespace std;

int prime[1000100];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 2; i * i < 1000100; ++i) 
        for (int j = i + i; j < 1000100; j += i) 
            if(!prime[j])prime[j] = i;
        
    prime[0] = prime[1] = 1;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        bool flag = 0;
        for (int i = 2; i * i <= n; ++i) {
            if(n % i == 0 and i > 1) {
                if(prime[i]) {
                    int a = n / i;
                    int b = prime[i];
                    int c = i / prime[i];
                    set<int> s;
                    s.insert(a);
                    s.insert(b);
                    s.insert(c);
                    if((int)s.size() == 3) {
                        cout << "YES\n";
                        cout << a << " " << b << " " << c << "\n";
                        flag = 1;
                        break;
                    }
                } else if(n / i < 1000000 and prime[n / i]) {
                    int a = i;
                    int b = prime[n / i];
                    int c = (n / i) / prime[n / i];
                    set<int> s;
                    s.insert(a);
                    s.insert(b);
                    s.insert(c);
                    if((int)s.size() == 3) {
                        cout << "YES\n";
                        cout << a << " " << b << " " << c << "\n";
                        flag = 1;
                        break;
                    }

                
                }
            }
        }
        if(!flag) cout << "NO\n";
    }
    return 0;
}

