class Node:
    def __init__(self, ID):
        self.ID = ID
        self.count = 1
        self.right = None
        self.left = None

    def search(self, ID):
        if self == None:
            return None

        if self.ID == ID:
            return self
        elif self.ID < ID:
            return search(self.right, ID)
        else:
            return search(self.left, ID)

    def insert(self, new):
        if self.ID == new.ID:
            self.count += 1
        elif self.ID < new.ID:
            if self.right == None:
                self.right = new
            else:
                self.right.insert(new)
        else:
            if self.left == None:
                self.left = new
            else:
                self.left.insert(new)

    def get_rank(self, ID):
        count = 0
        if self.ID == ID:
            count += self.count-1
        elif self.ID < ID:
            count += self.count

        if self.left != None:
            count += self.left.get_rank(ID)
        if self.right != None:
            count += self.right.get_rank(ID)
        return count

def main():
    nums = [5, 1, 4, 4, 5, 9, 7, 13, 3]
    root = Node(nums[0])
    for num in nums[1:]:
        root.insert(Node(num))

    print(root.get_rank(1))
    print(root.get_rank(3))
    print(root.get_rank(4))

main()
