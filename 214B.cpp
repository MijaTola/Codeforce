#include <bits/stdc++.h>

using namespace std;

int v[10];

int main(){
	int n, i, sum=0, x;
	memset(v, 0,sizeof v);
	cin >> n;	
	for(i=0; i<n; i++){
	    cin >> x;
	    sum+=x;
	    v[x]++;
	}
	if(v[0]==0) return cout << -1,0;
	if(sum>0 && sum<3) return cout << 0,0;

	bool sw = false;
	if(sum%3 == 1){
		if(v[1]){v[1]--;sw = true;}
		else if(v[4]){v[4]--;sw = true;}
		else if(v[7]){v[7]--;sw = true;}
		if(!sw){
			if(v[2] + v[5] + v[8]< 2) return cout << 0,0;
			for (int i = 0; i < 2; ++i)
			{
			if(v[2]){v[2]--;}
			else if(v[5]){v[5]--;}
			else if(v[8]){v[8]--;}
			}
		}
	}
	sw = false;
	if(sum%3 == 2){
		if(v[2]){v[2]--;sw = true;}
		else if(v[5]){v[5]--;sw = true;}
		else if(v[8]){v[8]--;sw = true;}
		if(!sw){
			if(v[1] + v[4] + v[7]< 2) return cout << 0,0;
			for(int i = 0; i < 2;++i){
				if(v[1])v[1]--;
				else if(v[4])v[4]--;
				else if(v[7])v[7]--;
			}
		}
	}
	sum = 0;	
	for (int i = 0; i <= 9; ++i)
		sum += v[i]*i;

	if(sum == 0) return cout << 0,0;
	    for (int i = 9; i >= 0; --i){
	    		for (int j = 0; j < v[i]; j++)
	  				cout << i;
	    }
	  	

	  return 0;
}