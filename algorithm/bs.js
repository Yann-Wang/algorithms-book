/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

输入: [1,3,5,6], 5  输出: 2
输入: [1,3,5,6], 6  输出: 3
输入: [1,3,5,6], 2  输出: 1
输入: [1,3,5,6], 7  输出: 4
输入: [1,3,5,6], 0  输出: 0

*/

/*
var searchInsert = function(nums, target) {
    var i=0, j=nums.length-1;
    var mid;
    while(i<j) {
        mid = parseInt((j-i)/2)+i;
        if (nums[mid] === target) {
            return mid;
        }
        if (nums[mid]>target) {
            j = mid;
        } else {
            i = mid+1;
        }
    }
    if (nums[i] >= target) {
        return i;
    }
    if(nums[i]<target) {
        return i+1;
    }
};
*/

var searchInsert = function(nums, target) {
	var index = nums.indexOf(target)
	if(index != -1){
    	return index
	}else{
		nums.push(target)
		var sortArr = nums.sort()
		return sortArr.indexOf(target)
	}
};

console.log('输入: [1,3,5,6], 5  输出: 2  ', searchInsert([1,3,5,6], 5));

console.log('输入: [1,3,5,6], 6  输出: 3  ', searchInsert([1,3,5,6], 6));

console.log('输入: [1,3,5,6], 2  输出: 1  ', searchInsert([1,3,5,6], 2));

console.log('输入: [1,3,5,6], 7  输出: 4  ', searchInsert([1,3,5,6], 7));

console.log('输入: [1,3,5,6], 0  输出: 0  ', searchInsert([1,3,5,6], 0));

