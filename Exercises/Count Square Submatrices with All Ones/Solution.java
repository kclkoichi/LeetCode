// 1277
class Solution {
  public int countSquares(int[][] matrix) {
      int res = 0;
      for(int i = 0; i < matrix.length; i++) {
        for(int j = 0; j < matrix[0].length; j++) {
          res += countSquareFrom(i, j, matrix);
        }
      }
      return res;
  }

  public int countSquareFrom(int i, int j, int[][] matrix) {
    int res = 0;
    int side = 1;
    while(i + side <= matrix.length && j + side <= matrix[0].length) {
      boolean can = true;
      for(int m = i; m < i+side; m++) {
        for(int n = j; n < j+side; n++) {
          if(matrix[m][n] == 0) can = false;
          if(!can) break;
        }
        if(!can) break;
      }
      if(!can) break;
      // Everything was 1 in the square
      res++;
      side++;
    }
    return res;
  }
}