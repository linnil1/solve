#include<bits/stdc++.h>
#define ll long long 
#define M 1000010
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

int a[M],b[M],al,bl;


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		int arr[n];
		FR(i,n)
			cin >> arr[i];
		al=bl=0;
		FR(i,n)
			FR(j,n)
				FR(k,n){
					a[al++]= arr[i]* arr[j]+arr[k] ;
					if(arr[i]!=0)
						b[bl++]= arr[i]*(arr[j]+arr[k]);
				}
		
		sort(a,a+al);
		sort(b,b+bl);
		int x=0,y=0;
		ll sum=0;
		while(x<al && y<bl){
			int k = MIN (a[x],b[y]);
			while(x<al && a[x]<k)
				++x;
			while(y<bl && b[y]<k)
				++y;
			int tx=0,ty=0;
			while(x<al && a[x]==k)
				++x,++tx;
			while(y<bl && b[y]==k)
				++y,++ty;
			sum += (ll)tx*ty;
		}
		cout << sum << "\n\n";
	};
}
	return 0;
};
/*






*/
