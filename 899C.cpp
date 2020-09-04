#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int main(){
    
    scanf("%d", &n);
    
    int a = 0, b = 0;
    for (int i = n; i >= 1; --i) {
        if(a < b) {
            a += i;
            v.push_back(i);
        } else b += i;
    }

    printf("%d\n%d ", abs(a - b), (int)v.size());
    
    for (int i = 0; i < (int)v.size(); ++i) {
        printf("%d ", v[i]);
    }
    puts("");
    return 0;
}

