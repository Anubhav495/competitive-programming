fun lis(a:Vector<Int>):Vector<Int>{
    var n=a.size
    val INF=1e9.toInt()+7;
    var d=Array<Int> (n+1){INF};
    var index=Array<Int> (n+1){-1};
    d[0]=-INF;
    for(i in 0..n-1)
    {
        var lo=0;
        var hi=n;
        var take=0;
        //upper bound
        while(lo<=hi)
        {
            var mid=(lo+hi)/2;
            if(d[mid]<=a[i])
            {
                take=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        take++;
        if(take<=n&&d[take-1]<a[i]&&a[i]<d[take])
        {
            d[take]=a[i];
            index[take]=i;
        }
    }
    var ans=0;
    for(i in 0..n)
    {
        if(d[i]<INF)
        {
            ans=i;
        }
    }
//    return ans;

    var recover=Vector<Int> ();
    var len=ans;
    while(len>=1)
    {
        recover.add(index[len]);
        len--;
    }
    recover.reverse();
    return recover;

}
