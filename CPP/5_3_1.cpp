#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
    virtual ~Expression() { }
};

struct Number : Expression
{
    Number(double value):value(value){};
    double evaluate() const {return value;};

    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
    :left(left), op(op), right(right){};
    ~BinaryOperation(){};
    double evaluate() const{
        return 1.;
    };

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout<<number->get_value()<<" ";
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        bop->get_left()->visit(this);
        std::cout<<bop->get_op()<<" ";
        bop->get_right()->visit(this);
    }
};


struct ScopedPtr
{
    //запрет неявного преобразования типов
    explicit ScopedPtr(Expression* ptr = 0){
        this->ptr_ = ptr;
    };
    ~ScopedPtr(){
        delete this->ptr_;
    };
    Expression* get() const{
        return this->ptr_;
    };
    Expression* realease(){
        Expression* ptr = this->ptr_;
        this->ptr_=NULL;
        return ptr;
    };
    void reset(Expression* ptr = 0){
        delete this->ptr_;
        this->ptr_ = ptr;
    };
    Expression& operator *() const{
        return *this->ptr_;
    };
    Expression* operator ->()const{
        return ptr_;     
    };

private:
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator =(const ScopedPtr&);

    Expression* ptr_;
};



int main(){
    Number num(5);
    ScopedPtr ptr(&num);
    // std::cout<<*ptr<<'\n';
}