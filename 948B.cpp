#include <bits/stdc++.h>

using namespace std;

bool prime[10001000];
vector<int> p;
int x;

int bs(int cp, int y) {
    int a = -1, b = 1000010;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(mid * cp > y) b = mid;
        else a = mid;
    }
    return b * cp;
}

int f(int p1, int p2) {
    
}

int main() {
    for (int i = 2; i * i < 1000100; ++i) 
        for (int j = i + i; j < 1000010; j += i) 
            prime[j] = 1;
    
    for (int i = 2; i < 1000100; ++i) 
        if(!prime[i]) p.push_back(i);
    cout << p.size() << "\n";
    return 0;
}

