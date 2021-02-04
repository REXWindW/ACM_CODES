
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
typedef long long LL;
 
void exgcd(LL a, LL b, LL& x, LL& y, LL& c) {
    if(!b) {y = 0; x = 1; c = a; return;}
    exgcd(b,a%b,y,x,c); y -= a/b*x;
}
  
int main() {
	LL n,p,w,d;
	cin >> n >> p >> w >> d;
	// wx+dy = gcd w,d
	LL x,y,c;
	exgcd(w,d,x,y,c);
    cout<<"gcdd"<<c<<endl;
	LL v1 = p/w,v2 = 0,m = p%w;
	v2 = m/d; m = m%d;
//cout << x << " " <<y<<"\n";
	if (m%c == 0) {
		LL t = m/c;
		v1 += t*x;
		v2 += t*y;
		LL t1 = w/c,t2 = d/c;
		// +t1 -t2
		while (v1 < 0) {
			v1 += t2;
			v2 -= t1;
			if (v2 < 0) {
				puts("-1");
				return 0;
			}
		}
		while (v2 < 0) {
			v1 -= t2;
			v2 += t1;
			if (v1 < 0) {
				puts("-1");
				return 0;
			}
		}
		while (n-v1-v2 < 0) {
			if (t1 > t2) {
				v1 += t2;
			    v2 -= t1;
			    if (v2 < 0) {
				  puts("-1");
				  return 0;
			    }
			} else if (t1 < t2) {
				v1 -= t2;
			    v2 += t1;
			    if (v1 < 0) {
			 	  puts("-1");
				  return 0;
			    }
			} else {
				puts("-1");
				return 0;
			}
		}
		if (v1>=0 && v2>=0 && n-v1-v2>=0) {
			cout << v1 << " " << v2 << " " << n-v1-v2 << "\n";
			return 0;
		}
	}
	puts("-1");
    return 0;
}