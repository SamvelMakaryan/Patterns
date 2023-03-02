public class Singleton {
    private static Singleton ob = null;
    private Singleton() {}
    public static Singleton constructor() {
        if (ob == null) {
            ob = new Singleton();
        }
        return ob;
    }
}
