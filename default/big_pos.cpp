#define MM 1000000000 // every 9 digit in long long int 

class Big_pos{

#define ll long long 
#define pb push_back

private:
	std::vector<ll> v;

	void nozero(){// no head 0
		int len = v.size();
		for(;len>0&&v[len-1]==0;--len);
		v.resize(len);
	}

	int comp(Big_pos &a,Big_pos &b,int st=0){//compare from st position
		//if more digits
		if(a.size() < b.size()+st )
			return -1;
		if(a.size() > b.size()+st )
			return 1;
		// same digits comare from the top
		for(int i=0;i<b.size();++i)
			if(a.v[a.size()-1-i] < b.v[b.size()-1-i] )
				return -1;
			else if(a.v[a.size()-1-i] > b.v[b.size()-1-i] )
				return 1;
		return 0;
	}

	Big_pos minus(Big_pos a,Big_pos &b,int st=0){// a>=b
		if(comp(a,b,st) <0)
			puts("error");
		for(int i=0;i+st<a.size() ;++i){
		   ll y = i<b.size() ? b.v[i] : 0;
		   a.v[i+st]-=y;
			if(a.v[i+st]<0){
				a.v[i+st]+=MM;
				a.v[i+st+1]--;	
			}
		}
		a.nozero();
		return a;
	}

	Big_pos operator *(ll &a){
		Big_pos c;
		if(a)
			c.v.pb(a);
		return *this * c;
	}

	Big_pos div(Big_pos &a, Big_pos &b){ // tention: the value will be changed
		if(comp(a,b)<0)
			return Big_pos();//special for zero  it's quicker
		Big_pos c;
		c.v.resize(a.size()-b.size()+1);
		for(int i=a.size()-b.size();i>=0;--i){ // binary search 
			ll min=0,max=MM,mid;
			Big_pos tmp;
			while(min+1<max){
				mid = (min+max)>>1;
				tmp = b*mid;
				if( comp(a,tmp,i)<0)
					max = mid;
				else
					min = mid;
			}
			c.v[i]=min;
			tmp = b*min;
			a = minus(a,tmp,i);
//			std::cout << a << " " << b <<"\n";
		}
		a.nozero();
		c.nozero();
		return c;
	}

public:
	Big_pos(){
		v = std::vector<ll>();
	}

	Big_pos (std::string s){ // input a number 
		v = std::vector<ll>();
		for(int i=s.size()-1,now=MM;i>=0;--i,now*=10){
			if(now==MM){ // every MM a int
				now=1;
				v.pb(0);
			}
			v.back()+=now*(s[i]-'0');
		}
		nozero();
	}

	int size(){
		return v.size();
	}
	
/*	void print(){
		if(v.size()==0){
			printf("0");
			return ;
		}
		printf("%lld",v.back());
		for(int i=v.size()-2;i>=0;--i)
			printf("%08lld",v[i]);
	}
	
	bool IN(){
		std::string s;
		if(std::cin>>s){
			*this = Big_pos(s);
			return 1;
		}
		return 0;
	}
*/
	friend std::ostream& operator <<(std::ostream &out,Big_pos &a){
		if(a.size()==0){
			out<<"0";
			return out;
		}
		out << a.v.back();
		for(int i=a.size()-2;i>=0;--i){
			out.width(9);// every 9 digits
			out << std::setfill('0') << a.v[i] ;
		}
		return out;
	}

	friend std::istream& operator >>(std::istream &in,Big_pos &a){
		std::string s;
		in >> s;
		a = Big_pos(s);
		return in;
	}

		
	Big_pos operator + (Big_pos &b){
		int r=0;
		Big_pos c;
		for(int i=0;i<v.size()||i<b.size();++i){
			ll x = i<v.size() ? v[i] : 0,
			   y = i<b.size() ? b.v[i] : 0;
			c.v.pb(x+y+r);
			r=0;
			if(c.v.back()>=MM){
				r = 1;
				c.v.back()-=MM;
			}
		}
		if(r)
			c.v.pb(r);
		c.nozero();
		return c;
	}
				
	Big_pos operator * (Big_pos &b){
		Big_pos c;
		c.v.resize(v.size()+b.size()+2);
		for(int i=0;i<v.size();++i)
			for(int j=0;j<b.size();++j){
				auto r = c.v.begin()+(i+j) ;
			   	*r += v[i]*b.v[j];
				if(*r>=MM){
					*(r+1) += *r/MM;
					*r%=MM;
				}	
			}
		c.nozero();
		return c;
	}

//package
	Big_pos operator - (Big_pos &b){
		return minus(*this,b);
	}
	Big_pos operator / (Big_pos &b){
		Big_pos a = *this;
		return div(a,b);
	}
	Big_pos operator % (Big_pos &b){
		Big_pos a = *this;
		div(a,b);
		return a;
	}
	bool operator <(Big_pos &b){
		return comp(*this,b)<0;
	}

};

/*
int main(){
	Big_pos a,b;
	char c[100];
	while(std::cin>>a>>c>>b){
		Big_pos tmp;
		switch(c[0]){
			case '+':tmp = a+b;break;
			case '-':tmp = a-b;break;
			case '*':tmp = a*b;break;
			case '/':tmp = a/b;break;
			case '%':tmp = a%b;break;
		}
		std::cout << tmp <<"\n";
	}
	return 0;
}
*/

