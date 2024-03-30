class Parent {
    public Parent() {
        System.out.println("Non-param of parent ");
    }

    public Parent(int x) {
        System.out.println("Param of parent " + x);

    }
}

class Child extends Parent {
    public Child() {
        System.out.println("Non-param of child constructor");
    }

    public Child(int x, int y) {
        super(x);
        System.out.println("Param of chlid " + y);

    }
}

class superConstructor {
    public static void main(String[] args) {

        Child c = new Child();

    }
}
