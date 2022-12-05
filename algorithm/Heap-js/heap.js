/**
 * create heap [adjust]
 * replace heap arch node with the last node [adjust]
 *  */
function adjust (arr, low, high) {

    if (low <high) {
        var max, index, j;
        for (var i=parseInt((high-1)/2); i>=low; i = parseInt((i-1)/2)) {
            index = 2*i+1
            if (2*i+2<=high && arr[2*i+1] < arr[2*i+2]) {
                index = 2*i+2
            }
            max = arr[index]
            arr[index] = arr[i]
            arr[i] =max

        }
    }
}


function bigHeapSort(arr) {
    var len = arr.length;
    var tmp;

    for (var i = len-1;i>=0; i--) {
        adjust(arr, 0, i)
        console.log(arr)
        tmp = arr[i]
        arr[i] = arr[0]
        arr[0] = tmp
        console.log('second: ',arr)
    }
}

var arr = [3,4,2,1,5,6]
bigHeapSort(arr)
// [ 1, 6, 2, 4, 5, undefined, 3 ]
console.log('result: ', arr)
