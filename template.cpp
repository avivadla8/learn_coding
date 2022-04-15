#include <bits/stdc++.h>
using namespace std;

#define cnd(c, a, b) (c ? a : b);
#define fl(x,y,z) for(int x=y;x<z;x++)
#define fe(x,y,z) for(int x=y;x<=z;x++)
#define fge(x,y,z) for(int x=y;x>=z;x--)

#define debug(x) std::cerr << #x << " --> " << x << "\n";
#define fastIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define pb push_back
#define pob pop_back
 
#define ln '\n'
typedef long long int ll;

ll mod=1e9+7;

class Cmp
{
public:
    bool operator() (pair<ll, ll> a, pair<ll, ll> b)
    {
		if(a.first==b.first) {
			return a.second>b.second;
		}
		return a.first>b.first;
    }
};

ll mod_pow(ll a, ll b) {
	ll ans = 1;
	while(b>0) {
		if(b%2) {
			ans = ((ans%mod)*(a%mod))%mod;
		}
		a = ((a%mod)*(a%mod))%mod;
		b /= 2;
	}
	return (ans+mod)%mod;
}

ll mod_div(ll a, ll b) {
	ll ans = ((a%mod)*(mod_pow(b, mod-2)%mod))%mod;
	return (ans+mod)%mod;
}

void decrypt() {
}

int main() {
    fastIO
    int t = 1;
    // cin >> t;
    fl(i,0,t) {
    	// cout << "Case #"<< i+1 <<": ";
    	decrypt();
    }
    return 0;
}