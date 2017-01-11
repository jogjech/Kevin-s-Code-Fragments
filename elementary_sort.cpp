// Bubble Sort(non-adaptive)
void bubble(item a[], int left, int right) {
	for (int i = left; i < right - 1; ++i) {
		for (int j = right - 1; j > i; j--) {
			compswap(a[j - 1], a[j]);
		}
	}
}

// Bubble Sort(adaptive)
void bubble(item a[], int left, int right) {
	for (int i = left; i < right - 1; ++i)
	{
		bool swapped = false;
		for (int j = right - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swapped = true;
				swap(a[j - 1], a[j]);
			}
		}
		if (!swapped)
			break;
	}
}

// Selection Sort(adaptive)
void selection(Item a[], int left, int right) {
	for (int i = left; i < right - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < right; ++j) {
			if (a[j] < a[min])
				min = j;
		}
		if (min != i) swap(a[i], a[min]);
	}
}

// Insertion Sort(adaptive)
void insertion(Item a[], int left, int right) {
	for (int i = right - 1; i > left; i--)
		compswap(a[i - 1], a[i]); // find min item put in a[left]

	for (int i = left + 2; i < right; i++) {
		Item v = a[i]; int j = i;
		while (v < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}

// Bucket(Bin) Sort for small universes
void binsort(vector<size_t> &A) {
	vector<vector<size_t>> B(MAX); // bins
	for (auto a : A)
		B[a].push_back(a);
	size_t current = 0;
	for (size_t i = 0; i < MAX; ++i)
	{
		for (auto item : B[i])
			A[current++] = item;
	} // for
} // binsort

// Counting Sort
void counting_sort(vector<size_t> &A) {
	vector<size_t> B(A.size()), C(MAX);
	for (auto a : A)
		++C[a];
	for (size_t i = 1; i <= MAX; ++i)
		C[i] += C[i - 1];
	for (auto a : A) {
		B[C[a] - 1] = a;
		--C[a];
	} // for
	A = B;
} // counting_sort()

void in_place_counting_sort(vector<size_t> &A) {
	vector<size_t> C(MAX + 1);
	for (auto a : A)
		++C[a];
	int current = 0;
	for (size_t i = 0; i < MAX; ++i)
		for (size_t j = 0; j < C[i]; ++j)
			A[current++] = i;
} // in_place_counting_sort()


