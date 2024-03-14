function selectionSort(arr) {
    for (let i = 0; i < arr.length; i++) {
        let min_index = i;
        // Finding the min element
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        [arr[i], arr[min_index]] = [arr[min_index], arr[i]]; // Swapping
    }
    return arr;
}

let s1 = selectionSort([10, 7, 8, 9, 1, 5]);
console.log(s1);
