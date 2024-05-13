void bubble_sort(int a[], int n) {
	int temp;
	for (int j = n - 1; j >= 1; j--) {
		for (int k = 0; k < j; k++) {
			if (a[k] > a[k + 1]) {
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}
}