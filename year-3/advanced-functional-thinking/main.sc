object Main extends App {
    val salaries = Seq(20_000, 70_000, 40_000)
    val doubleSalary = (x: Int) => x * 2
    val newSalaries = salaries.map(doubleSalary)
}