#include <iostream>

struct Rational{
    Rational(int numerator = 0, int denominator =1){
        numerator_ = numerator;
        denominator_ =denominator;
    };
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);
    void neg();
    void inv();

    Rational& operator +=(Rational const& s){
        this->add(s);
        return *this;
    }
    Rational& operator +=(int d){
        this->add(Rational(d));
        return *this;
    }
    Rational& operator -=(Rational const& s){
        this->add(s);
        return *this;
    }
    Rational& operator -=(int d){
        this->add(Rational(d));
        return *this;
    }
    Rational& operator *=(Rational const& s){
        this->add(s);
        return *this;
    }
    Rational& operator *=(int d){
        this->add(Rational(d));
        return *this;
    }
    Rational& operator /=(Rational const& s){
        this->add(s);
        return *this;
    }
    Rational& operator /=(int d){
        this->add(Rational(d));
        return *this;
    }

    Rational operator -()const{
        return Rational(-this->numerator_, this->denominator_);
    }
    Rational operator +()const{
        return *this;
    }

    double to_double() const{
        if (denominator_!=0){
            return (double)numerator_/denominator_;
        }else{
            return 0;
        }
    };
    operator double(){
        return this->to_double();
    }
    int get_numerator() const {
        return numerator_;
    }
    int get_denominator() const {
        return denominator_;
    }
private:
    int numerator_;
    int denominator_;
};

bool operator ==(Rational const& r1, Rational const& r2){
    if (r1.get_numerator()*r2.get_denominator() == r2.get_numerator()*r1.get_denominator()){
        return true;
    }
    return false;
}
bool operator ==(Rational const& r1, int r2){
    if (r1.get_numerator() == r2 * r1.get_denominator())
    {
        return true;
    }
    return false;
}
bool operator ==(int r1, Rational const& r2){
    if (r1 * r2.get_denominator() == r2.get_numerator())
    {
        return true;
    }
    return false;
}

bool operator !=(Rational const& r1, Rational const& r2){
    return !(r1==r2);
}

bool operator !=(Rational const& r1, int r2){
    return !(r1==r2);
}
bool operator !=(int r1, Rational const& r2){
    return !(r1==r2);
}

bool operator <(Rational const& r1, Rational const& r2){
    if (r1.get_numerator()*r2.get_denominator() < r2.get_numerator()*r1.get_denominator()){
        return true;
    }
    return false;
}
bool operator <(Rational const& r1, int r2){
    if (r1.get_numerator() < r2 * r1.get_denominator())
    {
        return true;
    }
    return false;
}
bool operator <(int r1, Rational const& r2){
    if (r1 * r2.get_denominator() < r2.get_numerator())
    {
        return true;
    }
    return false;
}

bool operator >(Rational const& r1, Rational const& r2){
    return r2<r1;
}
bool operator >(Rational const& r1, int r2){
    return r2<r1;
}
bool operator >(int r1, Rational const& r2){
    return r2<r1;
}

bool operator <=(Rational const& r1, Rational const& r2){
    return !(r2<r1);
}
bool operator <=(Rational const& r1, int r2){
    return !(r2<r1);
}
bool operator <=(int r1, Rational const& r2){
    return !(r2<r1);
}

bool operator >=(Rational const& r1, Rational const& r2){
    return !(r2>r1);
}
bool operator >=(Rational const& r1, int r2){
    return !(r2>r1);
}
bool operator >=(int r1, Rational const& r2){
    return !(r2>r1);
}



int main(){
    Rational rat1(40, 21);
    Rational rat2(30, 4);
    Rational rat3(80, 42);
    // std::cout<<rat1.to_double()<<'\n';
    // std::cout<<rat2.to_double()<<'\n';
    bool sign = rat1==rat3;
    std::cout<<sign<<'\n';
}