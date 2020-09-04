#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int v[10000] ;

ll convert(int n){
	ll ans = 0;
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		ans += v[i];
		if(i + 1 < n)ans *= p;
	}
	return ans;
}
int main(){
	ll n;
	cin >> n;
	long long ans = 123456789123456789;
	long long dis = 123456789123456789;
	bool sw = false;
	int tam = log10(n) + 1;
	if(tam&1)tam++;
	while(!sw){
	int mid = tam/2;
	for (int i = 0; i < tam; ++i)
	{
		if(i > mid-1) v[i] = 7;
		else v[i] = 4;
	}
	do{
		unsigned long long number = convert(tam);
		unsigned long long rest = number - n;
		if(number >= n){
			if(rest < dis){
				dis = rest;
				ans = number;
				sw = true;
			}
		}
	}while(next_permutation(v,v+tam));
	tam+=2;
	}
	cout << ans;
	return 0;
}