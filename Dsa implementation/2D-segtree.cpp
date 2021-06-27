const int mxn2=4e5+2;
const int INF=1e15;
int n;
struct node
{
    ll s,m,lz=0,mini;
} st[10][1<<20];

void push(int node,int which) {
    st[which][node*2+1].s += st[which][node].lz;
    st[which][node*2+2].s += st[which][node].lz;
    st[which][node*2+1].m += st[which][node].lz;
    st[which][node*2+2].m += st[which][node].lz;
    st[which][node*2+1].mini += st[which][node].lz;
    st[which][node*2+2].mini += st[which][node].lz;
    st[which][node*2+1].lz += st[which][node].lz;
    st[which][node*2+2].lz += st[which][node].lz;
    st[which][node].lz = 0;
}

void rupdate(int l,int r,int val,int which,int l2=0,int r2=n-1,int ci=0)
{
    if(l>r) return ;
    if(l==l2&&r==r2)
    {
        st[which][ci].s+=val;
        st[which][ci].m+=val;
        st[which][ci].mini+=val;
        st[which][ci].lz+=val;
        return ;
    }
    push(ci,which);
    int mid=(l2+r2)/2;

    rupdate(l,min(r,mid),val,which,l2,mid,2*ci+1);
    rupdate(max(l,mid+1),r,val,which,mid+1,r2,2*ci+2);

    st[which][ci].s=(st[which][2*ci+1].s+st[which][2*ci+2].s);
    st[which][ci].m=max(st[which][2*ci+1].m,st[which][2*ci+2].m);
    st[which][ci].mini=min(st[which][2*ci+1].mini,st[which][2*ci+2].mini);
}

void update(int l,int r,int val,int which,int l2=0,int r2=n-1,int ci=0)
{
    if(l>r) return ;
    if(l==l2&&r==r2)
    {
        st[which][ci].s=val;
        st[which][ci].m=val;
        st[which][ci].mini=val;
        return ;
    }
    int mid=(l2+r2)/2;
    update(l,min(r,mid),val,which,l2,mid,2*ci+1);
    update(max(l,mid+1),r,val,which,mid+1,r2,2*ci+2);

    st[which][ci].s=(st[which][2*ci+1].s+st[which][2*ci+2].s);
    st[which][ci].m=max(st[which][2*ci+1].m,st[which][2*ci+2].m);
    st[which][ci].mini=min(st[which][2*ci+1].mini,st[which][2*ci+2].mini);
}

int query(int l1,int r1,int type,int which,int l2=0,int r2=n-1,int ci=0)
{
    if(l1<=l2&&r1>=r2)
    {
        if(type==1)
            return st[which][ci].s;
        else if(type==2)
            return st[which][ci].m;
        return st[which][ci].mini;
    }
    if(l2>r1||r2<l1)
    {
        return 0;
    }
    push(ci,which);
    int mid=(l2+r2)/2;
    if(type==1)
        return query(l1,r1,type,which,l2,mid,2*ci+1)+query(l1,r1,type,which,mid+1,r2,2*ci+2);
    else if(type==2)
        return max(query(l1,r1,type,which,l2,mid,2*ci+1),query(l1,r1,type,which,mid+1,r2,2*ci+2));
    return min(query(l1,r1,type,which,l2,mid,2*ci+1),query(l1,r1,type,which,mid+1,r2,2*ci+2));
}

void build(vector<int> &a) 
{
    fi(0,n)
    {
        update(i,i,a[i],0);
        update(i,i,a[i],1);
        update(i,i,a[i],2);
    }
}
