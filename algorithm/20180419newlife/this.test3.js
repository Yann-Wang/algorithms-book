var x = 1;
function test(){
    console.log(this, this.x);
  this.x = 0;
}
test();
console.log(x); //1而非0
