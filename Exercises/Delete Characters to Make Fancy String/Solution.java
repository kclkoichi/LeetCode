// 1957
class Solution {
  public String makeFancyString(String s) {
    if(s.length() < 3) return s;

    StringBuilder builder = new StringBuilder();

    for(int i = 0; i < s.length() - 2; i++) {
      if(s.charAt(i) == s.charAt(i+1) && s.charAt(i+1) == s.charAt(i+2)) {
        // skip
      } else {
        builder.append(s.charAt(i));
      }
    }
    builder.append(s.charAt(s.length() - 2));
    builder.append(s.charAt(s.length() - 1));
    return builder.toString();
  }
}