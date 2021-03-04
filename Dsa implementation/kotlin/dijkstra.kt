adj = Array(n) { mutableListOf<Pair<Int,Int>>() }
for(i in 0..m-1)
{
    var(x,y,w)=readInts(3);
    x--;y--;
    adj[x].add(Pair(y,w));
    adj[y].add(Pair(x,w));
}
var d=mutableListOf<Pair<Int,Int>> ()
for(i in 0..n-1)
{
    d.add(Pair(INF,-1));
}
var d=Array(n) {Pair<Long,Int> (INF,-1)};
d[0]=Pair(0,-1);
val pq = PriorityQueue<Pair<Long, Int>> (compareBy {p -> p.first})
pq.add(Pair(0L,0))
while(!pq.isEmpty())
{
    val (dist,node) = pq.remove()
    for(x:Pair<Int,Int> in adj[node])
    {
        val (u,temp_d)=x
        var nxt_d=d[u].first
        if(nxt_d>dist+temp_d)
        {
            nxt_d=dist+temp_d
            d[u]=Pair(nxt_d,node)
            pq.add(Pair(nxt_d,u))
        }
    }
}
var ans=mutableListOf<Int> ()
if(d[n-1].first==INF)
{
    print("-1 ");
    return ;
}
var start=n-1;
while(start!=-1)
{
    ans.add(start)
    start=d[start].second;
}
ans=ans.asReversed()
for(x:Int in ans)
{
    print("${x+1} ")
}
