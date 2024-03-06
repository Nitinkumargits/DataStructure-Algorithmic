class maxConsecutiveOnes {

    static public int getMaxLength(boolean arr[], int size) {
        int count = 0;
        int result_count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == false) {
                count = 0;
            } else {

                count++;

                result_count = Math.max(result_count, count);
            }
        }
        return result_count;
    }

    public static void main(String[] args) {
        boolean arr[] = { true, true, false, false,
                true, false, true, false,
                true, true, true, true };

        int n = arr.length;

        System.out.println(getMaxLength(arr, n));
    }
}