// Code by Desh Iyer

// PROBLEM STATEMENT
// Write a program in Java to create a Player class. Inherit the classes Cricket _Player, Football _Player and Hockey_ Player from Player class. 

public class q2 {
    public static void main(String[] args) {
        Player P = new Player("P1", 10);
        P.printData();
        
        Cricket_Player C = new Cricket_Player("CP1", 11, "RCB");
        C.printData();

        Football_Player F = new Football_Player("FP1", 12, "Manchester United");
        F.printData();

        Hockey_Player H = new Hockey_Player("HP1", 13, "Indian Olympic Team");
        H.printData();
    }
}

class Player {
    public String playerName;
    public int playerNumber;

    public Player() {}

    public Player(String a, int c) {
        playerName = a;
        playerNumber = c;
    }

    public void printData() {
        // System.out.println("\n\nPrinting Player details");
        System.out.printf("\nPlayer Name: %s\nPlayer Number: %d", playerName, playerNumber);
    }
}

class Cricket_Player extends Player {
    public String cricketPlayerTeam;
    
    public Cricket_Player() {}
    
    public Cricket_Player(String a, int b, String c) {
        super(a, b);
        cricketPlayerTeam = c;
    }
    
    public void printData() {
        System.out.println("\n\nPrinting Cricket Player details");
        super.printData();
        System.out.printf("\nCricket Player's Team: %s", cricketPlayerTeam);
    }
}

class Football_Player extends Player {
    public String footballPlayerTeam;
    
    public Football_Player() {}
    
    public Football_Player(String a, int b, String c) {
        super(a, b);
        footballPlayerTeam = c;
    }
    
    public void printData() {
        System.out.println("\n\nPrinting Football Player details");
        super.printData();
        System.out.printf("\nFootball Player's Team: %s", footballPlayerTeam);
    }
}

class Hockey_Player extends Player {
    public String hockeyPlayerTeam;
    
    public Hockey_Player() {}
    
    public Hockey_Player(String a, int b, String c) {
        super(a, b);
        hockeyPlayerTeam = c;
    }
    
    public void printData() {
        System.out.println("\n\nPrinting Hockey Player details");
        super.printData();
        System.out.printf("\nHockey Player's Team: %s", hockeyPlayerTeam);
    }
}
