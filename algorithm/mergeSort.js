function merge(input, low, mid, high){
	var i=low, j=mid+1,k=0;
	var temp = new Array(high-low+1);

	while(i<=mid && j<=high){
		if(input[i]<input[j]){
			temp[k++] = input[i++];
		}else{
			temp[k++] = input[j++];
		}
	}
	
	while(i<=mid) temp[k++] = input[i++];
	
	while(j<=high) temp[k++] = input[j++];

	for(i=low,k=0;i<=high;k++,i++){
		input[i] = temp[k];
	}
}

function sort(input, n){ //input元素个数
	
	var size = 1, low, mid, high;

	while(size <= n-1){
		low = 0;
		while(low+size <= n-1){
			mid  = low + size - 1;
			high = mid + size;  
			if(high > n-1){
				high = n-1;
			}

			merge(input, low, mid, high);
			low = high + 1;
		}
		size *= 2;
	}
}

var input = [3,1,2,7,4,5,8,6];
var n = input.length;

console.log(input);
sort(input, n);
console.log(input);
input = null;