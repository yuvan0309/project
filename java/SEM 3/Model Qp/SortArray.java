public class SortArray {

    public static void main(String[] args) {
      int[] arr = {5, 2, 8, 7, 1};
      int temp;
  
      System.out.println("Original array:");
      for (int i = 0; i < arr.length; i++) {
        System.out.print(arr[i] + " ");
      }
      System.out.println();
  
      for (int i = 0; i < arr.length - 1; i++) {
        for (int j = i + 1; j < arr.length; j++) {
          if (arr[i] > arr[j]) {
            // Swap elements
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
          }
        }
      }
  
      System.out.println("Sorted array:");
      for (int i = 0; i < arr.length; i++) {
        System.out.print(arr[i] + " ");
      }
    }
  }
  