import java.util.Scanner;

public class ShellSortInput {
    // Method to perform Shell Sort
    public static void shellSort(int[] arr) {
        int n = arr.length;

        // Start with a big gap, then reduce it
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;

                // Shift earlier gap-sorted elements
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }

                // Put temp in its correct location
                arr[j] = temp;
            }
        }
    }

    // Utility method to print an array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking array size input
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        // Taking array elements input
        int[] arr = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.println("Original array:");
        printArray(arr);

        // Sorting the array
        shellSort(arr);

        System.out.println("Sorted array:");
        printArray(arr);

        scanner.close();
    }
}
