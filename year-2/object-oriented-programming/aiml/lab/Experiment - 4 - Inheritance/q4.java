// Code by Desh Iyer

// PROBLEM STATEMENT
// Consider the trunk calls of a telephone exchange. A trunk call can be ordinary, urgent or lightning. The charges depend on the duration and the type of the call. Write a program using the concept of polymorphism in Java to calculate the charges.

// CONSIDER
// 1 rs - ordinary
// 3 rs - urgent
// 5 rs - lightning

class Trunk {
    public String callerName;
    public float callDurationMins;
    public float callCharge;
    
    public Trunk() {}
    
    public Trunk(String a, float b) {
        callerName = a;
        callDurationMins = b;
        callCharge = 0;
    }

    public void calcCharge(float callRate) {
        callCharge = callDurationMins * callRate;
    }

    public void printData() {
        System.out.printf("Caller Name: %s\nCall Duration (Mins): %.3f\n\n", callerName, callDurationMins);
    }
}

class Ordinary extends Trunk {
    public float callRate;

    public Ordinary() {}
    
    public Ordinary(String a, float b) {
        super(a, b);
        callRate = 1;
    }

    public void calcCharge() {
        super.calcCharge(callRate);
    }

    public void printData() {
        System.out.printf("Caller Name: %s\nCall Duration (Mins): %.3f\nOrdinary Call Rate = Rs. 1\nCall Charge: Rs. %.3f\n\n", callerName, callDurationMins, callCharge);
    }
}

class Urgent extends Trunk {
    public float callRate;

    public Urgent() {}
    
    public Urgent(String a, float b) {
        super(a, b);
        callRate = 3;
    }

    public void calcCharge() {
        super.calcCharge(callRate);
    }

    public void printData() {
        System.out.printf("Caller Name: %s\nCall Duration (Mins): %.3f\nUrgent Call Rate = Rs. 3\nCall Charge: Rs. %.3f\n\n", callerName, callDurationMins, callCharge);
    }
}

class Lightning extends Trunk {
    public float callRate;

    public Lightning() {}
    
    public Lightning(String a, float b) {
        super(a, b);
        callRate = 5;
    }

    public void calcCharge() {
        super.calcCharge(callRate);
    }

    public void printData() {
        System.out.printf("Caller Name: %s\nCall Duration (Mins): %.3f\nLightning Call Rate = Rs. 5\nCall Charge: Rs. %.3f\n\n", callerName, callDurationMins, callCharge);
    }
}

public class q4 {
    public static void main(String[] args) {
        Trunk trunkCall = new Trunk("TC1", 3.5f);
        trunkCall.printData();

        Ordinary ordinaryCall = new Ordinary("OC1", 5f);
        ordinaryCall.calcCharge();
        ordinaryCall.printData();
        
        Urgent urgentCall = new Urgent("UC1", 10f);
        urgentCall.calcCharge();
        urgentCall.printData();
        
        Lightning lightningCall = new Lightning("LC1", 2.45f);
        lightningCall.calcCharge();
        lightningCall.printData();
    }
}
