import java.util.List;

class Solution {
    // Primes up to 1000
    List<Integer> primes = List.of(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997);

    // Not used now, just used once to generate
    void generatePrimes() {
        for(int i = 2; i <= 1000; i++) {
            boolean isPrime = true;
            for(int j = 2; j < i; j++) {
                if(i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) primes.add(i);
        }
    }

    int reduceMax(int number, int constraint) {
        int prev = number;
        for(int prime: primes) {
            if(number - prime > 0 && number - prime > constraint) {
                prev = number - prime;
            } else {
                return prev;
            }
        }

        System.out.println("Something went wrong");
        return -1; // Something went wrong
    }

    public boolean primeSubOperation(int[] nums) {
        nums[0] = reduceMax(nums[0], 0);
        for(int i = 1; i < nums.length; i++) {
            nums[i] = reduceMax(nums[i], nums[i-1]);
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
}
