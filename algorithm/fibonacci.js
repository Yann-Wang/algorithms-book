function fibonacci(n){
	var first =1, second=1,third, t;

	if(n===0 || n===1){
		return 1;
	}

	t=2;

	while(t<=n){
		third = first + second;
		first = second;
		second = third;
		++t;
	}

	return third;
}

var result = fibonacci(5);
console.log(result);
