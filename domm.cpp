#include <iostream>
#include <cmath>
using namespace std;

class KompBr
{
    private:
    float real;
    float img;
    
    public:

    KompBr()
    {
        real = 1;
        img = 0;
    }
    KompBr(float real)
    {
        this->real=real;
        img = 0;
    }
    KompBr(float real, float img)
    {
        this->real=real;
        this->img=img;
    }
    
    KompBr operator+(KompBr y)
    {
        KompBr res(real+y.real, img+y.img);
        return res;
    }
    
    KompBr operator-(KompBr y)
    {
        KompBr res(real-y.real, img-y.img);
        return res;
    }
    KompBr operator*( KompBr y)
    {
        KompBr res(((real*y.real)-(img*y.img)),((real*y.img)+(img*y.real)));
        return res;
    }
    KompBr operator/(KompBr y)
    {
        KompBr res((real*y.real+img*y.img)/(y.real*y.real+y.img*y.img),(img*y.real-real*y.img)/(y.real*y.real+y.img*y.img));
        return res;
    }
    KompBr& operator~()
    {
        img=(-1)*img;
        return *this;
    }
    KompBr& operator-() //unarno
    {
        real=-real;
        img = -img;
        return *this;
    }
    float operator!()
    {
       return sqrt(real*real+img*img);
    }
    
    KompBr& operator=(KompBr y)
    {
        real = y.real;
        img = y.img;
        
        return *this;
    }
    
    bool operator==(KompBr y)
    {
        if(y.real==real and y.img == img)
        return true;
        
        return false;
    }
    
    bool operator!=(KompBr y)
    {
        if(y.real==real and y.img == img)
        return false;
        
        return true;
    }
    
    KompBr & operator++(int)
    {
        //postfix x++
        
        real++;
        return *this;
        
    }
    KompBr & operator++()
    {
        // prefix ++x
        real++;
        return *this;
    }
    
    KompBr & operator--(int)
    {
        real--;
        return *this;
        
    }
    KompBr & operator--()
    {
        real--;
        return *this;
    }
    float getterr()
    {
        return real;
    }
    float geteri()
    {
        return img;
    }
    void print()
    {
        cout << real << " " << img << "i\n";
    }
};

KompBr operator+(KompBr x, float y)
{
    KompBr m(x.getterr()+y, x.geteri());
    return m;
}

KompBr operator+(float y, KompBr x)
{
    KompBr m(x.getterr()+y, x.geteri());
    return m;
}



int main()
{
    KompBr a(5);
    KompBr b(10,4);
    KompBr c;
    a.print();
    b.print();
    c.print();
    c = a+b;
    c.print();
    c = a*b;
    c.print();
    c = a/b;
    c.print();
    c=b-a;
    c.print();
    cout << !b << "\n";
    b=~b;
    b.print();
    ++b;
    b.print();
    b--;
    b.print();
    a = -c;
    a.print();
    a = b+5;
    a.print();
    if(a!=b)
    cout << "NO";
    if(a==b)
    cout << 4;
    
    return 0;
}