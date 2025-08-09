import java.util.Stack;
class Solution{
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if(st.empty()) {
                st.push(s.charAt(i));
            } else {
                char top = st.peek();
                if ((top == '(' && s.charAt(i) == ')') ||
                    (top == '{' && s.charAt(i) == '}') ||
                    (top == '[' && s.charAt(i) == ']')) {
                    st.pop();
                } else {
                    st.push(s.charAt(i));
                }
            }
        }
        return st.empty();
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isValid("()"));
        System.out.println(solution.isValid("()[]{}"));
        System.out.println(solution.isValid("(]"));
        System.out.println(solution.isValid("([)]"));
        System.out.println(solution.isValid("{[]}"));
    }
}