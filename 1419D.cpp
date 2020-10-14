#include <bits/stdc++.h>

using namespace std;

void task1() {

    int n;
    cin >> n;

    vector<int> v(n), ans(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    for (int i = 0, p = 1; i < n / 2; ++i, p += 2) {
        ans[p] = v[i];
    }
    
    vector<int> del;
    for (int i = n - 1; i >= 0; i-=2) {
        while(ans[i - 1] >= v.back()) {
            del.push_back(v.back());
            v.pop_back();
        }
        if((int)v.size() < n / 2) break;
        ans[i] = v.back();
        v.pop_back();
    }


    for (int i = 0; i < n; ++i) {
        if(ans[i] == 0) {
            ans[i] = del.back();
        del.pop_back();
        }

    }



    int c = 0;
    for (int i = 1; i < n; i += 2) {
        c += ans[i] < ans[i - 1] and ans[i] < ans[i + 1];
    }

    cout << c << "\n";

    for (int x: ans)
        cout << x << " ";
    cout << "\n";
   
}

int main() {
    
    task1();
    return 0;
}

