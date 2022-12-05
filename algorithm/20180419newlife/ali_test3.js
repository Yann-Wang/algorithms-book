var BigInt = function (str) {
    var test = /^\d+$/.test(str);
    if (typeof str !== 'string' || !test) {
      throw new Error('the param must be a bigint!');
  }
    this.str = str;
  this.value = str.split('').reverse().map(function(item) { return +item; });

}
BigInt.prototype.plus = function(bigint){

    var arr = this.value;
    var arr2 = bigint.value;
    var len = Math.max(arr.length, arr2.length);

    var sum = new Array(len);
    for(var i=0; i<len;i++) {
      sum[i] = 0;
  }

    for(var j=0; j<len; j++) {
      var value1 = arr[j];
        sum[j] = arr[j] + arr2[j];
  }

    for (var k=0; k<len; k++) {
      if (sum[k] >= 10) {
            if (k+1 >= len) {
              sum[k+1] = 0;
          }
          sum[k] = sum[k] - 10;
          sum[k+1] += 1;
      }
  }

    var str = sum.reverse().join('');
    return new BigInt(str).toString();

};
BigInt.prototype.toString = function(){
  return this.str;
};
var bigint1 = new BigInt('1234232453525454546445458814343421545454545454');
var bigint2 = new BigInt('1234232453525454546445459914343421536654545454');
console.log(bigint1.plus(bigint2));
