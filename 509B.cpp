#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int mini = INT_MAX;
	int maxi = INT_MIN;
	int dn[100];
	for (int i = 0; i < n; ++i)
	{
		cin >> dn[i];
		mini = min(mini,dn[i]);
		maxi = max(maxi,dn[i]);
	}

	if(maxi - mini > k){
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i)
	{
		 for (int j = 0; j < mini; j++)
            cout << 1 << " ";
        for (int j = mini; j < dn[i]; j++)
        {
            cout << j-mini+1;
            if (j != dn[i] - 1)
               cout << " ";
        }
		cout << endl;
	}
	return 0;
}