const int mxn=2e5+10;
vector<ll> tree(1<<19),lazy(1<<19),arr(mxn);
void updateRangeUtil(int si, int ss, int se, int us,int ue, ll diff) 
{
	if (lazy[si] != 0) { 
		tree[si] += lazy[si]; 
		if (ss != se) {
			lazy[si * 2 + 1] += lazy[si]; 
			lazy[si * 2 + 2] += lazy[si]; 
		} 
		lazy[si] = 0; 
	} 
	if (ss > se || ss > ue || se < us) 
		return; 
	if (ss >= us && se <= ue) { 
		tree[si] += diff; 
		if (ss != se) { 
			lazy[si * 2 + 1] += diff; 
			lazy[si * 2 + 2] += diff; 
		} 
		return; 
	}
	int mid = (ss + se) / 2; 
	updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff); 
	updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff); 
	tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]); 
} 
void updateRange(int n, int us, int ue, int diff) 
{ 
	updateRangeUtil(0, 0, n - 1, us, ue, diff); 
}
ll getmaxUtil(int ss, int se, int qs, int qe, int si) 
{ 
	if (lazy[si] != 0) { 
		tree[si] += lazy[si]; 
		if (ss != se) {  
			lazy[si * 2 + 1] += lazy[si]; 
			lazy[si * 2 + 2] += lazy[si]; 
		}
		lazy[si] = 0; 
	} 
	if (ss > se || ss > qe || se < qs) 
		return 0; 
    
	if (ss >= qs && se <= qe) 
		return tree[si]; 
    
	int mid = (ss + se) / 2; 
	return max(getmaxUtil(ss, mid, qs, qe, 2 * si + 1), 
			getmaxUtil(mid + 1, se, qs, qe, 2 * si + 2)); 
} 
ll getmax(int n, int qs, int qe) 
{
	return getmaxUtil(0, n - 1, qs, qe, 0); 
} 

void constructSTUtil(int ss, int se, int si) 
{ 
	if (ss > se) 
		return; 

	if (ss == se) { 
		tree[si] = arr[ss]; 
		return; 
	} 

	int mid = (ss + se) / 2; 
	constructSTUtil(ss, mid, si * 2 + 1); 
	constructSTUtil(mid + 1, se, si * 2 + 2); 

	tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]); 
}

void constructST(int n) 
{ 
	// Fill the allocated memory st 
	constructSTUtil(0, n-1, 0); 
} 

 //Driver code 
//int main() 
//{ 
	//int arr[] = { 1, 2, 3, 4, 5 }; 
	//int n = sizeof(arr) / sizeof(arr[0]); 

	 //Build segment tree from given array 
	//constructST(arr, n); 

	 //Add 4 to all nodes in index range [0, 3] 
	//updateRange(n, 0, 3, 4); 

	 //Print maximum element in index range [1, 4] 
	//cout << getSum(n, 1, 4); 

	//return 0; 
//} 

