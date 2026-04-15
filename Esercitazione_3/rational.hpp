#pragma once
#include <concepts>
#include <numeric>
using namespace std;

template<typename I> requires std::integral<I>
class rational
{
    I num_;
    I den_;
    bool inf=0;
    bool nan=0;
    bool neg=0;

public:
    /* Costruttore di default */
    rational() : num_(I{0}), den_(I{1})
    {}
    
    /* Costruttore di conversione*/
    explicit rational(I n) : num_(n), den_(1)
    {}

    /* Costruttore user-defined */
    rational(const I& n, const I& d) : num_(n), den_(d)
    {
        /*num_(n);
        den_(d);*/
        if(num_ != 0 && den_ == 0) inf=1;
        else if(num_ == 0 && den_ == 0) nan=1;
        else if((num_<0 || den_<0) && !(num_<0 && den_<0)){
            neg=1;
            if (den_<0){
                den_ *= -1;
                num_ *= -1;
            }
        }
        else if(num_<0 && den_<0){
            den_ *= -1;
            num_ *= -1;
        }
        I div=gcd(num_, den_);
        num_ /= div;
        den_ /= div;
    }

    /* Restituiscono i valori di numeratore e denominatore */
    I num() const { return num_; }
    I den() const { return den_; }

    /* Implementazione += */
    rational& operator+=(const rational& other) {
        if(nan || other.nan){
            nan=1;
            return *this;
        }
        else if(inf || other.inf){
            if((inf && !other.inf)){
                return *this;
            }
            else if(!inf && other.inf){
                *this = other;
                return *this;
            }
            else if(neg != other.neg){
                nan=1;
                return *this;
            }
            else return *this;
        }
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        I div=gcd(num_, den_);
        num_ /= div;
        den_ /= div;
        return *this;
    }
    
    /* Implementazione + */
    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }


    /* Implementazione -= */
    rational& operator-=(const rational& other) {
        /*
        if(nan) return *this;
        else if(inf){
            if(other.inf || other.nan){
                nan=1;
                return *this;
            }
            else return *this;
        }
        d = den_ * other.den_;
        n = (num_*d/den_) - (other.num_*d/other.den_);
        num_ = n;
        den_ = d;
        */

        rational temp=other;
        temp.neg = !temp.neg;
        temp.num_ *= -1;
        *this += temp;
        return *this;
    }
    
    /* Implementazione - */
    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        return ret;
    }


    /* Implementazione *= */
    rational& operator*=(const rational& other) {
        if(nan || other.nan){
            nan=1;
            return *this;
        }
        else if(inf || other.inf){
            inf=1;
            if(neg != other.neg) neg=1;
            else neg=0;
            return *this;
        }
        num_ *= other.num_;
        den_ *= other.den_;
        I div=gcd(num_, den_);
        num_ /= div;
        den_ /= div;
        return *this;
    }
    
    /* Implementazione * */
    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        return ret;
    }


    /* Implementazione /= */
    rational& operator/=(const rational& other) {
        if(other.num_ == 0){
            nan=1;
            return *this;
        }
        else if(nan || other.nan){
            nan=1;
            return *this;
        }
        else if(inf || other.inf){
            if(inf && !other.inf) return *this;
            else if(!inf && other.inf){
                num_=0;
                return *this;
            }
            else{
                nan=1;
                return *this;
            }
        }
        rational inv(other.den_, other.num_);
        *this *= inv;
        return *this;
    }
    
    /* Implementazione / */
    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        return ret;
    }
};


template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
    os << "(" << r.num() << "/" << r.den() << ")";
    return os;
}