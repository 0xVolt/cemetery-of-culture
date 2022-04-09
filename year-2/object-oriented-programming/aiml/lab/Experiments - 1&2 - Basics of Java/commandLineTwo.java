public class commandLineTwo {
    public static void main(String[] args) {
        Point a, b, c;
        float t;
        a = new Point();

        int arg1 = Integer.parseInt(args[0]);
        int arg2 = Integer.parseInt(args[1]);

        a.getPoint(arg1, arg2);
        a.print();
        a.abc();
        a.print();
        b = Point.pqr(a);
        b.print();
        a = new Point();


        a.getPoint(arg1, arg2);
        c = new Point();
        c.ghi(a);
        c.print();
        t = a.getx();
        System.out.println(t);

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
}
