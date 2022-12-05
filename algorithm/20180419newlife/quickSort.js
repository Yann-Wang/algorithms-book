function quickSort(arr, left, right) {
    var tmp;
    var i=left,j=right;
    if (left < right) {
        tmp = arr[left];
        while(i!=j) {
            while(j>i && arr[j]>tmp) --j;
            if (i<j) {
                arr[i] = arr[j];
                ++i;
            }
            while(i<j && arr[i]<tmp) ++i;
            if (i<j) {
                arr[j] = arr[i];
                --j;
            }
        }
        arr[i] = tmp;
        quickSort(arr, left, i-1);
        quickSort(arr, i+1, right);
    }
}

const arr = [3,5,7,2,1,4,6,8];
console.log(arr);
quickSort(arr, 0, arr.length-1);
console.log(arr);
