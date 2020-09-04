#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;

    long long moves = n / k;
    
    if(moves&1) puts("YES");
    else puts("NO");
    return 0;
}

