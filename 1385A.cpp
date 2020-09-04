#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int x,y,z;
        cin >> x >> y >> z;

        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
    

        bool flag = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int a = v[i];
                    int b = v[j];
                    int c = v[k];
                    if(max(a,b) == x and max(a,c) == y and max(b,c) == z) {
                        cout << "YES\n" << a << " " << b << " " << c << "\n";
                        flag = 1;
                        goto fin;
                    } 
                }
            }
        }
        fin:

        if(!flag) cout << "NO\n";



    }
    return 0;
}

