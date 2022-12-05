// const arr = [1,8,6,2,5,4,8,3,7];
const arr = [1,3,2,5,25,24,5];

/**
 * 
 * @param {Array} arr 
 * @returns {[i,j]}
 */
function getVolumnMax(arr) {
    const len = arr.length;
    let left = 0, right = len-1;
    let i = 0, j = len-1;
    let previous,curr;
    while (i<j) {

        const res = (right-left)*Math.min(arr[left], arr[right]);
        
        if (arr[i] < arr[j]) {
            
            i++;
        } else if (arr[i] > arr[j]){
            j--;
        } else {
            i++;
        }


        
        previous = (right-left)*Math.min(arr[left], arr[right]);
        curr = (j-i)*Math.min(arr[i], arr[j]);
        if (curr > previous) {
            left = i;
            right = j;
        }

        
        console.log(i,j,left, right);
    }

    return [left, right];
}

console.log('result: ', getVolumnMax(arr));