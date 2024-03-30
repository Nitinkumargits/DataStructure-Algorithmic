class Television {

    private int channel;
    private int volume;

    public void changeChannel() {
        System.out.println("Channel change ");
    }

    public void changeVolume() {
        System.out.println("Volume changed");
    }

}

class Tele {
    public static void main(String[] args) {
        Television t = new Television();
        t.changeChannel();
        t.changeVolume();
    }
}