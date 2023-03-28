public class Multyton {
    private static int currentCount = 0;
    private static final int count = 3;
    private static Multyton ob1 = null;
    private static Multyton ob2 = null;
    private static Multyton ob3 = null;
    private Multyton() {};
    public static Multyton constructor () {
        if (currentCount == count) {
            currentCount = 0;
        }
        switch (currentCount % count) {
            case 0 -> {
                ++currentCount;
                if (ob1 == null) {
                    ob1 = new Multyton();
                }
                return ob1;
            }
            case 1 -> {
                ++currentCount;
                if (ob2 == null) {
                    ob2 = new Multyton();
                }
                return ob2;
            }
            case 2 -> {
                ++currentCount;
                if (ob3 == null) {
                    ob3 = new Multyton();
                }
                return ob3;
            }
            default -> {
                return null;
            }
        }
    }
}
