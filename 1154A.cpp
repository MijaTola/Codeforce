#include <bits/stdc++.h>

using namespace std;

int v[4];
int main() {

    for (int i = 0; i < 4; ++i)
        cin >> v[i];
    sort(v, v + 4);
    do {
        int a = v[3] - v[2];
        int b = v[0] - a;
        int c = v[1] - a;
        if(a + b == v[0] and a + c == v[1] and b + c == v[2] and a + b + c == v[3]) {
            return cout << a << " " << b << " " << c << "\n",0;
        }
    } while(next_permutation(v, v + 4));
    

    return 0;
}

