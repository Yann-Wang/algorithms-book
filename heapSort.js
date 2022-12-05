const arr = [1,5,7,3,4,2,6,8];

function heapSort(arr) {
    const len = arr.length;


    for (let i = parseInt((len-2)/2);i>=0;i--) {
        heapSortByRange(arr, i, len-1);
    }

    let tmp;

    for (let j=len-1;j>=0;j--) {
        tmp = arr[0];
        arr[0] = arr[j];
        arr[j] = tmp;
        heapSortByRange(arr, 0, j-1);
    }

    return arr;

}

function heapSortByRange(arr, low, high) {

    if (low >= high) {
        return;
    }

    let i=low, j=2*i +1,tmp=arr[i];

    while(j<=high) {
        if (j<high && arr[j]<arr[j+1]) {
            j++
        }
        if (arr[j]>tmp) {
            arr[i] = arr[j];
            i = j;
            j = 2*i+1;
        } else {
            break;
        }
    }

    arr[i] = tmp;



}

console.log('result: ', JSON.stringify(heapSort(arr)));

