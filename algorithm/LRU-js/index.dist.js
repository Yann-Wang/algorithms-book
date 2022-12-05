"use strict";

function _classCallCheck(instance, Constructor) {
    if (!(instance instanceof Constructor)) {
        throw new TypeError("Cannot call a class as a function");
    }
}

/**
 * 1. 如果此数据之前已经被缓存在链表中了，我们遍历得到这个数据对应的结点，
 *    并将其从原来的位置删除，然后再插入到链表的头部。
 * 2. 如果此数据没有在缓存链表中，又可以分为两种情况：
 *    如果此时缓存未满，则将此结点直接插入到链表的头部；
 *    如果此时缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部。
 */

var Node = function Node(key, value, next) {
    _classCallCheck(this, Node);

    this.key = key || null;
    this.value = value || null;
    this.next = next || null;
};

var LRU = function LRU(maxSize) {
    var _this = this;

    _classCallCheck(this, LRU);

    this.put = function(key, value) {
        var index = 0;
        var p = _this.head;
        var target = void 0,
            first = void 0;

        while (p.next !== null) {
            index++;
            if (p.next.key === key) {
                p.next.value = value;

                target = p.next;
                p.next = p.next.next;
                first = _this.head.next;
                _this.head.next = target;
                target.next = first;
                return;
            }
            p = p.next;
        }

        if (index <= _this.maxSize) {
            var node = new Node(key, value);
            first = _this.head.next;
            _this.head.next = node;
            node.next = first;
        }
        if (index === _this.maxSize) {
            _this.deleteLastNode();
        }
    };

    this.deleteLastNode = function() {
        var first = _this.head.next;
        if (first === null || first.next === null) {
            return;
        }

        var last = first.next,
            lastSecond = first;
        while (last.next !== null) {
            lastSecond = last;
            last = last.next;
        }
        lastSecond.next = null;
    };

    this.get = function(key) {
        var p = _this.head;
        var val = void 0;
        var target = void 0,
            first = void 0;

        while (p.next !== null) {
            if (p.next.key === key) {
                val = p.next.value;
                break;
            }
            p = p.next;
        }
        console.log(key, " :", val);
        if (val) {
            target = p.next;
            p.next = p.next.next;
            first = _this.head.next;
            _this.head.next = target;
            target.next = first;

            return val;
        }

        return null;
    };

    this.maxSize = maxSize;
    if (this.maxSize < 1) {
        throw new Error("maxSize must be a positive integer");
    }
    this.head = new Node();
};
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

var cache = new LRU(2);
cache.put(1, 1);
cache.put(2, 2);
cache.get(1); // 返回  1
cache.put(3, 3); // 该操作会使得密钥 2 作废
cache.get(2); // 返回 -1 (未找到)
cache.put(4, 4); // 该操作会使得密钥 1 作废
cache.get(1); // 返回 -1 (未找到)
cache.get(3); // 返回  3
cache.get(4); // 返回  4
