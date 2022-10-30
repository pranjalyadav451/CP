int checkvalid(int arr[], int n) {
    int mx_ele = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1] or arr[i] > mx_ele) {
            mx_ele = arr[i];
        }
        else {
            return 0;
        }
    }
    return 1;
}