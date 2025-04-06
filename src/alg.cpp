// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
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
      int left_val = arr[i];
      int left_count = 1;
      while (i + 1 < j && arr[i + 1] == left_val) {
        left_count++;
        i++;
      }

      int right_val = arr[j];
      int right_count = 1;
      while (i < j - 1 && arr[j - 1] == right_val) {
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

int findFirst(int *arr, int left, int right, int target) {
    int first = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            if (arr[mid] == target) first = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return first;
}

int findLast(int *arr, int left, int right, int target) {
    int last = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            if (arr[mid] == target) last = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        if (i < len - 1 && target < arr[i + 1]) continue;
        int first = findFirst(arr, i + 1, len - 1, target);
        if (first == -1) continue;
        int last = findLast(arr, first, len - 1, target);
        count += (last - first + 1);
    }
    return count;
}
