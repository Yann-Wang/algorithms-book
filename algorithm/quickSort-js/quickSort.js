var arr = [1, 6, 3, 5, 2, 4];

function quickSort(arr) {
    quickSort_s(arr, 0, arr.length - 1);
    return arr;
}

function quickSort_s(arr, m, n) {
    if (m >= n) {
        return;
    }
    var q = partition(arr, m, n);

    quickSort_s(arr, m, q - 1);
    quickSort_s(arr, q + 1, n);
}

function partition(arr, start, end) {
    var i = start,
        j = end;
    var tmp = arr[i];
    while (i < j) {
        while (j > i && arr[j] >= tmp) {
            j--;
        }
        if (j > i) {
            arr[i] = arr[j];
        }
        while (i < j && arr[i] <= tmp) {
            i++;
        }
        if (i < j) {
            arr[j] = arr[i];
        }
    }
    arr[i] = tmp;
    return i;
}

const result = quickSort(arr);
console.log("result: ", result);
