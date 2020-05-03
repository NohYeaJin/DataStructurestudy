import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import  java.util.Queue;
import java.util.Scanner;

class Node{
    int data;
    Node p = null;
    Node left = null;
    Node right = null;
    Node(int data){
        this.data = data;
    }
}
class BinarySearchTree{
    Node root =  null;


    Node findNode(int key) {
        // 트리가 비었을 때
        if (root == null) return null;

        Node focusNode = root;

        while (focusNode.data != key) {
            if (key < focusNode.data) {              // 현재노드보다 작으면
                focusNode = focusNode.left;    // 왼쪽으로
            } else {                                // 크면
                focusNode = focusNode.right;   // 오른쪽으로
            }

            // 찾으려는 노드가 없을 때
            if (focusNode == null)
                return null;
        }

        return focusNode;
    }
    void addNode(int key) {
        if (findNode(key) != null) return;  // 이미 존재하면 그냥 리턴

        Node newNode = new Node(key);

        if (root == null) {
            root = newNode; // 트리가 비어있으면 root 에 삽입
        } else {
            Node focusNode = root;  //  탐색용 노드
            Node parent;            //  탐색용 노드의 부모 노드

            while(true) {
                parent = focusNode; //  이동

                if (key < parent.data) {             //  삽입하려는 키가 현재 노드보다 작으면
                    focusNode = parent.left;   //  왼쪽으로 이동

                    if (focusNode == null) {        //  왼쪽 노드가 비어있으면
                        parent.left = newNode; //  왼쪽 노드에 삽입
                        return;
                    }
                } else {                            //  삽입하려는 키가 현재 노드와 같거나 크다면
                    focusNode = parent.right;  //  오른쪽으로 이동

                    if (focusNode == null) {        //  오른쪽 노드가 비어있으면
                        parent.right = newNode;//  오른쪽 노드에 삽입
                        return;
                    }
                }
            }
        }
    }
    void postOrderTraverse(Node focusNode) {
        if (focusNode != null) {
            postOrderTraverse(focusNode.left);
            postOrderTraverse(focusNode.right);
            System.out.print(focusNode.data + " ");
        }
    }
}

public class Main{
    public  static StringBuilder sb = new StringBuilder();
    public static void main(String[]args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BinarySearchTree bst = new BinarySearchTree();
        String s = "";
        while ((s = br.readLine()) != null && s.length() != 0) {
            bst.addNode(Integer.parseInt(s));
        }

        bst.postOrderTraverse(bst.root);
    }



    }
