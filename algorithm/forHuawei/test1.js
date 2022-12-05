process.stdin.resume();
process.stdin.setEncoding('ascii');

var input = "";
var input_array = "";

process.stdin.on('data', function (data) {
    input += data;
});

process.stdin.on('end', function () {
    input_array = input.split("\n");
    var nLine = 0;

    while(nLine < input_array.length){
    	var line = input_array[nLine++].trim();
    	if(line === ''){
    		continue;
    	}
        var input_arrays = line.split(' ');
        var a = +input_arrays[0];
        var b = +input_arrays[1];
        var c = +input_arrays[2];
        var d = +input_arrays[3];
        
        var A,B1,B2,C;
        
        A=(a+c)/2;
        B1= (c-a)/2;
        B2= (b+d)/2;
        C= (d-b)/2;
        
        if(B1 === B2){
            console.log(A,' ',B1,' ',C);
        }else{
            console.log('No');
        }
        
        
        console.log(a+b);
    }
});