#include <iostream>

using namespace std;

int main(){

    int n;
    long long x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        char c; long long s;
        cin >> c >> s;
        if(c == '+') x += s;
        else{
            if(x >= s) x -= s;
            else ans++;
        }
    }
    cout << x << " " << ans << endl;
    return 0;
}
