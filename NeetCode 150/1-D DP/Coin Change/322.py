class Solution(object):
    # def recurse(self, count, coins, remainder):
    #     if remainder == 0:
    #         return count
    #     if remainder < 0:
    #         return -1
    #     if (len(coins) == 0):
    #         return -1
    #     with_largest_coin = self.recurse(count+1, coins, remainder-coins[len(coins)-1])
    #     without_largest_coin = self.recurse(count, coins[:-1], remainder)

    #     if with_largest_coin != -1 and without_largest_coin != -1:
    #         return min(with_largest_coin,without_largest_coin)
    #     elif (with_largest_coin != -1):
    #         return with_largest_coin
    #     else:
    #         return without_largest_coin

    def coinChange(self, coins, amount):
      """
      :type coins: List[int]
      :type amount: int
      :rtype: int
      """
      solution, found = self.myCoinChange(self, coins, amount, False)
      if found:
        return solution
      else:
        return -1
        
    def myCoinChange(self, coins, amount, found):
      if amount == 0:
        found = True
        return 1, found
      elif amount < 0 or coins.size() == 0:
        return -1, found
      else:
        return (self.myCoinChange(coins, amount-coins(coins.size()-1), found) + self.myCoinChange(coins[:-1], amount, found)), found
        

        

    

    
        