function flat(arr) {
    var arr2 = [];
    function _flat(arr, init) {
        for (var i=0; i<arr.length; ++i) {
            if (Array.isArray(arr[i])) {
                _flat(arr[i], init);
            } else {
                init.push(arr[i]);
            }
        }
    }

    _flat(arr, arr2);

    return arr2;
 }

var res = flat([0, [1, 2], 3]); //[0, 1, 2, 3]
var res2 = flat([0, [1, [2, 3]], 4]); //[0, 1, 2, 3, 4]

console.log(res, res2);
