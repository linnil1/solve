#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>

using std::cin;using std::cout;using std::string;
using std::sort;using std::endl;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MANN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;


int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;scanf("%d",&times); while(times--)
{	
	int n;
	scanf("%d",&n);
	{
		ll sum=0;
		int now,here=0;
		FR(i,n)
		{
			scanf("%d",&now);
			if(now > here)
				sum += now-here;
			here = now;
		}
		printf("%lld\n",sum);
	};
}
	return 0;
};
/*






*/
