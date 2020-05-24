#include<iostream>
#include<cmath> //abs
using namespace std;
string str; int sum,cnt;char c;
int main(void)
{
	cin>>str;
	for(int i = 0;i < str.size()-1;i++)
		if(str[i] != '-')
			sum += (str[i]-48)*(++cnt);
	sum %= 11;
	if(sum < 10)c = sum+48;
	else c='X';
	if(c == str.back())puts("Right");
	else 
	{
		str.back()=c;
		cout<<str<<endl;
	}
	return 0;
}
