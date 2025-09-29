void simpleSort(float[] a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] < a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
}