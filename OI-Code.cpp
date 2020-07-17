#include<stdio.h>
#include<math.h>
int ans;
int sx,sy,tx,ty;
int excel[5][5]=
	{{0,3,2,3,2},
	 {3,2,1,2,3},
	 {2,1,4,3,2},
	 {3,2,3,2,3},
	 {2,3,2,3,4}};
void swap(int *x,int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
int main()
{
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	int x=abs(sx-tx);
	int y=abs(sy-ty);
	while(x>4||y>4)
	{//贪心
		if(x<0)x=-x;
		if(y<0)y=-y;
		if(x<y)swap(&x,&y);
		x-=2;y-=1;
		ans++;
	}
	printf("%d\n",ans+excel[x][y]);
	return 0;
}
