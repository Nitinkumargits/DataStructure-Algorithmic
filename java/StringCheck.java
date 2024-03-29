class StringCheck {
    public static void main(String[] args) {

        String str = "progrmmer@gmail.com";
        int i = str.indexOf("@");
        String uName = str.substring(0, i);
        String domain = str.substring(i + 1, str.length());
        System.out.println("User name :" + uName);
        System.out.println("Domain name :" + domain);

    }
}