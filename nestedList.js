var NestedIterator = function(nestedList) {
    this.nestedList = nestedList;
};


/**
 * @this NestedIterator
 * @returns {boolean}
 */
NestedIterator.prototype.hasNext = function() {
    console.log('hasNext 1: ', JSON.stringify(this.nestedList));
    if (this.nestedList.length) {
        if (Array.isArray(this.nestedList[0])) {
            const target = this.nestedList.shift();
            this.nestedList = target.concat(this.nestedList);
        }
        console.log('hasNext 2: ', JSON.stringify(this.nestedList));
        return true;
    }

    return false;
};

/**
 * @this NestedIterator
 * @returns {integer}
 */
NestedIterator.prototype.next = function() {
    if (this.nestedList.length) {
        return this.nestedList.shift();
    }
};

const nestedList = [[1, 2], 3, [4, [5]]];
 //* Your NestedIterator will be called like this:
 var i = new NestedIterator(nestedList), a = [];
 while (i.hasNext()) a.push(i.next());

 console.log('result: ', JSON.stringify(a));