public class AgeException extends Exception{
    public AgeException() {
        super("Age is too high.");
    }

    public AgeException(String message) {
        super(message);
    }
}