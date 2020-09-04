#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,m;
    cin >> n >> m;
    int c = 0;
    pair<int,int> ft;
    pair<int,int> sd;
    bool flag = 1;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if(c == 'B') {
                if(flag) {
                    ft.first = i;
                    ft.second = j;
                    flag = 0;
                }
                sd.first = i;
                sd.second = j;
            }
        }
    
    cout << (sd.first + ft.first + 1) / 2 + 1<< " ";
    cout << (sd.second + ft.second + 1) / 2  + 1<< "\n";
    return 0;
}

