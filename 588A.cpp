#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int n;
	cin >> n;
	int price = 999999999;
	int money = 0;
	for (int i = 0; i < n; ++i)
	{
		int a,p;
		cin >> a >> p;
		price = min(p,price);
		money += price*a;
	}
	cout << money <<endl;
	return 0;
}