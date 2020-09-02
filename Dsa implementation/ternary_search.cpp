    
    auto f=[&](double mid)
    {
    
    
    };
    double eps=1e-9;
		double l=0,r=1e9+1;
		while(r-l>=eps)
		{
			double m1=l+(r-l)/3;
			double m2=r-(r-l)/3;
			double f1=f(m1);
			double f2=f(m2);
			if(f1<f2)
			{
				//l=m1;
				r=m2;
			}
			else
			{
				//r=m2;
				l=m1;
			}
		}
		ll ans=0;
		if((ll)(f(l)*10)%10<5)
		{
			ans=(ll)f(l);
		}
		else
		{
			ans=(ll)f(l)+1;
		}
