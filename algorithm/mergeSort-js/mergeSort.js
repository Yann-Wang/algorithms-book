var arr = [3,1,2,4,6,5]

function mergeSort(arr) {
    mergeSort_s(arr, 0, arr.length - 1)
}

function mergeSort_s(arr, m, n) {
    if(m >= n) {
        return
    }
    var mid = parseInt((m+n)/2)
    mergeSort_s(arr, m, mid)
    mergeSort_s(arr, mid+1, n)

    merge(arr, m, mid, n)
}

function merge(arr, m, mid, n) {
    var arr2 = []
    var i = m
    var j = mid+1

    while(i<=mid && j<=n) {
        if (arr[i] < arr[j]) {
            arr2.push(arr[i])
            i++
        } else {
            arr2.push(arr[j])
            j++
        }
    }

    while(i<=mid) {
        arr2.push(arr[i])
        i++
    }
    while(j<=n) {
        arr2.push(arr[j])
        j++
    }

    for (var k=m, s=0; k<=n; k++, s++) {
        arr[k] = arr2[s]
    }
}

mergeSort(arr)

console.log('result: ', arr)
