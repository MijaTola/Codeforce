#include <iostream>

using namespace std;

int main(){
    string x;
    cin >> x;


    for (int i = 0; i < (int)x.size(); ++i) cout << x[i];
    for (int i = (int)x.size()-1; i >= 0; --i) cout << x[i];
    return 0;
}
