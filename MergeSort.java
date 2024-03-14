import java.util.Arrays;

public class MergeSort {
    public static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) {
            return arr;
        }

        int mid = arr.length / 2;
        int[] leftHalf = Arrays.copyOfRange(arr, 0, mid);
        int[] rightHalf = Arrays.copyOfRange(arr, mid, arr.length);

        int[] leftSorted = mergeSort(leftHalf);
        int[] rightSorted = mergeSort(rightHalf);

        return merge(leftSorted, rightSorted);
    }

    public static int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int leftIdx = 0, rightIdx = 0, resultIdx = 0;

        while (leftIdx < left.length && rightIdx < right.length) {
            if (left[leftIdx] < right[rightIdx]) {
                result[resultIdx++] = left[leftIdx++];
            } else {
                result[resultIdx++] = right[rightIdx++];
            }
        }

        while (leftIdx < left.length) {
            result[resultIdx++] = left[leftIdx++];
        }

        while (rightIdx < right.length) {
            result[resultIdx++] = right[rightIdx++];
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        int[] sortedArr = mergeSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(sortedArr));
    }
}
