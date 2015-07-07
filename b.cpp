
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 50005;
int sum[maxn<<2],n,q;
char a[maxn];
int mark[maxn];
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
	if(l == r)
	{
		sum[rt] = mark[l];
		return ;
	}
	int m =(l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p,int val,int l,int r,int rt)
{
	if(l == r)
	{
		sum[rt] = val;
		return ;
	}
	int m = (l + r) >> 1;
	if(p <= m) update(p,val,lson);
	if(p > m) update(p,val,rson);
	pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L <= l && r <= R)
	{
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if(L <= m) ret += query(L,R,lson);
	if(R > m) ret += query(L,R,rson);
	return ret;
}

int main()
{
	int T,L,R,op,pos;
	char s[5];
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case %d:\n",cas);
		scanf("%d%d",&n,&q);
		scanf("%s",a+1);
		memset(mark,0,sizeof(mark));
		for(int i=3; i<=n; i++)
		{
			if(a[i-2]=='w'&&a[i-1]=='b'&&a[i]=='w')
			mark[i]=1;
		}
		build(1,n,1);
		while(q--)
		{
			scanf("%d",&op);
			if(op==0)
			{
				scanf("%d%d",&L,&R);
				L++;R++;
				if(R - L < 2)
				printf("0\n");
				else
				printf("%d\n",query(L+2,R,1,n,1));
				/*
                 a[L-1]=='w'&&a[L]=='b'&&a[L+1]=='w'
                 a[L-2]=='w'&&a[L-1]=='b'&&a[L]=='w'
               */
			}
			else
			{
				scanf("%d%s",&pos,s);
				pos++;
				if(s[0]==a[pos]) continue;
				if(pos >= 3)
				{
					if(a[pos-2]=='w'&&a[pos-1]=='b'&&a[pos]=='w')
					update(pos,0,1,n,1);
					if(a[pos-2]=='w'&&a[pos-1]=='b'&&a[pos]=='b')
					update(pos,1,1,n,1);
				}
				if(pos >= 2 && pos + 1 <= n)
				{
					if(a[pos-1]=='w'&&a[pos]=='b'&&a[pos+1]=='w')
					update(pos+1,0,1,n,1);
					if(a[pos-1]=='w'&&a[pos]=='w'&&a[pos+1]=='w')
					update(pos+1,1,1,n,1);
				}
				if(pos+2 <= n)
				{
					if(a[pos]=='w'&&a[pos+1]=='b'&&a[pos+2]=='w')
					update(pos+2,0,1,n,1);
					if(a[pos]=='b'&&a[pos+1]=='b'&&a[pos+2]=='w')
					update(pos+2,1,1,n,1);
				}
				a[pos] = s[0];
			}
		}
	}
	return 0;
}
