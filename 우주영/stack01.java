import java.util.*;

public class stack01 { //백준 10828번

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack<Integer> stk = new Stack<Integer>();
		Scanner sc1 = new Scanner(System.in);
		Scanner sc2 = new Scanner(System.in);
		
		int cnt = sc1.nextInt();
		int cmdb = 0; //변수만 선언하고 비워두기
		
		for(int i=0; i<cnt; i++) {
			String cmda = sc2.next();
			
			if(cmda.equals("push")) {
				cmdb = sc2.nextInt();
				stk.add(cmdb);
			}
			else if(cmda.equals("pop")) {
				System.out.println(stk.isEmpty()?-1:stk.pop());
			}
			else if(cmda.equals("size")) {
				System.out.println(stk.size());
			}
			else if(cmda.equals("empty")) {
				System.out.println(stk.isEmpty()?1:0);
			}
			else if(cmda.equals("top")) {
				System.out.println(stk.isEmpty()?-1:stk.peek());
			}
		}
	}

}
