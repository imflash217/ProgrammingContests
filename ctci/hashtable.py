class HashTable:
    def __init__(self, table_size):
        """
        Args:
            table_size (int): the size of the hash table.
        """
        super().__init__()
        self.table_size = table_size
        self.hash_table = [[] for _ in range(self.table_size)]      ## ! this kind of nested lists DS is useful for CHAINING

    def hashing_func(self, key):
        """Hashing Function
        Args:
            key (int): the key
        Returns:
            [int]: index of the hash-table
        """
        hash = key % self.table_size
        return hash

    def insert_linear_probing(self, key, value):
        """
        Insert a (key, value) pair in the hash table.
        Using LINEAR PROBING
        Args:
            key (int): the key to be hashed
            value (any type): value to be stored
        """
        hash_key = self.hashing_func(key=key)
        if len(self.hash_table[hash_key]) == 0:
            self.hash_table[hash_key].append(value)
        else:
            ## ! collision happened. so search for the available slot
            pass

    def insert(self, key, value):
        """
        Insert a (key, value) pair in the hash table.
        Using TABLE CHAINING
        Args:
            key (int): the key to be hashed
            value (any type): value to be stored
        """
        hash_key = self.hashing_func(key=key)
        key_exists = False
        bucket = self.hash_table[hash_key]
        # print(bucket)
        for i, kv in enumerate(bucket):
            # print(i, kv)
            k, v = kv
            if k == key:
                key_exists = True
                break
        if key_exists:
            bucket[i] = (key, value)        ## ! the original key already exists. So OVERRIDE
        else:
            bucket.append((key, value))     ## ! two different keys COLLIDING. So APPEND using CHAINING

    def search(self, key):
        """Searching for a "key" and returning its (key, value) pair

        Args:
            key (int): any hashable type (as per the hash function used)

        Returns:
            (key, value) pair
        """
        hash_key = self.hashing_func(key=key)
        bucket = self.hash_table[hash_key]
        for i, kv in enumerate(bucket):
            k, v = kv
            if k == key:
                return (k, v)

    def delete(self, key):
        """Delete a given key (if present in the hashtable)

        Args:
            key ([type]): [description]
        """
        hash_key = self.hashing_func(key=key)
        bucket = self.hash_table[hash_key]
        key_exists = False
        for i, kv in enumerate(bucket):
            k, v = kv
            if k == key:
                key_exists = True
                break
        if key_exists:
            del bucket[i]
            print(f"key = {key} is deleted.")
        else:
            print(f"key={key} not found.")



##########################################################################################
if __name__ == "__main__":
    import pprint
    hashtable = HashTable(table_size=9)
    pprint.pprint(hashtable.hash_table)
    hashtable.insert(key=12, value="barry")
    pprint.pprint(hashtable.hash_table)
    hashtable.insert(key=13, value="vinay")
    pprint.pprint(hashtable.hash_table)
    hashtable.insert(key=32, value="flash")
    pprint.pprint(hashtable.hash_table)
    hashtable.insert(key=32, value="flash217")
    pprint.pprint(hashtable.hash_table)

    ## searching
    pprint.pprint(hashtable.search(key=32))

    ## deleting
    hashtable.delete(key=13)
    pprint.pprint(hashtable.hash_table)

##########################################################################################