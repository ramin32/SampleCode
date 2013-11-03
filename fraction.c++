/*******************************************************
 * fraction.c++
 *
 * ADT representation of a fraction with intuitive overloaded operators.
 * Also allows direct IO with object
 * ie: 
 *     Fraction f;
 *     cin >> Fraction
 *     cout >> Fraction;
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ******************************************************/ 
#include <iostream>

class Fraction{
    private:
        int num;
        int denom;
    public:
        Fraction(){}
        Fraction(int num,int denom){
            this->num = num;
            this->denom = denom;
        }
        Fraction operator+(Fraction other){
            int num = this->num * other.denom + other.num * this->denom;
            int denom = this->denom * other.denom;

            return Fraction(num,denom);
        }
        Fraction operator-(Fraction other){
            int num = this->num * other.denom - other.num * this->denom;
            int denom = this->denom * other.denom;
            return Fraction(num,denom);
        }
        void operator=(Fraction other){
            this->num = other.num;
            this->denom = other.denom;
        }
        Fraction operator*(Fraction other){
            int num = this->num * other.num;
            int denom = this->denom * other.denom;
            return Fraction(num,denom);
        }
        Fraction operator/(Fraction other){
            int num = this->num * other.denom;
            int denom = this->denom * other.num;
            return Fraction(num,denom);

        void simplify(){
            for(int i=num;i >0;i--){
               if(num % i == 0 && denom % i == 0){
                  num/=i;
                  denom/=i;
               }
            }
        }
        friend std::ostream& operator<<(std::ostream&, Fraction&);
        friend std::istream& operator>>(std::istream&, Fraction&);
};

std::ostream& operator<<(std::ostream& output, Fraction& f){
    output << "(" <<  f.num << "/" << f.denom <<")";
    return output;  
}

std::istream& operator>>(std::istream& input, Fraction& f){
    int num;
    char slash;
    int denom;
    input >> num >> slash >> denom;
    f = Fraction(num,denom);
}

int main(){
    Fraction f1,f2;
    Fraction result;
    char op;
    bool success;
    while(1){
        success = true;
        std::cout << "Enter first fraction: ";
        std::cin >> f1 ;
        std::cout << "Enter second fraction: ";
        std::cin >> f2;
        std::cout << "Enter operation (+ - * /): ";
        std::cin >> op;

        switch(op){
            case 'a':
                result = f1 + f2;
                break;
            case 's':
                result = f1-f2;
                break;
            case 'm':
                result = f1*f2;
                break;
            case 'd':
                result = f1/f2;
                break;

            default:
                success = false
                std::cout << "Wrong usage." << std::endl;
        }
        if(success)
            std::cout << f1 << op << f2 << " = " << result;
    }
}

