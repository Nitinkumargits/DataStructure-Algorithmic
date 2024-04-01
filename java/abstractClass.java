abstract class Super {
    public Super() {
        System.out.println("Super constructor");
    }

    public void meth1() {
        System.out.println("meth1 of super");
    }

    abstract public void meth2();
}

class Sub extends Super {
    public void meth2() {
        System.out.println("sub meth2");
    }
}

class abstractClass {
    public static void main(String[] args) {
        Super s = new Sub();
        s.meth1();
        s.meth2();
    }

}