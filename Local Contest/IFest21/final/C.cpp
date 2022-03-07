#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
typedef long long LL;
using namespace std;
const int maxn=10100;
int num[maxn], n, m;
int val[maxn];
int tmp[maxn];
int back[5][5];
int ans;

bool valid(int N)
{
	int sz[5];
	for (int i=1; i<=4; i++)
	{
		sz[i]=N%10;
		N/=10;
	}
	sort(sz+1,sz+5);
	for (int i=1; i<4; i++)
		if (sz[i]==sz[i+1])
			return false;
	return true;
}

void addAns(int X, int Y)
{
	int ti[4], tj[4];
	int x=num[X], y=val[Y];
	for (int i=0; i<4; i++)
	{
		ti[i]=x%10;
		tj[i]=y%10;
		x/=10;
		y/=10;
	}
	int l=0, r=0;
	for (int i=0; i<4; i++)
		l+=ti[i]==tj[i];
	bool use[10];
	memset(use,0,sizeof use);
	for (int i=0; i<4; i++)
		if (!use[ti[i]])
			for (int j=0; j<4; j++)
				if (ti[i]==tj[j]&&ti[i]!=tj[i]){
					r++;
					use[ti[i]]=1;
				}
	back[l][r]++;
}

int getBack(int x, int &l, int &r){
	int ti[4], tj[4];
	int y=ans;
	for (int i=0; i<4; i++)
	{
		ti[i]=x%10;
		tj[i]=y%10;
		x/=10;
		y/=10;
	}
	l=0, r=0;
	for (int i=0; i<4; i++)
		l+=ti[i]==tj[i];
	bool use[10];
	memset(use,0,sizeof use);
	for (int i=0; i<4; i++)
		if (!use[ti[i]])
			for (int j=0; j<4; j++)
				if (ti[i]==tj[j]&&ti[i]!=tj[i]){
					r++;
					use[ti[i]]=1;
				}
}

int main()
{
//	scanf("%d",&ans);
	for (int i=0; i<10000; i++)
		if (valid(i))
			num[++n]=i;
	for (int i=1; i<=n; i++)
		val[i]=num[i];
	m=n;
	int cnt=0;
	while (++cnt){
		if (m==1){
			printf("%04d\n",val[1]);
			fflush(stdout);
			break;
		}
		int nowask=-1,nowmin=0x3f3f3f3f;
		if (m!=5040){
			for (int i=1; i<=n; i++)
			{
				memset(back,0,sizeof back);
				for (int j=1; j<=m; j++)
					addAns(i,j);
				int maxPart=-1;
				for (int j=0; j<=4; j++)
					for (int k=0; k<=4; k++)
						if (back[j][k]>maxPart)
							maxPart=back[j][k];
				if (maxPart<=nowmin)
				{
					nowmin=maxPart;
					nowask=i; 
				}
			}
		} else {
			nowask=1;
		}
		// printf("%04d\n",num[nowask]);
		// fflush(stdout);
        {
            string s = to_string(num[nowask]);
            while (s.size() < 4){
                s = "0" + s;
            }
            for (auto &x : s){
                cout << x << ' ';
            }
            cout << endl;
        }
		int ok,next;
//		getBack(num[nowask],ok,next);
		scanf("%d%d",&ok,&next);
        ok -= next;
        swap(ok, next);
		if (ok==4) break;
		int nowm=m;
		m=0;
		for (int i=1; i<=nowm; i++)
		{
			back[ok][next]=0;
			addAns(nowask,i);
			if (back[ok][next])
				tmp[++m]=val[i];
		}
		for (int i=1; i<=m; i++)
			val[i]=tmp[i];
	}
//	fprintf(stderr,"%d\n",cnt);
	return 0;
}
