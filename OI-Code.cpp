#include <iostream>
#include <algorithm>
  
using namespace std;
  
int main()
{
    int n;
    cin >> n;
  
    bool is_first = true;
    for (int i = n; i >= 0; i -- )
    {
        int a;
        cin >> a;
  
        if (!a) continue;
  
        if (!is_first && a > 0) printf("+");
        else if (a < 0) printf("-");
        if (abs(a) != 1 || !i) printf("%d", abs(a));
        if (i) printf("x");
        if (i > 1) printf("^%d", i);
  
        is_first = false;
    }
  
    return 0;
}
