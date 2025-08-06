import java.util.Set;
import java.util.HashSet;
import java.util.Scanner;
class Solution {
    public boolean hasDuplicate(int[] nums) {
    Set<Integer> uniq = new HashSet<>();
        for (int num : nums) {
         uniq.add(num);
        }       
        return uniq.size() != nums.length;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        boolean result = solution.hasDuplicate(nums);
        System.out.println(result);
        scanner.close();
    }
}