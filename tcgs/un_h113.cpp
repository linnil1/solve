char need_time=1;
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
//#include<utility>
#include<limits.h>
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
#define VMP std::vector<MP>
#define MP std::pair<int,int>
#define IN(a) scanf("%d",&a)
#define INN(a,b) scanf("%d%d",&a,&b)

//using namespace std;

int fight(int a,int b){
	if(a<b)swap(a,b);
	std::set< MP > s;
	while(1){
		if(a==b)
			return 1;
		else if( s.count( mp(a,b) ))
			return 0;
		else
			s.insert( mp(a,b) );
		a = a-b;
		b+=b;
		if(a<b)swap(a,b);
	}
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);
/*	FOR(i,1,10000){
		FOR(j,1,i)
			if( __builtin_popcount((i/std::__gcd(i,j) + j/std::__gcd(i,j)))==1 )
				if(!fight(i,j))
					printf("%d %d\n",i,j);
//		puts("");
	}
	puts("zxc");
*/

	int n;
	while(~scanf("%d",&n)){
		int arr[n];
		FR(i,n)
			IN(arr[i]);
		int sum=0;
		FR(i,n)
			FR(j,i)
			{
				int k = std::__gcd(arr[i],arr[j]);
				if( __builtin_popcount(arr[i]/k + arr[j]/k)==1 )
					++sum;
			}
		printf("%d\n",sum);
				
		
		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/
