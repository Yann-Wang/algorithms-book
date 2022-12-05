const arr = [1,5,6,2,4,3]

function quickSort(arr) {
    quickSort_c(arr, 0, arr.length-1)
}

function quickSort_c(arr, p, q) {
    if (p >= q) {
        return
    }
    const pivot = partition(arr, p, q)
    quickSort_c(arr, p, pivot-1)
    quickSort_c(arr, pivot+1, q)
}

function partition(arr, p, q) {

}
