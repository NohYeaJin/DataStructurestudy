import java.util.*;
public class LinkedLlist01 { // 백준 1158번

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CLinkedList CLL = new CLinkedList();
		StringBuilder sb = new StringBuilder("<");
		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt();
		int jump = sc.nextInt();
		for(int i = 1; i<count+1; i++) {
			CLL.firstNodeInsert(Integer.toString(i));
		}
		String solution[] = new String[count];
		
		if(jump == 1) {
			for(int i=1; i<count; i++) {
				sb.append(i);
				sb.append(", ");
			}
			sb.append(count);
			sb.append(">");
		}
		
		else {
			int key = 0;
			for(int i=0; i<count; i++) {
				key = key+jump-1;
				if(key>count) key-=count; 
				String Skey = Integer.toString(key);
				
				int j = 1;
				while (j<jump) {
					key+=1;
					if(key>count) key-=count;
					Skey = Integer.toString(key);
					if(CLL.isNodeNull(Skey) == true) {
						j+=1;
					}
				}
				
				ListNode delNode = CLL.searchNode(Skey);
				CLL.deleteNode(delNode);
				solution[i] = Skey;
			}
			
			for(int i=0; i<count-1; i++) {
				sb.append(solution[i]);
				sb.append(", ");
			}
			sb.append(solution[count-1]);
			sb.append(">");
		}
		System.out.println(sb.toString());
	}
}

class ListNode {
	String data;
	ListNode next;
	
	public ListNode() {
		this.data = null;
		this.next = null;
	}
	
	public ListNode(String data) {
		this.data = data;
		this.next = null;
	}
	
	public ListNode(String data, ListNode next) {
		this.data = data;
		this.next = next;
	}
	
	public String getData() {
		return this.data; //리스트 전체 출력
	}
}

class CLinkedList {
	private ListNode head;
	
	public CLinkedList() {
		this.head = null;
	}
	
	public void firstNodeInsert(String data) {
		ListNode insertNode = new ListNode(data);
		if(this.head == null) {
			head=insertNode;
			insertNode.next = insertNode;
		}
		else {
			ListNode temp = head;
			insertNode.next = head;
			while(temp.next != head) {
				temp = temp.next;
			}
			temp.next = insertNode;
			head = insertNode;
		}
	}
	
	public void middleNodeInsert(String data, ListNode pre) {
		ListNode insertNode = new ListNode(data);
		//head is null
		if(head == null){
			head = insertNode;
			insertNode.next = insertNode;
		}else{
			ListNode temp = head;
			//middle node insert
			while(temp.next !=head){
				if(pre == temp){
					insertNode.next=pre.next;
					pre.next = insertNode;
					return;
				}else{
					temp = temp.next;
				}
			}
			//last node insert
			if(temp==pre){
				insertNode.next = pre.next;
				pre.next = insertNode;
				return;
			}else{
				//not exist node
//				System.out.println("pre 노드가 존재하지 않습니다.");
			}
		}
	}
	
	public void deleteNode(ListNode delNode) {
		ListNode temp = head;
		//FirstList delete
		if(temp == delNode) {
			ListNode headNode = head;
			head = headNode.next;
			while(temp.next != headNode ) {
				temp = temp.next;
			}
			temp.next = head;
		}
		else {
			//MiddleList delete
			ListNode preNode = temp;
			while(temp.next != head) {
				if(temp.next == delNode) {
					temp.next = delNode.next;
					delNode.next = null;
					return;
				}
				else {
					preNode = temp;
					temp = temp.next;
				}
			}
			if(temp == delNode) {
				//LastNode delete
				preNode.next = head;
				delNode.next = null;
			}
			else {
				//노드 없음
//				System.out.println("해당 노드가 없음");
				return;
			}
		}
	}
	
	public ListNode searchNode(String data) {
		ListNode searchNode = new ListNode();
		searchNode = head;
		
		//Middle
		while(searchNode.next != head) {
			if(searchNode.getData().equals(data)) {
				return searchNode;
			} else { searchNode = searchNode.next; }
		}
		
		//Last
		if(searchNode.getData().equals(data)) {
			return searchNode; }
		else { 
//			System.out.println("찾는 데이터 없음");
			return null;
		}
	}
	
	public Boolean isNodeNull(String data) {
		ListNode searchNode = new ListNode();
		searchNode = head;
		
		//Middle
		while(searchNode.next != head) {
			if(searchNode.getData().equals(data)) {
				return false;
			} else { searchNode = searchNode.next; }
		}
		
		//Last
		if(searchNode.getData().equals(data)) {
			return false; }
		else { 
//			System.out.println("찾는 데이터 없음");
			return true;
		}
	}
}
