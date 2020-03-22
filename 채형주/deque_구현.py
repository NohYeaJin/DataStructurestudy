class Deque:
    def __init__(self):
        self.my_deque = []
    def push_back(self, new_int):
        self.my_deque = self.my_deque + [new_int]
    def push_front(self, new_int):
        self.my_deque = [new_int] +  self.my_deque
    def front(self):
        if len(self.my_deque) == 0:
            print(-1)
        else:
            print(self.my_deque[0])
    def back(self):
        if len(self.my_deque) == 0:
            print(-1)
        else:
            print(self.my_deque[-1])
    def empty(self):
        if len(self.my_deque) == 0:
            print(1)
        else:
            print(0)
    def size(self):
        print(len(self.my_deque))
    def pop_front(self):
        print(self.my_deque[0])
        del self.my_deque[0]
    def pop_back(self):
        print(self.my_deque[-1])
        del self.my_deque[-1]
    def command(self, new_command):
        tmp = new_command.split()
        command_name = tmp[0]
        tmp[1] = int(tmp[1])
        if command_name == "push_front":
            self.push_front(tmp[1])
        elif command_name == "push_back":
            self.push_back(tmp[-1])
        elif command_name == "pop_front":
            self.pop_front()
        elif command_name == "pop_back":
            self.pop_back()
        elif command_name == "size":
            self.size()
        elif command_name == "empty":
            self.empty()
        elif command_name == "front":
            self.front()
        elif command_name == "back":
            self.back()
        elif command_name == "print":
            print(self.my_deque)

        else:
            print("Invalid Command")


deque = Deque()
while True:
    new_command = input("Enter a command(q : quit): ")
    if new_command == "q":
        break
    else:
        deque.command(new_command)






