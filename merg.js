function mergeSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    const mid = Math.floor(arr.length / 2);
    const leftHalf = arr.slice(0, mid);
    const rightHalf = arr.slice(mid);

    const leftSorted = mergeSort(leftHalf);
    const rightSorted = mergeSort(rightHalf);

    return merge(leftSorted, rightSorted);
}

function merge(left, right) {
    const result = [];
    let leftIdx = 0, rightIdx = 0;

    while (leftIdx < left.length && rightIdx < right.length) {
        if (left[leftIdx] < right[rightIdx]) {
            result.push(left[leftIdx]);
            leftIdx++;
        } else {
            result.push(right[rightIdx]);
            rightIdx++;
        }
    }

    while (leftIdx < left.length) {
        result.push(left[leftIdx]);
        leftIdx++;
    }

    while (rightIdx < right.length) {
        result.push(right[rightIdx]);
        rightIdx++;
    }

    return result;
}

// Example 
const arr = [10, 7, 8, 9, 1, 5];
const sortedArr = mergeSort(arr);
console.log("Sorted array:", sortedArr);
