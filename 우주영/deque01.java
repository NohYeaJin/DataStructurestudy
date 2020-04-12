import java.util.LinkedList;
import java.util.Deque;
import java.util.Scanner;


public class deque01 { //백준 1021

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Deque<Integer> deq = new LinkedList<>();
		Scanner sc1 = new Scanner(System.in);
		Scanner sc2 = new Scanner(System.in);
		
		int count = sc1.nextInt();
		int cmdfront = 0; //새로운 숫자를 넣을 변수라 미리 선언
		int cmdback = 0; //마찬가지
		
		for(int i=0; i<count; i++) {
			String cmda = sc2.next();
			
			if(cmda.equals("push_front")) {
				cmdfront = sc2.nextInt();
				deq.addFirst(cmdfront);
			}
			if(cmda.equals("push_back")) {
				cmdback = sc2.nextInt();
				deq.add(cmdback);
			}
			else if(cmda.equals("pop_front")) {
				System.out.println(deq.isEmpty()?-1:deq.poll());
			}
			else if(cmda.equals("pop_back")) {
				System.out.println(deq.isEmpty()?-1:deq.pollLast());
			}
			else if(cmda.equals("size")) {
				System.out.println(deq.size());
			}
			else if(cmda.equals("empty")) {
				System.out.println(deq.isEmpty()?1:0);
			}
			else if(cmda.equals("front")) {
				System.out.println(deq.isEmpty()?-1:deq.peek());
			}
			else if(cmda.equals("back")) {
				System.out.println(deq.isEmpty()?-1:deq.peekLast()); //boolean 검사
			}
		}
	}

}
