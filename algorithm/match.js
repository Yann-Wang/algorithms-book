

function match(exp, n){
	//console.log(n);
	var stack = new Array(parseInt(n/2)),top = -1;

	for(var i=0;i<n;++i){
		if(exp[i] === '(')
			stack[++top] = '(';
		if(exp[i] === ')'){
			if(top == -1)
				return 0;
			else
				--top;
		}
	}

	if(top == -1)
		return 1;
	else
		return 0;
}

// (3+(5*7-6)*3)%(5-3)
var expression = ['(','3','+','(','5','*','7','-','6',')','*','3',')','%','(','5','-','3',')'];
var exp_len = expression.length;

var result = match(expression, exp_len);
console.log(result);


