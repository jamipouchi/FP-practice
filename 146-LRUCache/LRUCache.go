package lrucache

type LRUCache struct {
    length, capacity int
    m map[int]*Node
    head, tail *Node
}

type Node struct {
    key, val int
    next, prev *Node
}

func Constructor(capacity int) LRUCache {
    return LRUCache {
        capacity: capacity,
        length: 0,
        m : make(map[int]*Node),
        head: nil,
        tail: nil,
    }
}

func (this *LRUCache) Get(key int) int {
    if node, ok := this.m[key]; !ok {
        return -1
    } else {
        if node == this.head && node == this.tail {
			// do nth
        } else if node == this.head {
			// do nth
        } else if node == this.tail {
            prevNode := this.tail.prev
            prevNode.next = nil
            this.tail.next = this.head
            this.head.prev = this.tail
            this.head = this.tail
            this.tail = prevNode
        } else {
            prevNode := node.prev
            nextNode := node.next    
            prevNode.next = nextNode
            nextNode.prev = prevNode
            node.next = this.head
            this.head.prev = node
            this.head = node
        }
    }
    return this.head.val
}

func (this *LRUCache) Put(key int, value int)  {
    if node, ok := this.m[key]; ok {
        node.val = value
        if node == this.head && node == this.tail {
            // do nth 
        } else if node == this.head {
            // do nth 
        } else if node == this.tail {
            this.tail = node.prev
            this.tail.next = nil
            node.next = this.head
            this.head.prev = node
            this.head = node
        } else {
            prevNode := node.prev
            nextNode := node.next    
            node.next = nil
            node.prev = nil
            prevNode.next = nextNode
            nextNode.prev = prevNode
            node.next = this.head
            this.head.prev = node
            this.head = node
        }
    } else { 
        newNode := &Node {
            key: key,
            val: value,
            prev: nil,
            next: nil,
        }
        this.m[key] = newNode
        this.length++
        if this.head == nil && this.tail == nil {
            this.head = newNode
            this.tail = newNode
        } else {
            newNode.next = this.head
            this.head.prev = newNode
            this.head = newNode
            for this.length > this.capacity {
                delete(this.m, this.tail.key)
                prevNode := this.tail.prev
                prevNode.next = nil
                this.tail.next = nil
                this.tail = prevNode
                this.length--
            }
        }
    }
}