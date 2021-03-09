lateinit var tree: Array<Int>
fun update(index:Int,va:Int,l2:Int,r2:Int,ci:Int)
{
//    l2=0,r2=n-1,ci=0
    if(l2==r2)
    {
        tree[ci]+=va;
        return ;
    }
    var mid=(l2+r2)/2;
    if(index<=mid)
    {
        update(index,va,l2,mid,2*ci+1);
    }
    else
    {
        update(index,va,mid+1,r2,2*ci+2);
    }
    tree[ci]=max(tree[2*ci+1],tree[2*ci+2]);
}
fun query(l1:Int,r1:Int,l2:Int,r2:Int,ci:Int):Int
{
    if(l2>=l1&&r2<=r1)
    {
        return tree[ci];
    }
    if(l2>r1||r2<l1)
    {
        return 0;
    }
    var mid=(l2+r2)/2;
    return max(query(l1,r1,l2,mid,2*ci+1),query(l1,r1,mid+1,r2,2*ci+2));
}

//init
tree=Array<Int> (5*n+100) {0};
update(l,value,0,n-1,0);
query(l,r,0,n-1,0);
