#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int pos = 1;
    while(v[pos] > v[pos-1]) pos++;
    while(v[pos] == v[pos-1]) pos++;
    while(v[pos] < v[pos-1]) pos++;
    if(pos == n + 1) cout << "YES";
    else cout << "NO";
    return 0;
}

