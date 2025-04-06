// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int end = len - 1;
  while (end > 0) {
    if (arr[end] > value) {
      end--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = end; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}
int Step(int* arr, int left, int right, int value) {
  int first = -1;
  int mleft = left, mright = right;
  while (mleft <= mright) {
    int mid = mleft + (mright - mleft) / 2;
    if (arr[mid] >= value) {
      mright = mid - 1;
      if (arr[mid] == value) first = mid;
    } else {
      mleft = mid + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  mleft = first;
  mright = right;
  while (mleft <= mright) {
    int mid = mleft + (mright - mleft) / 2;
    if (arr[mid] <= value) {
      mleft = mid + 1;
      if (arr[mid] == value) last = mid;
    } else {
      mright = mid - 1;
    }
  }
  return last - first + 1;
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    count += Step(arr, i + 1, len - 1, value - arr[i]);
  }
  return count;
}
