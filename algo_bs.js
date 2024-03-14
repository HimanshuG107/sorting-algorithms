function bubbleSort(arr) {
    const n = arr.length;
    for (let i = 0; i < n; i++) {
        let swapped = false;
        for (let j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]; // Swapping
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return arr;
}

const result = bubbleSort([10, 7, 8, 9, 1, 5]);
console.log(result);
