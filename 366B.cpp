#include <iostream>

using namespace std;

int ans[100001];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans[i%k] += a;
    }
    int pos = 0;
    for(int i = 0; i < k; i++)
        if(ans[i] < ans[pos])
            pos = i;

    cout << pos +1;
}