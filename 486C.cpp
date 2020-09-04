	#include <iostream>
	#include <algorithm>
	#include <queue>
	#include <stack>
	#include <vector>
	#include <climits>
	#include <map>
	#include <set>
	#include <cassert>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <deque>
	#include <string> 
	#include <sstream>
	#include <cstdlib>
	#include <unordered_set>
	#include <unordered_map>

	using namespace std;
	string s;
	int main() {
		int n, k;
		cin>>n>>k;
		cin>>s;
		
		if(k > (n+1)/2) {
			for(int i = 0; i < (n+1)/2; ++i) {
				char x = s[i];
				s[i] = s[n-i-1];
				s[n-i-1] = x;
			}
			k = n-k+1;
		}
		k--;
		//cout<<"s is "<<s<<"k is "<<k<<endl;
		int i = k+1;
		int right = -1;
		int left = -1;
		int ans = 0;
		while(i < (n+1)/2) {
			if(s[i] != s[n-i-1]) {
				right = i;
				int diff = s[n-i-1] - s[i];
				if(diff < 0)    diff *= -1;
				diff = min(diff, (-diff+26)%26);
				//cout<<"diff "<<diff<<endl;
				ans += diff;
			}
			i++;
		}
		i = k;
		while(i >= 0) {
			if(s[i] != s[n-i-1]) {
				left = i;
				int diff = s[n-i-1] - s[i];
				if(diff < 0)    diff *= -1;
				diff = min(diff, (-diff+26)%26);
				//cout<<"diff "<<diff<<endl;
				ans += diff;    
			}
			i--;
		}
		//cout<<"k is "<<k<<endl;
		//cout<<"ans "<<ans<<endl;
		//cout<<"l and r "<<left<<" "<<right<<endl;
		if(left != -1 && right != -1)
			ans += min(right-k + right - left, k - left + right - left);
		else if(right == -1 && left != -1)
			ans += k - left;
		else if(left == -1 && right != -1)
			ans += right -k;
		cout<<ans;
		
		
		
		return 0;
	}
