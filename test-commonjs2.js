let demo = require('./test-commonjs-demo.js');

console.log(demo.a);  // 1
console.log(demo.b);  // { num: 1 }
setTimeout(() => {
    console.log(demo.a);  // 1
    console.log(demo.b);  // { num: 1 }
}, 500);