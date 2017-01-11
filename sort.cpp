// Quicksort: O(1) additional memory, O(n^2) worst case, O(nlog n) average
void quicksort(int a[], int left, int right) {
	if (left >= right)
		return;
	int pivot = partition(a, left, right);
	quicksort(a, left, pivot);
	quicksort(a, pivot + 1, right);
}

// Simple Partition
int partition(int a[], int left, int right) {
	int pivot == --right;
	while (true) {
		while (a[left] < a[pivot])
			++left;
		while (a[right - 1] >= a[pivot] && left < right)
			--right;
		if (left >= right)
			break;
		swap(a[left], a[right - 1]);
	}
	swap(a[left], a[pivot]);
	return left;
}

// Another Partition
int partition(int a[], int left, int right) {
	int pivot = left + (right - left) / 2; // pivot is middle
	swap(a[pivot], a[--right]); // swap with right
	pivot = right; // pivot is right
	while (true) {
		while (a[left] < a[pivot])
			++left;
		while (a[right - 1] >= a[pivot] && left < right)
			--right;
		if (left >= right)
			break;
		swap(a[left], a[right - 1]);
	}
	swap(a[left], a[pivot]);
	return left;
}

// Merge Sort
void mergeAB(Item c[], Item a[], int size_a, Item b[], int size_b) {
	for (int i = 0, j = 0, k = 0; k < size_a + size_b; k++) {
		if (i == size_a)
			c[k] = b[j++];
		else if (j == size_b)
			c[k] = a[i++];
		else
			c[k] = (a[i] <= b[j]) ? a[i++] : b[j++];
	} // for
} // mergeAB()

void mergesort(Item a[], int left, int right) {
	if (right <= left)
		return;
	int mid = (right + left) / 2;
	mergesort(a, left, mid); // [left, mid]
	mergesort(a, mid + 1, right); // [mid + 1, right]
	merge(a, left, mid, right);
} // mergesort()

void merge(Item a[], int left, int mid, int right) {
	int size = right -left + 1;
	vector<Item> c(size);
	for (int i = left, j = mid + 1, k = 0; k < size; ++k) {
		if (i > mid)
			c[k] = a[j++];
		else if (j > right)
			c[k] = a[i++];
		else
			c[k] = (a[i] <= a[j]) ? a[i++] : a[j++];
	} // while

	copy(c.begin(), c.end(), &a[left]);
} // merge()


