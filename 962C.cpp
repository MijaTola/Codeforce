#include <bits/stdc++.h>

using namespace std;

bool ver(int x) {
    if((int)sqrt(x) == sqrt(x)) return 1;
    return 0;
}
int main(){
    int n; cin >> n;

    queue<pair<int,int> > q;
    q.push({n,0});
    bool zero = 0;
    while(!q.empty()) {
        int number = q.front().first;
        int c = q.front().second;
        q.pop();
        if(ver(number)) {
            if(!zero and number == 0) continue;
            cout << c<<"\n";
            return 0;
        }
        int cur = number;
        int right = 0;
        long long p = 1;
        while(cur > 0) {
            int d = cur % 10;
            zero |= d == 0;
            int n2 = (cur / 10) * p + right;
            //cout << n2 << " " << (int)log10(n2) + 1 << " " << (int)log10(n)  - c  << "\n";
            if((int)log10(n2) + 1 == (int)log10(n) - c)
                q.push({n2,c + 1});
            right = d * p + right;
            cur /= 10;
            p *= 10;
        }
    }
    cout << "-1\n";
    return 0;
}

