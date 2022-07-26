# Constructors

## Purpose of Constructors (ctors)

- Same name as class
- No return type
- Used to initialize objects at the time of creation
- Their storage is temporary since they are not static

## Types of constructors

### Default ctors

These take no arguments.

    Modifier ClassName() {
        // Empty or init the field to some vals
    }

    // call
    ClassName objectName = new ClassName();

###### Note: The compiler calls a default constructor automatically, which looks like this:

    ClassName() {}

### Parameterized ctors

This can accept paras of any type OTHER than that of its own class.

    Modifier ClassName(parameters) {
        // Empty or init the field to some vals
    }

    // call
    ClassName objectName = new ClassName(arguments);

### Copy ctors

This is a type of para ctor. The only diff is the type of the parameter. This ONLY accepts para types of its own class.

    Modifier ClassName(ClassName oldObjectReference) {
        // Empty or init the field to some vals
    }

    // call
    ClassName objectName = new ClassName(oldObjectReference)

## The difference between using Copy Ctors and Reference variables

##### Example:

*Using the following class definition*

    class Student {
        private String name;
        private String city;
        private double cgpa;

        // Default ctor
        public Student() {
            name = "Amit";
            city = "Bangalore";
            cgpa = 7.76;
        }

        // Parameterized ctor
        public Student(String name, String city, double cgpa) {
            this.name = name;
            this.city = city;
            this.cgpa = cgpa;
        }

        // Copy ctor where the parameter is an object of the same class
        public Student(Student A) {
            this.name = A.name;
            this.city = A.city;
            this.cgpa = A.cgpa;
        }

        public void putData() {
            System.out.println("Printing data:");
            System.out.println("Name: " + name);
            System.out.println("City: " + city);
            System.out.println("CGPA: " + cgpa);
            System.out.println();
        }
    }

    // int main()
    Student stu2 = new Student("Sumit", "Chennai", 8.81);

*Without using copy ctor:*

    Student stu2Copy = new Student(stu2);
    stu2Copy = stu2;
    stu2Copy.putData();

In this case, line `2` lets `stu2Copy` and `stu2` point to the same location in memory. Any changes in either object will reflect in the other.

*Using a copy ctor*

    Student stu2Copy = new Student(stu2);
    stu2Copy.putData();

Here, the two objects are stored at separate memory locations.