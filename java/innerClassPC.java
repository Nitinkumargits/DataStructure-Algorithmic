class OuterClass {
    int x = 10;

    public class Inner {

        int y = 20;

        void innerDisplay() {
            System.out.println("Inner method :" + x);
            System.out.println(y);
        }

    }

    void outerDisplay() {
        Inner i = new Inner();
        i.innerDisplay();
        System.out.println(i.y);
    }
}

class innerClassPC {
    public static void main(String[] args) {

        OuterClass o = new OuterClass();
        // System.out.println(o.x);

        o.outerDisplay();
        OuterClass.Inner oi = new OuterClass().new Inner();
        // oi.innerDisplay();
    }

}
