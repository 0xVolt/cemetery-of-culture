public class NameException extends Exception {
    public NameException() {
        super("The name cannot be an integer.");
    }

    public NameException(String message) {
        super(message);
    }
}