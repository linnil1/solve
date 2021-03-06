//#include<bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
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

int need[25];
VMP v;

bool getneed(int c){
	BFR(i,v.size()){
		need[i] = MIN(v[i].sd,c/v[i].ft);
		c -= need[i]*v[i].ft;
	}
	if(c)
		FR(i,v.size())
			if(need[i]<v[i].sd){
				need[i]++;
				c-=v[i].ft;
				break;
			}
	return c<=0;		
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,c;
	while(~scanf("%d%d",&n,&c)){
		v = VMP();
		FR(i,n){
			int x,y;
			scanf("%d%d",&x,&y);
			v.pb(  mp(x,y) );
		}
		std::sort(ALL(v));
		

		int sum=0;
		while(getneed(c)){
			int t=INT_MAX;
			FR(i,n)
				if(need[i])
					t = MIN(t,v[i].sd/need[i]);
//			printf("%d ",t);
			FR(i,n)
				v[i].sd-= need[i]*t;
			sum += t;
		}
		
		printf("%d\n",sum);
		
	};
}
	return 0;
};
/*






*/
