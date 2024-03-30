public class inheritance {
    private double radius;

    public inheritance() {
        radius = 0.0;
    }

    public void area() {
        System.out.println("area");
    }

    public void perimeter() {
        System.out.println("Perimeter");
    }
}

class Cyclinder extends inheritance {
    private double height;

    public Cyclinder(double height) {
        this.height = height;
    }
}