int on(int x, int b) {
	// returns number of numbers having bth bit on from 1 to x
	int first = (1 << b);

	if (first > x) return 0;

	int d = x - first + 1;

	int ans = first * (d / (2 * first)) + min(first, (d % (2 * first)));

	return ans;
}
