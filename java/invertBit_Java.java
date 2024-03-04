import java.io.*;

class invertBit_Java {
    static void invertBit(int num) {
        // calc number of bits in number
        int x = (int) (Math.log(num) / Math.log(2)) + 1;
        // Invert the bits one by one
        for (int i = 0; i < x; i++) {
            num = (num ^ (1 << i));
        }
        System.out.println(num);
    }

    public static void main(String[] args) {
        int num = 11;
        invertBit(num);

    }
}