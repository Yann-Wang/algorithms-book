x = 1;
function test(){
  this.x = 0;
}
console.log(x); //返回1
test();
console.log(x); //返回0
