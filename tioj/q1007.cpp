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
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(cin >> n>> m){
		ll dp[2][n+2],sum=1,now=0;
		for(int j=0;j<=n;++j)
			dp[0][j]=dp[1][j]=0;
		dp[0][0]=1;
		FR(i,m){
			now^=1;
			for(int j=0;j<=n;++j)
				dp[now][j]=0;
			FRE(j,n)
				dp[now][j]+=dp[!now][j-1];
			sum=0;
			for(int j=0;j<=n;++j)
				sum+=dp[!now][j];
			dp[now][0]+= sum ;
		}
		/*for(int j=0;j<=n;++j)
			sum+=dp[now][j];*/
		cout << sum << endl;
	};
}
	return 0;
};
/*






*/
