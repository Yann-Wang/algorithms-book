function Stack(){
	this.stackData = [];
	this.stackMin = [];

	this.getMin = function(){
		var len = this.stackMin.length;
		if(len == 0)
			throw new Error("stack is empty!");
		return this.stackMin[len-1];
	}

	this.push = function (val){
		this.stackData.push(val);
		if(this.stackMin.length == 0)
			this.stackMin.push(val);
		else if(val <= this.getMin()){
			this.stackMin.push(val);
		}		
	}

	this.pop = function(){
		var len = this.stackMin.length;
		if(len == 0)
			throw new Error("stack is empty!");
		var data = this.stackData.pop();
		if(data == this.getMin()){
			this.stackMin.pop();
		}
		return data;
	}
}



var st = new Stack();

var arr = [3,4,2,1];
for(var m of arr){
	st.push(m);
	console.log(st.getMin());
}