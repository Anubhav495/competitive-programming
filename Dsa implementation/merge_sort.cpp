// can do all pair finding problems
vector<int> a;
ll count=0;
ll merge(ll low,ll mid,ll high)
{
    ll count=0;
    ll j=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(j<=high&&a[i]>(ll)2*a[j])
        {
            j++;
        }
        count+=(j-mid-1);
    }
    vector<ll> temp;
    ll left=low,right=mid+1;
    while(left<=mid&&right<=high)
    {
        if(a[left]<=a[right])
        {
            temp.push_back(a[left++]);
        }
        else
        {
            temp.push_back(a[right++]);
        }
    }
    while(left<=mid)
    {
        temp.push_back(a[left++]);
    }
    while(right<=high)
    {
        temp.push_back(a[right++]);
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=temp[i-low];
    }
    return count;
}
int mergesort(ll low,ll high)
{
    if(low>=high) return 0;
    ll mid=(low+high)/2;
    ll inv=mergesort(low,mid);
    inv+=mergesort(mid+1,high);
    inv+=merge(low,mid,high);
    return inv;
}
