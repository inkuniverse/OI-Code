#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	bool isf = true;
	cin >> n;
	for (int i = n; i >= 0; i -- )
	{
		int a;
		cin >> a;
		if(a)
		{
			if (!isf && a > 0) printf("+");
			else if (a < 0) printf("-");
			if (abs(a) != 1 || !i) printf("%d", abs(a));
			if (i) printf("x");
			if (i > 1) printf("^%d", i);
			isf = false;
		}
	}

	return 0;
}
