import java.util.Scanner;

class Solution{

    public int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        while (carry != 0) {
            a = sum;
            b = carry;
            sum = a ^ b;
            carry = (a & b) << 1;
        }
        return sum;
    }

    public static void main(String[] args){
        Solution solution = new Solution();
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        System.out.println(solution.getSum(a, b));
        scanner.close();
    }
}