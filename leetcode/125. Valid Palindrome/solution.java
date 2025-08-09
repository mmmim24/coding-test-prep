class Solution{
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while(i < j){
            if( Character.isLetterOrDigit(s.charAt(i)) && Character.isLetterOrDigit(s.charAt(j))) {
                if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) {
                    return false;
                }
                else{
                    i++;
                    j--;
                }
            } else {
                if(!Character.isLetterOrDigit(s.charAt(i))) i++;
                if(!Character.isLetterOrDigit(s.charAt(j))) j--;
            }
        }
        return true;
    }

    public static void main(String[] args){
        Solution solution = new Solution();
        System.out.println(solution.isPalindrome("A man, a plan, a canal: Panama")); // true
        System.out.println(solution.isPalindrome("race a car")); // false
        System.out.println(solution.isPalindrome("Was it a car or a cat I saw?")); // true
    }
}