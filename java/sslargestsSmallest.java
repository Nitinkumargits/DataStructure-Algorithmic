import java.util.Arrays;

class sslargestsSamllest {

    public static int SecondLargest(int a[], int n) {
        int largest = a[0];
        int slargest = -1;

        for (int i = 0; i < n; i++) {

            if (a[i] > largest) {
                slargest = largest;
                largest = a[i];
            } else if (a[i] < largest && a[i] > slargest) {
                slargest = a[i];
            }
        }

        return slargest;
    }

    public static int SecondSmallest(int a[], int n) {
        int smallest = a[0];
        int sSmallest = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (a[i] < smallest) {
                sSmallest = smallest;
                smallest = a[i];
            } else if (a[i] < sSmallest && a[i] != smallest) {
                sSmallest = a[i];
            }
        }

        return sSmallest;
    }

    public static int[] SecondOrderElement(int a[]) {
        int n = a.length;
        int SecondLarge = SecondLargest(a, n);
        int SecondSmalle = SecondSmallest(a, n);
        return new int[] { SecondLarge, SecondSmalle };
    }

    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4, 5 };
        System.out.println(Arrays.toString(SecondOrderElement(arr)));

    }
}