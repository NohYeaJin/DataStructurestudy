import java.util.*;
public class stack02 { //น้มุ 10799น๘

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String pos;
		String prepos = "";
		
		int stick = 0;
		int stickSum = 0;
		
		Stack<String> stk = new Stack<String>();
		Scanner sc = new Scanner(System.in);
		String fullstick[] = sc.next().split("");
		
		for(int i=0; i<fullstick.length; i++) {
			stk.push(fullstick[i]);
		}
		
		for(int i=0; i<fullstick.length; i++) {
			pos = stk.pop();
			if(pos.equals(")")) {
				stick++;
				stickSum++;
			}
			else if(pos.equals("(")) {
				if(prepos.equals(")")) {
					stick--;
					stickSum = stickSum-1+stick; }
				else
					stick--;
			}
			prepos = pos;
		}
		System.out.println(stickSum);
	}
}
