
var filterString=["gre","eat"];

var input = "the great wall";

//expect: "the ***** wall"

var index = [];
var i,j,output,len,result;
var arr = new Array(input.length);
for(i=0;i<input.length;++i){
	arr[i]=0;
}

for(i=0;i<filterString.length;++i){
	index[i] = input.indexOf(filterString[i]);
	for(j=index[i];j<index[i]+filterString[i].length;++j){
		arr[j]=1;
	}
}

output = input.split("");
for(i=0;i<input.length;++i){
	if(arr[i]===1){
		output[i]='*';
	}
}
result = output.join("");
console.log(result);



