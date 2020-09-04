#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    set<int> s;
    int mn = min(1000000000LL,k);
    for (int i = 1; i <= mn; ++i) {
        if(s.count(n % i)) return cout << "No\n",0;
        s.insert(n % i);
    }
    cout << "Yes\n";
    return 0;
}

