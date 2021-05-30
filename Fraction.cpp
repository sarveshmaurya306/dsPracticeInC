
class Fraction{
    private:
        int numerator;
        int denominator;
        static int totalFractionClass; //static member declaration
    public:
        Fraction(int numerator=1, int denominator=1){
            this->numerator = numerator;
            this->denominator = denominator;
            totalFractionClass += 1;
        }
        void print(){
            cout << numerator << "/" << denominator<<endl;
        }
        void simplify(){
            int gcd = 1;
            int j = min(numerator, denominator);
            for (int i = 1; i <= j;i++){
                if(numerator%i==0 && denominator%i==0){
                    gcd = i;
                }
            }
            numerator = numerator / gcd;
            denominator = denominator / gcd;
        }
        Fraction const add(Fraction const &f2){
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;

            int num = x * numerator + (y * f2.numerator);
            Fraction fnew(num, lcm);
            
            fnew.simplify();
            return fnew;
        }

        Fraction const multiply(Fraction const &f2){
            int n = numerator * f2.numerator;
            int d = denominator * f2.denominator;
            Fraction fnew(n, d);
            fnew.simplify();
            return fnew;
        }

        //operator overloading;
        Fraction const operator+(Fraction const &f2){
            int lcm = denominator * f2.denominator;
            int x = lcm / denominator;
            int y = lcm / f2.denominator;

            int num = x * numerator + (y * f2.numerator);
            Fraction fnew(num, lcm);
            
            fnew.simplify();
            return fnew;
        }

        Fraction const operator*(Fraction const &f2){
            int n=numerator * f2.numerator;
            int d=denominator * f2.denominator;
            Fraction fnew(n, d);
            fnew.simplify();
            return fnew;
        }

        bool operator==(Fraction &f2){
            return numerator == f2.numerator && denominator == f2.denominator;
        }
        //preincrement
        Fraction& operator++(){
            numerator = numerator + denominator;
            simplify();
            return *this; //return whole value by with reference
        }
        //postincrement
        Fraction operator++(int){
            Fraction fnew(numerator, denominator);
            numerator = numerator + denominator;
            simplify();
            fnew.simplify();
            return fnew;
        }


        //static function   
        static int getTotalClass(){
            return totalFractionClass;
        }
};

int Fraction :: totalFractionClass=0; //static member initialization