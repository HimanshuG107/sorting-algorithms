import java.util.Arrays;

public class BubbleSort {
    public static int[] bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] result = bubbleSort(new int[]{10, 7, 8, 9, 1, 5});
        System.out.println(Arrays.toString(result));
    }
}
