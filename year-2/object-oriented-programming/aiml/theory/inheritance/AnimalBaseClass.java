package Inheritance;

public class AnimalBaseClass {
    private String name;
    private int size;
    private int weight;
    private int averageLifetime;

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getSize() {
        return this.size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public int getWeight() {
        return this.weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getAverageLifetime() {
        return this.averageLifetime;
    }

    public void setAverageLifetime(int averageLifetime) {
        this.averageLifetime = averageLifetime;
    }

    public AnimalBaseClass(String name, int size, int weight, int avg) {
        this.name = name;
        this.weight = weight;
        this.size = size;
        this.averageLifetime = avg;

        System.out.println("Parent ctor");
    }

    public AnimalBaseClass() {

    }
}