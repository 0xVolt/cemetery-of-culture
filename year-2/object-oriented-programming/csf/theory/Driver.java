class Player
{

  String name;
  int age;
  double weight;
  Player(String n,int a, double wt)

{
    name = n;

    age = a; 

    weight = wt;
}

  void show()

   {

     System.out.println("Player name: "+name);

     System.out.println("Age: "+age);

     System.out.println("Weight: "+weight);
    }

}

class Player_Cricket extends Player

{

  String game;

  Player_Cricket(String n,String g,int a, double wt)

  {

     super(n,a,wt );

     game=g;

  }

  public void show()

  {

     super.show();

     System.out.println("Game : "+game);

  }

}

class Player_Football extends Player

  {

     String game;

     Player_Football(String n,String g,int a,double wt)

  {

     super(n,a,wt);

     game=g;

  }

   public void show()

   {

     super.show();

     System.out.println("Player game : "+game);

   }

}

class Player_Hockey extends Player

{

   String game; 

   Player_Hockey(String n,String g,int a,double wt)

   {

      super(n,a,wt);

      game=g;

   }

   public void show()

   {

      super.show();

      System.out.println("Player game : "+game);

   }

}

class Driver

{

   public static void main(String args[])

   {

     Player_Cricket cp=new Player_Cricket("Max","Cricket",19,60.2);

     Player_Football fp=new Player_Football("Rohit","Football",20,55.8);

     Player_Hockey hp=new Player_Hockey("Bharat","Hockey",15,69.5);

     cp.show();

     fp.show();

     hp.show();

   }
}