class flippingBits {

    public static long flippBit(long n) {
        long num = (1L << 32) - 1;
        return n ^ num;
    }

    public static void main(String[] args) {

        long flip = flippBit(2147483647);
        System.out.println(flip);

    }
}