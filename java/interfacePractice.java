class Phone {
    public void call() {
        System.out.println("Phone call");

    }

    public void Sms() {
        System.out.println("phone SMS");
    }
}

/**
 * ICamer
 * 
 */
interface ICamer {
    void click();

    void record();
}

interface IMusicPlayer {
    void play();

    void stop();
}

class SmartPhone extends Phone implements ICamer, IMusicPlayer {
    public void videoCall() {
        System.out.println("SmartPhone video calling");
    }

    public void record() {
        System.out.println("SP record");
    }

    public void click() {
        System.out.println("sp click");

    }

    public void play() {
        System.out.println("sp play");
    }

    public void stop() {
        System.out.println("sp stop");
    }

}

public class interfacePractice {
    public static void main(String[] args) {
        ICamer sp = new SmartPhone();
        sp.click();
        sp.record();

    }

}
