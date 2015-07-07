#include <bits/stdc++.h>
using namespace std;
int main(){
	srand((unsigned)time(NULL));
	char s[] = "wb"; 
	cout<<1<<endl;
	int n = rand()%10+1;
	int m = rand()%10+1;
	cout<<n<<endl;
	cout<<m<<endl;

	for (int i=0;i<n;++i) printf("%c",s[rand()%2]); cout<<endl;
	while (m--){
		int cmd = rand()%2;
		cout<<cmd<<endl;
		if (cmd){
			int x = rand()%n;		
			int w = rand()%2;
			printf("%d %c\n",x,s[w]);
		}else{
			int r = rand()%n;
			int l = rand()%n;
			if (l>r) swap(l,r);
			printf("%d %d\n",l,r);
		}
	}
	
	return 0;
}
