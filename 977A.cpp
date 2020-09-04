#include <bits/stdc++.h>

using namespace std;

int  v[100010];
int main(){
    int n; cin >> n;
    int k; cin >> k;

    while(k and n) {
        if(n %  10 != 0 ) n--;
        else n/=10;
        k--;
    }
    cout << n << "\n";
    return 0;
}

