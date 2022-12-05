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

/*
* n {Number} arr数组最后一个元素的下标
* k {Number} 最小的K个数 k=K-1
*/
function HeapSort(arr, n, k){ 
	var i;

	for(i=(k-1)/2;i>=0;i--){
		HeapAdjust(arr,i,k);
	}

	for(i=n;i>=k+1;i--){
		if(arr[i]<arr[0]){
			arr[0] = arr[i];
			HeapAdjust(arr,0,k);
		}		
	}
}

var input = [3,1,2,7,4,5,8,6];
var n = input.length-1;
//top min 4
var topMIN = 4;
var k = topMIN - 1;

console.log(input);
HeapSort(input, n, k);
console.log(input.slice(0,topMIN).reverse());
input = null;