/******************************************************************
* Ramin Rakhamimov
* Description a Rational number ADT implementation.
*
* Usage:
*   [ramin@home ~/OOP]$ javac Rational.java && java Rational
*   > 100/50 * 2/1
*   4 / 1
*
*   > 20/50 + 1/50
*   21 / 50
*
*   > 33/50 - 3/50
*   3 / 5
*
*   > 33/50 - -3/50
*   18 / 25
*
*   > 20/50 + -1/50
*   19 / 50
*
*   > 1/2 / 1/2
*   1
*
*   > 1/2 * 2
* 1
*
*   > q
*   [ramin@home ~/OOP]$
*******************************************************************/
 
import java.util.Scanner;
 
public class Rational
{
  private final int numerator_;
  private final int denominator_;
 
  public Rational(int numerator, int denominator)
  {
    int gcd = euclidGcd(numerator, denominator);
    numerator_ = numerator / gcd;
    denominator_ = denominator / gcd;
  }
 
  public Rational(int numb)
  {
    this(numb, 1);
  }
 
  public static Rational constructRational(String rational)
  {
    String[] tokens = rational.split("/");
    if(tokens.length == 1)
      return new Rational(Integer.parseInt(tokens[0]));
    else if(tokens.length == 2)
      return new Rational(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
    else
      throw new RuntimeException("Incorrect input");
 
  }
  public Rational add(Rational other)
  {
    int newNumerator = (numerator_ * other.denominator_) +
    (other.numerator_ * denominator_) ;
    int newDenominator = denominator_ * other.denominator_;
    return new Rational(newNumerator, newDenominator);
  }
 
  public Rational sub(Rational other)
  {
    return add(new Rational(-other.numerator_, other.denominator_));
  }
 
  public Rational mult(Rational other)
  {
    return new Rational(numerator_ * other.numerator_,
        denominator_ * other.denominator_);
  }
 
  public Rational div(Rational other)
  {
    return mult(new Rational(other.denominator_, other.numerator_));
  }
 
  public static int euclidGcd(int x, int y)
  {
    if(y == 0)
      return x;
    return euclidGcd(y, x % y);
  }
 
  public String toString()
  {
    if(numerator_ == denominator_)
      return "1";
    if(denominator_ == 1)
      return numerator_ + "";
    return String.format("%s/%s", numerator_, denominator_);
  }
 
  public static void main(String...args)
  {
    while(true)
    {
      System.out.print("> ");
      Scanner scanner = new Scanner(System.in);
 
      try
      {
        String firstInput = scanner.next();
        if(firstInput.startsWith("q") || firstInput.startsWith("Q"))
          return;
        Rational r1 = constructRational(firstInput);
        char op = scanner.next().charAt(0);
        Rational r2 = constructRational(scanner.next());
 
        switch(op)
        {
          case '+':
            System.out.println(r1.add(r2));
            break;
          case '-':
            System.out.println(r1.sub(r2));
            break;
          case '*':
            System.out.println(r1.mult(r2));
            break;
          case '/':
            System.out.println(r1.div(r2));
            break;
          default:
            System.err.println("Incorrect input!");
        }
        System.out.println();
      }
      catch(Exception e)
      {
        System.err.println("Usage: [operand] [operator] [operand]");        
      }
    }
  }
}
