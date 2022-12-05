function foo(){
    console.log(this.a);
}

var a = 2;
var o = { a: 3, foo: foo};
var p = { a: 4};

o.foo();  // 3


(o.foo)();  // 3


(p.foo = o.foo)();  //  undefined     //赋值表达式的值 就是右操作数的值


p.foo();   //  4

(p.foo)();   // 4


var bar = o.foo;
bar();   //  undefined
console.log(this);
