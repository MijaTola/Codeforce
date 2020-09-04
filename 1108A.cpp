#include <bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;
    while(q--) {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int a = l1;
        int b = 0;
        for (int i = l2; i <= r2; i++) 
            if(i != a) {
                b = i;
                break;
            }
        cout << a << " " << b << "\n";
    }
    return 0;
}

