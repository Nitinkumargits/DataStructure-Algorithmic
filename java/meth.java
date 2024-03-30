public class meth {
    static int max(int x, int y) {
        if (x > y)
            return x;
        else
            return y;
    }

    public static void main(String[] args) {
        int a, b;
        a = 10;
        b = 20;
        System.out.println(max(a, b));
    }
}
