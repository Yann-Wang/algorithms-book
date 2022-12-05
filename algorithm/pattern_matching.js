function pattern_matching(str, substr){
	var i=0, j=0, k=i;
	while(i<str.length && j<substr.length){
		if(str.charAt(i) == substr.charAt(j)){
			++i;
			++j;
		}else{
			j=0;
			i=++k;
		}
	}
	if(j==substr.length)
		return k;
	else
		return -1;
}

var str = "ababcabcacbab";
var substr = "abcac";

var result = pattern_matching(str,substr);
if(result == -1){
	console.log('failure!');
}else{
	console.log('matching from '+result);
}