// 796
class Solution {
  public boolean rotateString(String s, String goal) {
    String doubleS = s + s;
    for(int i = 0; i < s.length(); i++) {
      if(goal.equals(doubleS.substring(i, i + s.length()))) {
        return true;
      }
    }
    return false;
  }
}