#include <bits/stdc++.h>

using namespace std;

int v[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool verifyday(int d,int month){
	return d <= v[month];
}
int main(){
	string x;
 	cin>> x;
 	map<string,int> data;
	for (int i = 0; i < x.size()-9; ++i)
	{	
		string date = "";
		string year = "";;
		for (int j = i; j < i+10; ++j){
			date += x[j];
			if(i+10-j <= 4)year+=x[j];
		}
		bool sw = false;
		if(date[2] == '-' and date[5]=='-'){
			if(year == "2013" or year == "2014" or year=="2015"){
				int day = 0;
				bool ver = true;;
				for (int k = 0; k < 2; ++k)
				{
					day += date[k] - '0';
					day *= 10;
					if(!isdigit(date[k])) ver = false;
				}
				day /=10;
				int month = 0;
				for (int k = 3; k < 5; ++k)
				{
					month += date[k] - '0';
					month *= 10;
					if(!isdigit(date[k])) ver = false;
				}
				month/= 10;
				if(verifyday(day,month) and month <= 12 and ver and day > 0)
					sw = true;
	
				
			}
		} 
		if(sw) data[date]++;
		
		
	}
	string ans;
	int maxi = -1;
	for(std::map<string,int>::iterator i = data.begin(); i != data.end();++i){
		if(i->second >= maxi){
			maxi = i->second;
			ans = i->first;
		}
	}
	cout << ans;
	return 0;
}