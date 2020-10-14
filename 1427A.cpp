#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        
        int n;
        cin >> n;
        vector<int> v(n);

        int sum = 0;

        for (int &x: v) {
            cin >> x;
        }
       
        sort(v.begin(), v.end());

        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            sum += v[i];
            flag &= sum != 0;
        }
       

        if(flag)  {
            cout << "YES\n";
            for (int x: v)
                cout << x << " ";
            cout << "\n";
        } else {
         
            sum = 0;
            bool flag = 1;
            for (int i = n - 1; i >= 0; i--) {
                sum += v[i];
                flag &= sum != 0;
            }
            if(flag) { 
                cout << "YES\n";
                for (int i = n - 1; i >= 0; i--) {
                    cout << v[i] << "\n";   
                }
                cout << "\n";
            } else cout << "NO\n";
        }

        


    }
    return 0;
}

