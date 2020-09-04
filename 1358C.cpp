#include <bits/stdc++.h>

using namespace std;

int c[110][110];

set<int> s;

int fx, fy;
void f(int x, int y, int sum) {
    if(x > fx or y > fy) return;
    //cout << x << " " << y << " " << c[x][y] << "\n";
    if(x == fx and y == fy) {
        s.insert(sum + c[x][y]);
        return ;
    }
    
    f(x + 1, y, sum + c[x][y]);
    f(x, y + 1, sum + c[x][y]);

}
int main() {

    int cur = 1;
    for (int i = 0, s = 1; i < 100; ++i, s++) {
        int row = cur;
        for (int j = 0, l = s; j < 100; ++j, l++) {
            c[i][j] = row;
            row += l;
        }
        cur += (i + 2);
    }

    int t;
    cin >> t;
    while(t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        c -= a;
        d -= b;
        c++,d++;
        if(c > d) swap(c,d);
        d -= (c - 1) ;
        
        auto get = [&] (long long x, bool f) {
            if(f) {
                return (x * (x + 1));
            }
            return x * x;
        };
        
        if(d & 1) {
            cout << 1LL + get(c + d / 2 - 1, 0) -  get(d / 2 , 0) << "\n";
        } else {
            cout << 1LL + get(c + d / 2 - 2, 1) -get(d / 2 - 1, 1) << "\n";
        }

    }

    return 0;
}

