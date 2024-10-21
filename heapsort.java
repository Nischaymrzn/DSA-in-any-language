import java.util.Arrays;

public class heapsort {

    // Function to swap values at two indices
    private static void swapElements(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Function to maintain the heap property for a subtree with root 'index'
    private static void buildHeap(int[] arr, int size, int index) {
        int max = index;                // Set root as largest
        int leftChild = 2 * index + 1; // Left child
        int rightChild = 2 * index + 2; // Right child

        // Check if left child is larger than the current largest
        if (leftChild < size && arr[leftChild] > arr[max])
            max = leftChild;

        // Check if right child is larger than the current largest
        if (rightChild < size && arr[rightChild] > arr[max])
            max = rightChild;

        // If the largest is not root, swap and recurse
        if (max != index) {
            swapElements(arr, index, max);
            buildHeap(arr, size, max);
        }
    }

    // Function to perform heap sort on an array
    public static void performHeapSort(int[] arr) {
        int size = arr.length;

        // Build a max heap by rearranging the array
        for (int i = size / 2 - 1; i >= 0; i--)
            buildHeap(arr, size, i);

        // One by one extract the largest element from the heap
        for (int i = size - 1; i > 0; i--) {
            // Swap the root (largest) with the last element
            swapElements(arr, 0, i);

            // Call heapify on the reduced heap
            buildHeap(arr, i, 0);
        }
    }

    // Main method to test the heap sort algorithm
    public static void main(String[] args) {
        int[] arr = {45, 22, 16, 8, 4, 17, 30};

        System.out.println("Unsorted Array:");
        System.out.println(Arrays.toString(arr));

        performHeapSort(arr);

        System.out.println("Array after Heap Sort:");
        System.out.println(Arrays.toString(arr));
    }
}

