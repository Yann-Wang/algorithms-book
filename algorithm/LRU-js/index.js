/**
 * 1. 如果此数据之前已经被缓存在链表中了，我们遍历得到这个数据对应的结点，
 *    并将其从原来的位置删除，然后再插入到链表的头部。
 * 2. 如果此数据没有在缓存链表中，又可以分为两种情况：
 *    如果此时缓存未满，则将此结点直接插入到链表的头部；
 *    如果此时缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部。
 */

class Node {
    constructor(key, value, next) {
        this.key = key || null;
        this.value = value || null;
        this.next = next || null;
    }
}

class LRU {
    constructor(maxSize) {
        this.maxSize = maxSize;
        if (this.maxSize < 1) {
            throw new Error("maxSize must be a positive integer");
        }
        this.head = new Node();
    }

    put = (key, value) => {
        let index = 0;
        let p = this.head;
        let target, first;

        while (p.next !== null) {
            index++;
            if (p.next.key === key) {
                p.next.value = value;

                target = p.next;
                p.next = p.next.next;
                first = this.head.next;
                this.head.next = target;
                target.next = first;
                return;
            }
            p = p.next;
        }

        if (index <= this.maxSize) {
            const node = new Node(key, value);
            first = this.head.next;
            this.head.next = node;
            node.next = first;
        }
        if (index === this.maxSize) {
            this.deleteLastNode();
        }
    };

    deleteLastNode = () => {
        let first = this.head.next;
        if (first === null || first.next === null) {
            return;
        }

        let last = first.next,
            lastSecond = first;
        while (last.next !== null) {
            lastSecond = last;
            last = last.next;
        }
        lastSecond.next = null;
    };

    get = key => {
        let p = this.head;
        let val;
        let target, first;

        while (p.next !== null) {
            if (p.next.key === key) {
                val = p.next.value;
                break;
            }
            p = p.next;
        }

        if (val) {
            target = p.next;
            p.next = p.next.next;
            first = this.head.next;
            this.head.next = target;
            target.next = first;
            return val;
        }

        return null;
    };
}
/*
const lruInstance = new LRU(5);
lruInstance.put("orange", 6);
lruInstance.put("banana", 3);
lruInstance.put("apple", 1);
lruInstance.put("pears", 4);
lruInstance.put("watermelon", 3);
lruInstance.put("grape", 9);

const orange = lruInstance.get("orange");
const banana = lruInstance.get("banana");
const apple = lruInstance.get("apple");
const pears = lruInstance.get("pears");
const watermelon = lruInstance.get("watermelon");
const grape = lruInstance.get("grape");

console.log("orange: ", orange);
console.log("banana: ", banana);
console.log("apple: ", apple);
console.log("pears: ", pears);
console.log("watermelon: ", watermelon);
console.log("grape: ", grape);
*/
const cache = new LRU(2);
cache.put(1, 1);
cache.put(2, 2);
cache.get(1); // 返回  1
cache.put(3, 3); // 该操作会使得密钥 2 作废
cache.get(2); // 返回 -1 (未找到)
cache.put(4, 4); // 该操作会使得密钥 1 作废
cache.get(1); // 返回 -1 (未找到)
cache.get(3); // 返回  3
cache.get(4); // 返回  4

// 时间复杂度为O(1) 的实现方法： hash + 双向链表
