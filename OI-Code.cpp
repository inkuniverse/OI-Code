#include<bits/stdc++.h>
using namespace std;

int a[9][9]; // a = array

bool Check(int check_number,int check_now_line,int check_now_column,int check_block_line,int check_block_column)
{
	for(int i=0;i<=8;++i)
	{
		if(a[check_now_line][i]==check_number||a[i][check_now_column]==check_number) 
			return false;
	}
	for(int i=0;i<=2;++i)
	{
		for(int j=0;j<=2;++j)
		{
			if(a[check_block_line+i][check_block_column+j]==check_number)
				return false;
		}
	}
	return true;
}

bool Work(int now_line,int now_column)
{
	if(now_line==9)
	{
		return true;
	}
	else 
	{
		int next_line,next_column,block_line,block_column;
		next_column=now_column+1;
		next_line=(next_column>=9?now_line+1:now_line);
		next_column=(next_column>=9?0:next_column);
		if(a[now_line][now_column]!=0)
		{
			if(Work(next_line,next_column)) return true;
		}
		else
		{
			block_line=(now_line/3)*3;
			block_column=(now_column/3)*3;
			for(int i=1;i<=9;++i)
			{
				if(Check(i,now_line,now_column,block_line,block_column))
				{
					a[now_line][now_column]=i;
					if(Work(next_line,next_column)) return true;
				}
			}
			a[now_line][now_column]=0;
			return false;
		}
	}
}

void Output()
{
	for(int i=0;i<=8;++i)
	{
		for(int j=0;j<=8;++j)
		{
			printf("%d ",a[i][j]);
		}
		cout<<endl;
	}
}
int main()
{
	for(int i=0;i<=8;++i)
	{
		for(int j=0;j<=8;++j)
		{
			cin>>a[i][j];
		}
	}
	if(Work(0,0)) Output();
	else cout<<"No Answer."<<endl;
	return 0;
}
