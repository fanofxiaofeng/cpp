import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
		String rubbish = in.nextLine();
        for(int i = 0;i < n;i++){
            String s = in.nextLine();
            process(s);
        }
    }

    private static void process(String s){
		Stack<Character> stack = new Stack<Character>();
		for(int i = 0;i < s.length();i++){
			if(stack.empty() || !match(stack.peek(), s.charAt(i)))
				stack.push(s.charAt(i));
			else
				stack.pop();
		}
		
		if(stack.empty())
			System.out.println("Yes");
		else
			System.out.println("No");
    }
	
	private static boolean match(char l, char r){
		if(l == '(' && r == ')')
			return true;
		if(l == '[' && r == ']')
			return true;
		return false;
	}
}
