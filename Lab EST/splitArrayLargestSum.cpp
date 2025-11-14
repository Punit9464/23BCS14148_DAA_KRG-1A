#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int countArr(vector<int> &arr, int count) {
  int cnt = 1, arrCnt = 0, n = arr.size();

  for(int i = 0; i < n; i++) {
      if(arr[i] + arrCnt <= count) {
          arrCnt += arr[i];
      } else {
          arrCnt = arr[i];
          cnt++;
      }
  }

  return cnt;
}

int splitArray(vector<int>& nums, int k) {
  int n = nums.size();
  int low = *max_element(nums.begin(), nums.end());
  int high = accumulate(nums.begin(), nums.end(), 0);

  while(low <= high) {
      int mid = (low + high) / 2;
      int val = countArr(nums, mid);
      if(val <= k) high = mid-1;
      else low = mid+1;
  }

  return low;
}

int main() {
  vector<int> nums = { 7, 2, 5, 10, 8 };
  int k = 2;
  int ans = splitArray(nums, k):
  cout<<ans<<endl;
  return 0;
}
