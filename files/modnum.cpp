const int mod=1e9+7;

int binpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=(res*a)%mod;
		}
		a=(a*a)%mod;
		b=b>>1;
	}
	return res%mod;
}

int add(int a,int b)
{
	return (a+b)%mod;
}

int mul(int a,int b)
{
	return (a*b)%mod;
}

int sub(int a,int b)
{
	int res=a-b;
	if(res<0)
	{
		res+=mod;
	}
	res%=mod;
	return res;
}

int div(int a,int b)
{
	int inv_b=binpow(b,mod-2);
	return (a*inv_b)%mod;
}
