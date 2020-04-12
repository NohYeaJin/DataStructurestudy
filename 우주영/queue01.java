import java.util.*;

public class queue01 { //백준 10845

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue<Integer> que = new LinkedList<>();
		Scanner sc1 = new Scanner(System.in);
		Scanner sc2 = new Scanner(System.in);
		
		int cnt = sc1.nextInt();
		int cmdb = 0; //변수만 선언하고 비워두기
		
		for(int i=0; i<cnt; i++) {
			String cmda = sc2.next();
			
			if(cmda.equals("push")) {
				cmdb = sc2.nextInt();
				que.add(cmdb);
			}
			else if(cmda.equals("pop")) {
				System.out.println(que.isEmpty()?-1:que.poll());
			}
			else if(cmda.equals("size")) {
				System.out.println(que.size());
			}
			else if(cmda.equals("empty")) {
				System.out.println(que.isEmpty()?1:0);
			}
			else if(cmda.equals("front")) {
				System.out.println(que.isEmpty()?-1:que.peek());
			}
			else if(cmda.equals("back")) {
				System.out.println(que.isEmpty()?-1:cmdb); 
			}
		}
	}

}
