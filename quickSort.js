const arr = [1,5,7,3,4,2,6,8];
/**
 * 
 * @param {Array} arr
 * @return {Array} result
 */
function quickSort(arr) {

    quickSortRange(arr, 0, arr.length -1);
    
    return arr;
}

function quickSortRange(arr, left, right) {
    if (left >= right) {
        return;
    }

    let i = left, j = right, tmp = arr[i];

    while (i !== j) {
        while(i<j && arr[j] < tmp) j--;
        if (i<j) {
            arr[i] = arr[j];
            i++;
        }
        while(i<j && arr[i] > tmp) i++;
        if (i<j) {
            arr[j] = arr[i];
            j--;
        }
    }

    arr[i] = tmp;

    quickSortRange(arr, left, i-1);
    quickSortRange(arr, i+1, right);
}


console.log('output: ', JSON.stringify(quickSort(arr)));
