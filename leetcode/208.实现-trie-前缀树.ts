/*
 * @lc app=leetcode.cn id=208 lang=typescript
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class TrieNode {
    isEnd?: boolean
}

class Trie {
    children: TrieNode;
    constructor() {
        this.children = {};
    }

    insert(word: string): void {
        let node = this.children;

        for(const ch of word) {
            if (!node[ch]) {
                node[ch] = new TrieNode();
            }
            node = node[ch];
        }
        node.isEnd = true;
    }

    search(word: string): boolean {
        let node = this.children;

        for(const ch of word) {
            if (!node[ch]) {
                return false;
            }
            node = node[ch];
        }

        return Boolean(node && node.isEnd);

    }

    startsWith(prefix: string): boolean {
        let node = this.children;

        for(const ch of prefix) {
            if (!node[ch]) {
                return false;
            }
            node = node[ch];
        }

        return Boolean(node);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
// @lc code=end

