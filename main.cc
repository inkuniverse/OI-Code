#include<iostream>
#include<vector>
using namespace std;

template<class T, class VAL>
T lowerbound(T begin, T end, VAL val)
{
	T l = begin, r = end; if(r != begin) r--; else return l;
	while(l < r)
	{
		T mid = l + (r - l) / 2;
		if(*mid >= val) r = mid;
		else {l = mid; l++;}
	}
	return l;
}

template<class T, class VAL>
T upperbound(T begin, T end, VAL val)
{
	T l = begin, r = end; if(r != begin) r--; else return l;
	while(l < r)
	{
		T mid = l + (r - l) / 2;
		if(*mid > val) r = mid;
		else {l = mid; l++;}
	}
	return l;
}

vector<int> a = {1, 2, 3, 5, 6};
int main(void)
{
	cout << *lowerbound(a.begin(), a.end(), 5) << endl;
	cout << *upperbound(a.begin(), a.end(), 5);
	return 0; 
} 
