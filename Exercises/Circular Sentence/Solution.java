// 2490
class Solution {
  public boolean isCircularSentence(String sentence) {
    String[] words = sentence.split(" ");
    for(int i = 1; i < words.length; i++) {
      if(words[i-1].charAt(words[i-1].length() - 1) != words[i].charAt(0)) return false;
    }
    return words[words.length-1].charAt(words[words.length-1].length() - 1) == words[0].charAt(0);
  }
}