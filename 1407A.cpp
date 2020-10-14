#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        int a = 0, b = 0;
        for(int &x: v) {
            cin >> x;
            if(x == 1) a++;
            else b++;
        }

        vector<int> ans;
        if(a > b) {

            if(a & 1) a--;

            cout << a << "\n";
            for (int i = 0; i < a; ++i)
                cout << 1 << " ";
            cout << "\n";
        } else {
            cout << n / 2 << "\n";
            for (int i = 0; i < n / 2; ++i)
                cout << 0 << " ";
            cout << "\n";
        }


    }
    return 0;
}

