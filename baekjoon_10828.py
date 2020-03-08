import sys
class Stack:
    def __init__(self):
        self.items = []
        self.size = 0

    def __len__(self):
        return len(self.items)

    def push(self,val):
        self.items.append(val)

    def pop(self):
        if len(self.items)==0:
            print("-1")

        else:
            a = self.items.pop()
            self.size -= 1
            print(a)

    def top(self):
        if len(self.items)==0:
            print("-1")

        else:
            a = self.items[-1]
            print(a)

    def isEmpty(self):
        if self.items == []:
            print("1")

        else:
            print("0")


def directions(result,input,val=None):
    result = Stack()

    if input == 'push':
        S.push(val)

    if input == 'top':
        S.top()

    if input == 'pop':
        S.pop()

    if input == 'empty':
        S.isEmpty()

    if input == 'size':
        print(len(S))


cmd_num = input()
cmd_num = int(cmd_num)
S = Stack()
for i in range(cmd_num):
    cmd = sys.stdin.readline().split()

    if cmd[0] == 'push':
        directions(S,cmd[0],cmd[1])
    else:
        directions(S,cmd[0])
