public class defineFA {
    public static void main(String[] args) {
        Point a;
        a = new Point();

        int arg1 = Integer.parseInt(args[0]);
        int arg2 = Integer.parseInt(args[1]);

        a.getPoint(arg1, arg2);
        a.print();

        a.fa();
        a.print();
    }
}

class Point {
    private float x, y;

    public void getPoint(float a, float b) {
        x = a;
        y = b;
    }

    public void print() {
        System.out.println("(" + x + "," + y + ")");
    }

    public void abc() {
        x = 2 * x;
        y = 3 * y;
    }

    public static Point pqr(Point a) {
        Point t;
        t = new Point();
        t.getPoint(2 * a.x, 2 * a.y);
        return t;
    }

    public void ghi(Point a) {
        x = 2 * a.x;
        y = 3 * a.y;
    }

    public float getx() {
        return x;
    }

    public void fa() {
        x = x + y;
        y = 2 * y;
    }
}
