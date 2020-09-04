#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie();
    int n;
    cin >> n;
    if(n == 0){
    	cout << 0 << endl << 0;
    	return 0;
    }
    if(n == 3){
    	cout << 2 << endl << "1 3";
    	return 0;
    }
    if(n == 1){
    	cout << 1 << endl << 1;
    	return 0;
    }
    if(n == 2){
    	cout << 1 << endl << 1;
    	return 0;
    }
    if(n == 4){
    	cout << 4 << endl << "2 4 1 3";
    	return 0;
    }
    cout << n << endl;
    for (int i = 1; i <= n; i+=2)
    	cout << i << " ";
    cout  << 2;
    for (int i = 4; i <= n; i+=2)
    	cout <<" " <<i;
    return 0;   
}   