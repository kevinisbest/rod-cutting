#include<cstdlib>
#include<iostream>
#include<algorithm>
//#include"stdafx.h"
using namespace std;

int rotcut(int R[], int N)
{
	int r[N];
	r[0] = 0;
	for (int j = 1; j <= N; j++)
	{
		int q = -1000;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, R[i] + r[j - i]);//從i=1開始將切下來的最大值紀錄 

			r[j] = q;
		}
	}
	return r[N];

}
int count(int C[], int N)
{
	int r[N],s[N];
	
	r[0] = 0;
	s[1] = 1;
	for (int j = 1; j <= N; j++)
	{
		int q = -1000;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, C[i] + r[j - i]);
			r[j] = q;//等於上面的再做一次記錄下來 
		}
		for (int i = 1; i < j / 2 + 1; i++)
		{

			if (r[j] == r[i] + r[j - i])//如果有哪兩個可以組成 
			{
				s[j] = s[i] + s[j - i];//s[]就換成組成的和與pdf上的s[]不同 
				break;
			}
			else
			{
				s[j] = 1;
			}
		}
	}
	return s[N];

}
int sorting(int S[], int N)
{
	int r[N], s[N];

	r[0] = 0;
	s[0] = 0;
	s[1] = 1;

	for (int j = 1; j <= N; j++)
	{
		int q = -1000;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, S[i] + r[j - i]);
			r[j] = q;
		}
		for (int i = 1; i < j / 2 + 1; i++)
		{

			if (r[j] == r[i] + r[j - i])
			{
				s[j] = s[i] + s[j - i];
				if (j == N)
				{
					cout << N << " = " << i << " + " << j - i;
				}
				break;
			}
			else
			{
				s[j] = 1;
			}
		}
	}
	if (s[N] == 1)
	{
		cout << N << " = " << N;
	}
	
}

int main()
{
	int k,i;
	cin >> k;
	if (k == 0)
	{
		return 0;
	}
	else
	{
		int *cut;
		cut=new int[k];
		cut[0] = 0;
		for (i = 1; i <= k; i++)
		{
			cin >> cut[i];
		}

		
		
		cout << rotcut(cut, k) << endl << count(cut, k) << endl;
		sorting(cut, k);
		cout<<endl<<"done";
		system("pause");
		delete[] cut;
	}
}
