#include<algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#define clr(a,x) memset(a,x,sizeof a)
#define X first
#define Y second
typedef  long long LL;
using namespace std;
const double pi  = acos(-1.0);
const double eps = 1e-8;
const LL INF = 1LL<<40;
const LL dir[4][2] = {0,1,-1,0,0,-1,1,0};
const int Mod = 998244353;
using namespace std;

LL _buf[50];
inline LL read()
{
    char c = getchar();
    LL isMinus = 1;
    LL x = 0;
    while ( c!='-' && ( c<'0' || c>'9' )) c = getchar();
    if (c=='-') {isMinus = -1;c= getchar();}
    while ( c>='0' &&c<='9' ) {x = x*10+c-'0';c=getchar();}
    return x * isMinus;
}
inline void write(LL num,LL flag = 1)
{
    if (num<0) {putchar('-');num=-num;}
    LL p = 0;
    if (num==0) _buf[p++] = 0;
    else while (num){_buf[p++]=num%10;num/=10;}
    for (LL i=p-1;i>=0;--i) putchar(_buf[i]+'0');
    if (flag==1) puts(""); else printf(" ");
}

const int N = 51234;
int n,m,cmd,l,r;
char s[N];

struct FenwickTree {
  int n;
  int C[N];

  void init(int _n) {n = _n; memset(C,0,sizeof C); }
  int lowbit(int x) {return x&(-x);}

  // 计算A[1]+A[2]+...+A[x] (x<=n)
  int sum(int x) {
    int ret = 0;
    while(x > 0) {
      ret += C[x]; x -= lowbit(x);
    }
    return ret;
  }

  // A[x] += d (1<=x<=n)
  void add(int x, int d) {
    while(x <= n) {
      C[x] += d; x += lowbit(x);
    }
  }
}ft;

void solve(){

    n = read();ft.init(n+1);
    m = read();
    clr(s,0);
    scanf("%s",s+1);

    for (int i=1;i<=n;++i){
        if (strncmp(s+i,"wbw",3)==0)
            ft.add(i,1);
    }
    while (m--){
        cmd = read();
        if (cmd){
            l = read()+1;
            char c = getchar();
            if (c!=s[l]){
                for (int i=-2;i<=0;++i){
                    if (strncmp(s+l+i,"wbw",3)==0)
                        ft.add(l+i,-1);
                    else {
                        char t = s[l];
                        s[l] = c;
                        if (strncmp(s+l+i,"wbw",3)==0)
                            ft.add(l+i,1);
                        s[l] = t;
                    }
                }
                s[l] = c;
            }
        }
        else{
            l = read()+1;
            r = read()+1;
            write(ft.sum(r-2)-ft.sum(l-1));
        }
    }
}

int  main(){
    int T = read(),cas = 1;
    while (T--){
        printf("Case %d:\n",cas++);
        solve();
    }
    return 0;
}

