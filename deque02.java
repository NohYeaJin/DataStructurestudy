import java.util.*;
public class deque02 {

	public static void main(String[] args) { //น้มุ 10866
		// TODO Auto-generated method stub
		Deque<Integer> que = new LinkedList<>();
		Scanner sc1 = new Scanner(System.in);
		Scanner sc2 = new Scanner(System.in);
		
		int resultCount = 0;
		int qsize = sc1.nextInt();
		for(int i=1; i<qsize+1; i++) {
			que.add(i);
		}
		
		int count = sc1.nextInt();
		int sch[] = new int[count];
		
		for(int i=0; i<count; i++) {
			sch[i] = sc2.nextInt();
			
			while(que.peek()!=sch[i]) {
				int pos = ((LinkedList<Integer>)que).indexOf(sch[i]);
				int size = que.size();
				int left = pos;
				int right = size-pos-1;
				
				if(left < right) {
					que.add(que.poll());
				}
				else {
					que.addFirst(que.pollLast());
				}
				resultCount++;
			}
			que.peek();
		}
		System.out.println(resultCount);
	}

}
