#include <iostream>

using namespace std;

long long a[6], b[6];
int main(){

    int n,m;
    cin >> n >> m;
   
    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        a[i % 5]++;
    }

    for (int i = 1; i <= m; ++i)
        b[i % 5]++;

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) 
            if((i + j) % 5 == 0) {
                ans += a[i] * b[j];
            }

    cout << ans << "\n";
        
    return 0;
}
