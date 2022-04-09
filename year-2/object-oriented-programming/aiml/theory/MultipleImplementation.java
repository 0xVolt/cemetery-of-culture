interface ElectronicsDevice {
    void powerOn();
}

interface TelephoneDevice {
    void powerOff();
}

class DesktopTelephoneExample implements ElectronicsDevice, TelephoneDevice {
    // private int phNumber;

    public DesktopTelephoneExample(int n) {
        // this.phNumber = n;
    }

    @Override 
    public void powerOn() {
        System.out.println("Powered On!");
    }

    @Override
    public void powerOff() {
        System.out.println("Powered Off!");
    }
}

public class MultipleImplementation {
    public static void main(String[] args) {
        DesktopTelephoneExample D = new DesktopTelephoneExample(12345);

        D.powerOn();
        D.powerOff();
    }
}
