#include <bits/stdc++.h>

using namespace std;

int v[4];
int main() {
    
    for (int i = 0; i < 4; ++i) 
        cin >> v[i];
    sort(v, v + 4);
    do {
        if((v[0] + v[1]) == (v[2] + v[3])) return cout << "YES\n",0;
        if((v[0]) == ( v[1] + v[2] + v[3])) return cout << "YES\n",0;
        if((v[3]) == ( v[1] + v[2] + v[0])) return cout << "YES\n",0;
    }while(next_permutation(v, v + 4));
    cout << "NO\n";
    return 0;

}

