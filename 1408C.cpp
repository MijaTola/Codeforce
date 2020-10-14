#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n,l;
        cin >> n >> l;

        vector<int> v(n);

        for (int &x: v) 
            cin >> x;

        long double a = 0, b = l;
        long double t3 = 0;

        for (int i = 0; i < 50; ++i) {
            long double mid = (a + b) / 2;
                
            int pos = 0;
            int ini = 0;
            long double vl = 1;
            long double t1 = 0;

            while(v[pos] < mid and pos < n) {
                long double dis = abs(v[pos] - ini);
                long double curT = dis / vl;   
                t1 += curT;
                vl++;
                ini = v[pos];
                pos++;
            }

            long double dis = abs(mid - ini);
            long double curT = dis / vl;   

            t1 += curT;

            ini = l;
            pos = n - 1;
            vl = 1;
            long double t2 = 0;

            while(v[pos] > mid and pos >= 0) {
                dis = abs(v[pos] - ini);
                curT = dis / vl;   
                t2 += curT;
                vl++;
                ini = v[pos];
                pos--;
            }

            dis = abs(mid - ini);
            curT = dis / vl;   
            t2 += curT;

            if(t1 < t2) a = mid;
            else b = mid;

            t3 = t1;
        }

        cout.precision(7);
        cout << fixed  << t3 << "\n";
    }   
    return 0;
}

