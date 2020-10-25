const int mod=1e9+7;
const int mxn=1e6+3;

ll binpow(ll a,ll b)
{
	ll res=1; 
	while(b)
	{
		if(b&1){
			res=((res%mod)*(a%mod))%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b=b>>1;
	}
	return res%mod;
}

vector<ll> fact(mxn),inv(mxn);
void facto()
{
	fact[0]=fact[1]=1;
	fi(2,mxn)
	{
		fact[i]=(fact[i-1]*i)%mod;
		//assert(fact[i]>=0&&fact[i]<=mod);
	}
	inv[0]=inv[1]=1;
	fi(2,mxn)
	{
		inv[i]=binpow(fact[i],mod-2)%mod;
		//assert(inv[i]>=0&&inv[i]<=mod);
	}	
}
 
ll ncr(ll a,ll b)
{
	//assert(a-b>=0);
	if(b > a || a < 0 || b < 0)return 0;
	return (((fact[a]*inv[b])%mod)*inv[a-b]%mod)%mod;
}
