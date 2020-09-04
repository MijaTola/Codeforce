#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	char x;
	cin >> n;
	int s = -1,t = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if(x=='L'){
			s = i;
			if(t == -1){ t = i-1;}
		}else if(x == 'R'){
			s = i;
			t = i + 1;
		}
	}
	cout << s +1 << " " << t + 1 ;
	return 0;
}