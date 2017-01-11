// Binary Search O(log n)
int binary_search(double a[], double val, int left, int right) {
	while (right >= left) {
		int mid = left + (right - left) / 2;
		if (val < a[mid])
			right = mid - 1;
		else if (val > a[mid])
			left = mid + 1;
		else return mid;
	}
	return -1; // val not found
}
