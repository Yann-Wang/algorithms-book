/*
* iteration method
*/
function QuickSort(arr, left, right){
	var temp, i=left, j=right;

	if(left<right){
		temp=arr[left];

		while(i != j){
			while(j>i && arr[j]>temp) --j;
			if(i<j){
				arr[i]=arr[j];
				++i;
			}
			while(i<j && arr[i]<temp) ++i;
			if(i<j){
				arr[j]=arr[i];
				--j;
			}
		}
		arr[i]=temp;
		QuickSort(arr,left,i-1);
		QuickSort(arr,i+1,right);
	}
}

var input = [3,1,2,7,4,5,8,6];
var n = input.length;

console.log(input);
QuickSort(input, 0, n-1);
console.log(input);
input = null;