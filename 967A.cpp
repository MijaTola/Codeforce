#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int main(){

    int n,s; cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        int h,m;
        cin >> h >> m;  
        int total =  h * 60 + m;
        v.push_back(total);
    }
    
    int dif = v[0] - 1;
    if(dif >= s) {
        return cout << 0 << " " << 0 << "\n",0;
    }
    for (int i = 1; i < n; ++i) {
        int dif = v[i] - v[i - 1];
        if(dif >= (2 * s) + 2) {
            int ans = v[i - 1] + s + 1;
            int hours = ans / 60;
            int min = ans % 60;
            cout << hours << " " << min << "\n";
            return 0;
        }
    }

    int ans = v[n - 1] + s + 1;
    int hours = ans / 60;
    int min = ans % 60;
    cout << hours << " " << min << "\n";
    return 0;
}

