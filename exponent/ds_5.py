## @imflash217
## Balanced Tree

class Node:
    def __init__(self, val) -> None:
        self.left = None
        self.right = None
        self.val = val


def get_height(node):
    if not node:
        ## base case for leaf-node
        return 0
    height_left_subtree = get_height(node.left)
    height_right_subtree = get_height(node.right)
    return max(height_left_subtree, height_right_subtree) + 1


def is_balanced(node):
    if not node:
        ## node is a NONE
        return True  ## no tree below it; so it is balanced
    height_left_subtree = get_height(node.left)
    height_right_subtree = get_height(node.right)
    height_diff = abs(height_left_subtree - height_right_subtree)
    if height_diff > 1:
        return False
    else:
        return is_balanced(node.left) and is_balanced(node.right)


if __name__ == "__main__":
    nodes = []
    for i in range(10):
        if i == 0:
            node = Node(i)
            nodes.append(node)
        else:
            node = Node(i)
            ## print(i, nodes)
            node.left = nodes[i - 1]
            # if len(nodes) >= 2:
            #     node.right = nodes[i - 2]
            nodes.append(node)
    import pprint

    # print(nodes[3].val, nodes[3].left.val, nodes[3].right.val)
    res = is_balanced(nodes[0])
    print(res)
