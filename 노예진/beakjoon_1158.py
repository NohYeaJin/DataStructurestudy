class Node:
    def __init__(self, key = None):
        self.key = key
        self.next = self.prev = self

    def __str__(self):
        return str(self.key)

class DoublyLinkedList:
    def __init__(self):
        self.head = Node()
        self.size = 0

    def __iter__(self):
        v = self.head
        for i in range(a):
            yield v
            v = v.next

    def __str__(self):
            return (str(v) for v in self)

    def __len__(self):
        count = 0
        v = self.head.next
        while v.key!=None:
            count = count + 1
            v = v.next
            if v == self.head:
                break
        return count

    def splice(self,a,b,x):
        if a == None or b == None or x == None:
            return
        ap = a.prev
        bn = b.next

        ap.next = bn
        bn.prev = ap

        xn = x.next
        xn.prev = b
        b.next = xn
        a.prev = x
        x.next = a


    def remove(self,x):
        if x == None: return
        x.prev.next, x.next.prev = x.next,x.prev

    def search(self,key):
        v = self.head
        while v!=None:
            if v.key == key: return v
            v = v.next
        return v
        
    def moveAfter(self,a,x):
        self.splice(a,a,x.prev)

    def moveBefore(self,a,x):
        self.splice(a, a, x.prev)

    def insertAfter(self,x,key):
        self.moveAfter(Node(key),x)

    def insertBefore(self,x,key):
        self.moveBefore(Node(key),x)

    def pushBack(self,key):
        self.insertBefore(self.head,key)

def josephus(n , k):
    answer = []
    L = DoublyLinkedList()
    v = L.head.next
    for i in range(1,n+1):
        L.pushBack(i)
    while len(L) > 1:
        for i in range(1,k+1):
            v = v.next
            if v.key == None:
                
                v = v.next
        answer.append(v.key)
        L.remove(v)
    answer.append(L.head.next.key)
    print("<",end='')
    for i in range(n):
        if (i==n-1):
            print(answer[i],end='')
            print(">")
        else:
            print(answer[i],end = ', ')

      


x,y = input().split()
a = int(x)
b = int(y)
josephus(a,b)

