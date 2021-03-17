## Least Recently Used (LRU) Cache
## Your program is running slowly because it's accessing data from disk over and over again.
# To improve the performance, you want to build a simple key-value store to cache this data in memory,
# but you also want to limit the amount of memory used. You decide to build a caching system
# that only keeps the N most recently used items—also known as a least recently used (LRU) cache.

# Write a class LRUCache(n) that accepts a size limit n. It should support a set(key, value)
# method for inserting or updating items and a get(key) method for retrieving items.
# Can you implement a solution where both of these methods run in O(1) time?

####################################################################################################
## Using DOUBLY-LINKED LIST & HASH-TABLE

## Helper methods

class Node():
    def __init__(self, key, val) -> None:
        self.key = key
        self.val = val
        self.front = None   ## prev
        self.back = None    ## next

class LRUCache():
    def __init__(self, n) -> None:
        self.n = n
        self.count = 0
        self.nodes = {}
        self.start = None
        self.end = None

    def insert(self, node):
        """Inserts the node at the front of teh list"""
        if not self.end:
            ## there is no end-node i.e. the list is empty. So add the node as end-node
            self.end = node
        if self.start:
            ## there is at least 1 node in the list.
            node.back = self.start  ## set the current node as new node's BACK
            self.start.front = node  ## set the new node as current node's FRONT
        self.start = node   ## set the new node as the start of the list

    def remove(self, node):
        if node.front:
            node.front.back = node.back
        if node.back:
            node.back.front = node.front
        if node == self.start:
            self.start = node.back
        if node == self.end:
            self.end = node.front

    def move_to_front(self, node):
        self.remove(node)   ## remove the node first
        self.insert(node)   ## RE-INSERT the node again at the front





    def get(self, key):
        """Get the node for the "key"
        """
        ## get node for the key if it exists
        node = self.nodes.get(key)      ## remember self.nodes is dictionary
        if not node:
            print("no node for this key")
            return None

        ## move this node to the front of the cache
        self.move_to_front(node)
        return node.val

    def set(self, key, val):
        pass