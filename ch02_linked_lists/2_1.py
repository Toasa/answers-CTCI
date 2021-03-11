# 単方向連結リストのノード
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

    def append_back(self, other):
        old_next = None
        if self.next != None:
            old_next = self.next

        self.next = other
        if old_next != None:
            other.next = old_next

    def print_node(self):
        cur = self
        while cur != None:
            print("{}->".format(cur.val), end="")
            cur = cur.next
        print()

def remove_dup_no_buf(n):
    cur = n
    while cur != None:
        runner = cur
        while runner.next != None:
            if runner.next.val == cur.val:
                runner.next = runner.next.next
            else:
                runner = runner.next

        cur = cur.next

def main():
    # n1 = Node(5)
    # n2 = Node(6)
    # n3 = Node(2)
    # n4 = Node(5)
    # n5 = Node(2)
    # n6 = Node(3)
    # n7 = Node(4)

    # n1.append_back(n2)
    # n2.append_back(n3)
    # n3.append_back(n4)
    # n4.append_back(n5)
    # n5.append_back(n6)
    # n6.append_back(n7)

    # n1.print_node()
    # remove_dup_no_buf(n1)
    # n1.print_node()

    n1 = Node(5)
    n2 = Node(5)
    n3 = Node(2)
    n4 = Node(5)
    n5 = Node(5)
    n6 = Node(3)
    n7 = Node(4)

    n1.append_back(n2)
    n2.append_back(n3)
    n3.append_back(n4)
    n4.append_back(n5)
    n5.append_back(n6)
    n6.append_back(n7)

    n1.print_node()
    remove_dup_no_buf(n1)
    n1.print_node()

main()
