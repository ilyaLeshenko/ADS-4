// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int i = 0;
    int j = len - 1;

    while (i < j) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            i++;
            continue;
        }
        if (j < len - 1 && arr[j] == arr[j + 1]) {
            j--;
            continue;
        }

        int sum = arr[i] + arr[j];
        if (sum == value) {
            if (arr[i] == arr[j]) {
                int n = j - i + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int left_count = 1;
            while (i + 1 < j && arr[i + 1] == arr[i]) {
                left_count++;
                i++;
            }
            int right_count = 1;
            while (i < j - 1 && arr[j - 1] == arr[j]) {
                right_count++;
                j--;
            }

            count += left_count * right_count;
            i++;
            j--;
        } else if (sum < value) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;

        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                right = mid - 1;
                if (arr[mid] == target) first = mid;
            } else {
                left = mid + 1;
            }
        }

        if (first == -1) continue;
        int last = first;
        left = first;
        right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
                if (arr[mid] == target) last = mid;
            } else {
                right = mid - 1;
            }
        }

        count += (last - first + 1);
    }
    return count;
}
