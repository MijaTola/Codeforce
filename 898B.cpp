#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;

    for (int i = 0; i <= n; ++i) {
        long long cur = n - 1LL * i * a;
        if(cur < 0) continue;
        if(cur % b == 0){
            cout << "YES\n";
            cout << i << " " << cur / b << "\n";
            return 0;
        }
    }
    puts("NO");
    return 0;
}

