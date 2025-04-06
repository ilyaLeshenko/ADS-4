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
  int j = len - 1;
  for (int i = 0; i < j; ) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      i++;
      continue;
    }
    
    while (i < j) {
      int sum = arr[i] + arr[j];
      if (sum == value) {
        int right_val = arr[j];
        int right_count = 1;
        j--;
        while (i < j && arr[j] == right_val) {
          right_count++;
          j--;
        }
        count += right_count;
      } else if (sum < value) {
        i++;
      } else {
        j--;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        count++;
        int j = mid - 1;
        while (j >= left && arr[j] == target) {
          count++;
          j--;
        }
        j = mid + 1;
        while (j <= right && arr[j] == target) {
          count++;
          j++;
        }
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}
