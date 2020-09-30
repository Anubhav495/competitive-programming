    double l=1.0,r=L;
		while((r-l)>0.000001)
		{
			double mid = (double)((l+r)/2);
			if(condition) r=mid;
			else l=mid;
    }
