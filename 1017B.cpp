#include <bits/stdc++.h>

using namespace std;

bool v[100010];
int n;
string a,b;   
int main(){
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i) {
        int da = a[i] - '0';
        int db = b[i] - '0';
        v[i] = da or db;
    }

    int zz = 0,zo = 0,ones = 0,zeros = 0;

    for (int i = 0; i < n; ++i) {
        if(v[i] and b[i] == '0') zo++;
        if(!v[i] and b[i] == '0') zz++;
        if(a[i] == '1') ones++;
        else zeros++;
    }
    long long ans = 0;
    ans = zz * ones + zo * (zeros - zz);
    cout << ans  << "\n";
    return 0;
}

