const val mxn=200005;
var p=Array<Int> (mxn) {-1};
var s=Array<Int> (mxn) {-1};

fun make(n:Int)
{
    for(i in 0..n-1)
    {
        p[i]=i;
        s[i]=1;
    }
}

fun find(node:Int):Int
{
    var n=node;
    if(p[node]!=node)
    {
        n=find(p[node]);
    }
    return n;
}

fun join(x:Int ,y:Int):Boolean
{
    var x1=x;
    x1=find(x);
    var y1=y;
    y1=find(y);
    if(x1==y1) return false;
    if(s[x1]<s[y1]) x1 = y1.also { y1 = x1 }
    p[y1]=x1;
    s[x1]+=s[y1];
    return true;
}
