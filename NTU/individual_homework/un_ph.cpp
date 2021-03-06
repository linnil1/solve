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
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
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

int pos(int *arr,int &n,int& m,int want){
	int min=m ,max = n ,mid;
	while(min+1<max){
		mid = (min+max)>>1;
		if(arr[mid]<want)
			min = mid ;
		else
			max = mid;
	}
	return min-m;
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		ARR(arr,n)cin >> arr[i];
		int sum=0;
		FR(i,n)
			FOR(j,i+1,n)
				if(std::__gcd(arr[i],arr[j])==1){
					ll now=  (ll)arr[i]*arr[i] + (ll)arr[j]*arr[j];
					ll t = (ll)sqrt(now);
					sum += now==t*t;
				}
		cout << sum << endl;
		
	};
}
	return 0;
};
/*






*/
