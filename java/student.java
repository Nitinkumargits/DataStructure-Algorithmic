import javax.swing.text.html.StyleSheet;

class StudentTEST {

    private String subID;
    private String name;
    private int maxMarks;
    private int marksObtain;

    public void subject(String subID, String name, int maxMarks) {
        this.subID = subID;
        this.name = name;
        this.maxMarks = maxMarks;
    }

    public String getSubID() {
        return subID;
    }

    public String getName() {
        return name;
    }

    public int getMaxMarks() {
        return maxMarks;
    }

    public int getMarkObtain() {
        return marksObtain;
    }

    public void setMaxMarks(int mm) {
        maxMarks = mm;
    }

    public void setMarkObtain(int m) {
        marksObtain = m;
    }

    boolean isQualified() {
        return marksObtain >= maxMarks / 10 * 4;
    }

    public String toString() {
        return "\n Subject ID :" + subID + "\nName :" + name + "\nMarks obtained :" + marksObtain;
    }

}

/**
 * mainStudent
 */
class student {

    public static void main(String[] args) {

        StudentTEST st = new StudentTEST();
        st.setMarkObtain(123);
        System.out.println(st.getMarkObtain());
        ;

    }
}
