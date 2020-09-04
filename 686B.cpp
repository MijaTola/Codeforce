#include <iostream>

using namespace std;

int v[110];
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];

    bool flag = true;
    while(flag){
    flag = false;
    for (int i = 0; i < n; ++i){
        if(v[i] > v[i+1]){
            flag = true;
            cout << i << " " << i+1 <<endl;
        }
    }
    }
    return 0;
}
