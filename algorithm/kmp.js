
function getnext(substr, next){
	var i=0,j=-1;
	next[0] = -1;
	while(i<substr.length){
		if(j==-1 || substr.charAt(i)==substr.charAt(j)){
			++i;
			++j;
			next[i]=j;
		}else{
			j=next[j];
		}
	}
}

function KMP(str,substr,next){
	var i=0,j=0;
	while(i<str.length && j<substr.length){
		if(str.charAt(i)==substr.charAt(j)){
			++i;
			++j;
		}else{
			j=next[j];
			if(j==-1){
				j=0;
				++i;
			}
		}
	}
	if(j==substr.length)
		return i-substr.length;
	else
		return -1;
}

var str = "ababcabcacbab";
var substr = "abcac";

var next = [];
getnext(substr,next);

var result = KMP(str,substr,next);
if(result == -1){
	console.log('failure!');
}else{
	console.log('matching from '+result);
}