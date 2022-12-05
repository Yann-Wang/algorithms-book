function HeapAdjust(arr, low, high){
	var i=low, j=2*i+1;
	var temp = arr[i];
	while(j<=high){
		if(j<high && arr[j]<arr[j+1])
			++j;
		if(temp<arr[j]){
			arr[i] = arr[j];
			i=j;
			j=2*i+1;
		}else
			break;
	}
	arr[i]=temp;
}

function HeapSort(arr, n){
	var i,temp;
	for(i=(n-1)/2;i>=0;i--){
		HeapAdjust(arr,i,n);
	}

	for(i=n;i>=1;i--){
		temp   = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		HeapAdjust(arr,0,i-1);
	}
}

var input = [3,1,2,7,4,5,8,6];
var n = input.length-1;

console.log(input);
HeapSort(input, n);
console.log(input);
input = null;