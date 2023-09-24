class Solution {
public:
  int mySqrt(int x) {
    if(x==1) return 1;
    int l = 0;
    int r = x;
    while(l+1<r) {
      int mid = (l + r)/2;
      long long pow = (long long)mid*mid;
      if(pow == x) return mid;
      if(pow > x) r = mid;
      if(pow < x) l = mid;
    }
    return l;
  }
};