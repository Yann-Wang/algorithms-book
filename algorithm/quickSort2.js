/*
* iteration method
*/
function partition(arr, left, right){
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
		
		return i;
	}
}


function QuickSortIterative(arr, left, right){
	var stack = new Array(right-left+1);
	var p;

	var top = -1;

	stack[++top] = left;
	stack[++top] = right;

	while(top >= 0){
		right = stack[top--];
		left  = stack[top--];

		p = partition(arr, left, right);

		if(p-1 > left){
			stack[++top] = left;
			stack[++top] = p-1;
		}

		if(p+1 < right){
			stack[++top] = p+1;
			stack[++top] = right;
		}

	}
}



var input = [3,1,2,7,4,5,8,6];
var n = input.length;

console.log(input);
QuickSortIterative(input, 0, n-1);
console.log(input);
input = null;