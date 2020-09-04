#include <bits/stdc++.h>

using namespace std;

int conver(string x){
	istringstream ss(x);
	int l;
	ss >> l;
	return l;

}
int main(){
	map<int,string> hours;

	hours[0] = "01:10"; hours[1] = "02:20"; 
	hours[2] = "03:30"; hours[3] = "04:40"; 
	hours[4] = "05:50"; hours[5] = "10:01"; 
	hours[6] = "10:01"; hours[7] = "10:01"; 
	hours[8] = "10:01"; hours[9] = "10:01";
	hours[10] = "11:11"; hours[11] = "12:21"; 
	hours[12] = "13:31"; hours[13] = "14:41";
	hours[14] = "15:51"; hours[15] = "20:02";
	hours[16] = "20:02"; hours[17] = "20:02";
	hours[18] = "20:02"; hours[19] = "20:02";
	hours[20] = "21:12"; hours[21] = "22:22";
	hours[22] = "23:32"; hours[23] = "00:00";

	string x;
	cin >> x;
	string p = x.substr(0,2);
	if(p == "00"){
		cout << hours[0];return 0;
	}
	int r = conver(p);
	string t = x.substr(3,p.size());
    string comp = hours[r-1].substr(3,p.size());
	if(t < comp) cout << hours[r-1];
	else cout << hours[r];
	return 0;
}