public class SelectionSort {
    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int min_index = i;
            // Finding the min element
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            // Swapping
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        selectionSort(arr);
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
