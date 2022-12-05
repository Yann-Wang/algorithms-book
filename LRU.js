/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？


示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
 

提示：

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
最多调用 3 * 104 次 get 和 put


*/

function Node(key, value) {
    this.left = null;
    this.right = null;
    this.value = value;
    this.key = key;
}

/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.head = new Node();
    this.rear = new Node();

    this.head.right = this.rear;
    this.rear.left = this.head;

    this.hash = {};
    this.len = 0;
    this.capacity = capacity;
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.hash[key]) {
        let left = this.hash[key].left;
        let right = this.hash[key].right;

        left.right = right;
        right.left = left;

        let first = this.head.right;
        this.head.right = this.hash[key];
        first.left = this.hash[key];

        this.hash[key].left = this.head;
        this.hash[key].right = first;

        return this.hash[key].value;
    } else {
        return -1;
    }
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    // key存在
    if (this.hash[key]) {
        // 从当前位置删除Node
        let leftNode = this.hash[key].left;
        let rightNode = this.hash[key].right;

        leftNode.right = rightNode;
        rightNode.left = leftNode;

        // 将Node插入头结点
        let first = this.head.right;

        this.head.right = this.hash[key];
        first.left = this.hash[key];

        this.hash[key].left = this.head;
        this.hash[key].right = first;
        this.hash[key].value = value;
        // this.hash[key].key = key;
    } else {
        // key不存在
        if (this.capacity === 0) {
            return;
        }
        if (this.len === this.capacity) {
            // 删除最后一个
            let lastNode = this.rear.left;

            let leftNode = lastNode.left;
            let rightNode = lastNode.right;

            leftNode.right = rightNode;
            rightNode.left = leftNode;

            this.len = this.len - 1;

            delete this.hash[lastNode.key];
        }

        // Node插入头结点
        let first = this.head.right;
        let currNode = new Node(key, value);

        this.head.right = currNode;
        first.left = currNode;

        currNode.left = this.head;
        currNode.right = first;

        this.len = this.len + 1;

        this.hash[key] = currNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */

 let operation = ["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
 let data = [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]

//  let operation = ["LRUCache","put","put","put","put","put","get"];
//  let data = [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13]]

 // 输出：[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,14,null,null,-1,null,null,11,null,null,null,null,null,-1,null,null,24,null,4,29,30,null,12,11,null,null,null,null,29,null,null,null,null,-1,22,-1,null,null,null,24,null,null,null,20,null,null,null,29,-1,-1,null,null,null,null,-1,null,null,null,null,null,null,null]

 // 预期：[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,-1,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,-1,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]
let obj;
let result = [];
let process = [];

function getRecord(cache) {
    let res = [];

    let p = cache.head;

    while(p.right && p.right.key !== undefined && p.right.value !== undefined) {
        p = p.right;

        res.push([p.left.key, p.key, p.value, ]);
    }

    // Object.keys(cache.hash).forEach(it => {
    //     res.push([it, cache.hash[it].value]);
    // });

    return res;
}

 operation.forEach((it, index) => {
     let tmp = []
     if (it === 'LRUCache') {
        obj = new LRUCache(data[index][0]);
        tmp.push(it, data[index][0])
     } else if (it === 'put') {
         obj.put(data[index][0], data[index][1]);
         tmp.push(it, data[index][0], data[index][1]);
     } else if (it === 'get') {
         let val = obj.get(data[index][0]);
         tmp.push(it, data[index][0])
     }

     tmp.push(getRecord(obj))
     console.log('index: ', index, tmp)
 })