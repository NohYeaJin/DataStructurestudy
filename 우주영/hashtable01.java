import java.util.*;

public class hashtable01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc1 = new Scanner(System.in);
		int count = sc1.nextInt();
		
		HashTable ht = new HashTable(count);
		
		for(int i=0; i<count; i++) {
			Scanner sc2 = new Scanner(System.in);
			String cmd = sc2.next();
			
			if(cmd.equals("i")) {
				int insert = sc2.nextInt();
				ht.put(insert);
			}
			else if(cmd.equals("p")) {
				StringBuilder sb = new StringBuilder();
				for(int j=0; j<count; j++) {
					if(ht.get(j) != null) {
						sb.append(ht.get(j)+" ");
					}
				}
				System.out.println(sb);
			}
		}
	}
	
}

class HashTable {
	LinkedList<Node>[] data;
	
	public HashTable(int size) { //해시테이블 생성
		this.data = new LinkedList[size];
	}
	
	int convertToIndex(int num) { //나머지 값을 인덱스값으로 변환
		return num % data.length;
	}
	
	void put(int value) {
		int index = convertToIndex(value);
		
		LinkedList<Node> list = data[index];
		
		if(list==null) {
			list = new LinkedList<Node>();
			data[index] = list;
		}
		
		list.addLast(new Node(index, value));
	}
	
	Node searchKey(LinkedList<Node> list, int key) {
		if(list==null) return null;
		
		for(Node node : list) {
			if(node.key == key) {
				return node;
			}
		}
		return null;
	}
	
	public String get(int key) {
		LinkedList<Node> list = data[key];
		Node node = searchKey(list, key);		
		
		return node == null ? null : Integer.toString(node.getValue());
	}
	
	class Node {
		int key;
		int value;
		
		public Node(int key, int value) {
			this.key = key;
			this.value = value;
		}
		
		public int getValue() {
			return this.value;
		}
		
		public void setValue(int value) {
			this.value = value;
		}
	}
}