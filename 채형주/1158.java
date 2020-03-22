package solution;
import java.util.*;


public class Solution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int n, k, it;
		n = scanner.nextInt();
		k = scanner.nextInt();
		//1 ~ n까지 담을 ArrayList 선언
		ArrayList<Integer> p = new ArrayList<Integer>();
		//iterator 시작
		it = k-1;

		for (int i = 0; i < n; i++) {
			p.add(i+1);
		}
		System.out.print("< ");
		while (true) {
			if(p.size() == 0) break; // 아무도 안 남았을 때 break
			if(it > p.size()) it %= p.size(); // iterator가 리스트어레이의 크기를 초과했을 때 조정
			System.out.print(p.get(it));
			if (p.size()!= 1) {
			System.out.print(", ");
			}
			p.remove(it); // 찾은 사람 제거
			// 다음 사람
			it += k-1;
			
					
			
			
		}
		System.out.print(">");

	}

}
