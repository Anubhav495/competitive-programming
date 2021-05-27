//**seive**//
const int mxn=1e6+2;
vector<int> is(mxn,true);
void seive()
{
    is[0]=is[1]=false;
    for(int i=1;i<mxn;i++)
    {
        for(int j=i*i;j<mxn;j+=i)
        {
            is[j]=false;
        }
    }
}

//**find inverse under non prime mod**//
void EE(int a, int b, int& x, int& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
}

int inverse(int a, int m)
{
    int x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}
