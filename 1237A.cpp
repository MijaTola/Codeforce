#include <bits/stdc++.h>

using namespace std;

int a[20000];
int b[200010];
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int sum = 0;
    int c = 0;
    
    for (int i = 0; i < n; ++i) {
        if(a[i] & 1) c++;
        b[i] = a[i] / 2;
        sum += b[i];
    }
    
    if(sum > 0) {
        for (int i = 0; i < n and sum; ++i) {
            if(a[i] & 1 and a[i] < 0) {
                sum--;
                b[i]--;
            }
        }
    } else {
        for (int i = 0; i < n and sum < 0; ++i) {
            if(a[i] & 1 and a[i] >= 0) {
                sum++;
                b[i]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) 
        cout << b[i] << "\n";
    


    return 0;
}

