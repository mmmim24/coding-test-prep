import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int diff;
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            diff = target - nums[i];
            if (map.containsKey(diff) && map.get(diff) != i) {
                return new int[] {i, map.get(diff)};
            }
        }
        return new int[] {};
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n, target;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        target = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int[] result = solution.twoSum(nums, target);
        System.out.println(result[0] + " " + result[1]);
        scanner.close();
    }
}