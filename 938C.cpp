#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int main(){

    int p = 1;
    while((long long)p * p < 1e9) {
        v.push_back(p * p);
        p++;
    }
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        for (int i = 0; i < (int)v.size(); ++i) {
            long long matrix = v[i];
            long long n = (long long)sqrt(matrix);
            long long zeros = abs(matrix - x);
            long long s = (int)sqrt(zeros);
            cout << n << " " << zeros << " " << s << "\n";
            if(matrix < x) continue;
            if(s * s != zeros or s == 0 or n / s == 1) continue;
            cout << n << " " <<  n / s << "\n";
            goto end;
        }
        cout << "-1\n";
        end:;
        
    }
    return 0;
}

