#include <bits/stdc++.h>

using namespace std;

vector<int> p;
bool pr[10001000];
void f() {
    memset(pr,false,sizeof pr);
    for (int i = 2; i * i < 10001000; ++i) {
        int  c = i + i;
        while(c < 10001000) {
            pr[c] = 1;
            c += i;
        }
    }
    
    for (int i = 2; i < 10001000; ++i) 
        if(!pr[i])p.push_back(i);
}
int main(){
    f();
    memset(pr,false,sizeof pr);
    int n; cin >> n;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int last = x;
        x--;
        do {
            x++;
            x = p[lower_bound(p.begin(),p.end(),x) - p.begin()];
        }while(pr[x]);
        pr[x] = 1;
        cout << x << " ";
        c++;
        if(x > last) break;
    }
    int pos = 0;
    while(c < n) {
        while(pr[p[pos]])pos++;
        cout << p[pos] << " ";
        c++;
    }
    cout << "\n";

    return 0;
}

