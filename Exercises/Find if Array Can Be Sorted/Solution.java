import java.util.ArrayList;
import java.util.Collections;

class Solution {
  public int getSetBits(int i) {
    int count = 0;
    while(i != 0) {
      if(i%2 == 1) {
        count++;
        i--;
      }
      i /= 2;
    }
    return count;
  }

  public boolean canSortArray(int[] nums) {
    ArrayList<ArrayList<Integer>> groups = new ArrayList<>();

    int curBits = getSetBits(nums[0]);
    ArrayList<Integer> curGroup = new ArrayList<>();
    curGroup.add(nums[0]);
    for(int i = 1; i < nums.length; i++) {
      if(curBits == getSetBits(nums[i])) {
        curGroup.add(nums[i]);
      } else {
        groups.add(curGroup);
        curBits = getSetBits(nums[i]);
        curGroup = new ArrayList<>();
        curGroup.add(nums[i]);
      }
    }
    groups.add(curGroup);

    ArrayList<Integer> maxes = new ArrayList<>();
    ArrayList<Integer> mins = new ArrayList<>();
    for(ArrayList<Integer> group: groups) {
      maxes.add(Collections.max(group));
      mins.add(Collections.min(group));
    }

    for(int i = 1; i < maxes.size(); i++) {
      if(maxes.get(i-1) > mins.get(i)) return false;
    }

    return true;
  }

}