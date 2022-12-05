

function(arr){
	var i=0,n=arr.length,arri=1;
	var lost=[],k=-1;
	while(i<n){

		if(arr[i] !== arri){
			lost[++k] = arri;
		}

		++i;
		++arri;
	}
}