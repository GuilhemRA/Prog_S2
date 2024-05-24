#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << (*this).numerator << "/" << this->denominator;
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }


// Fraction sub(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction mul(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction div(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }


Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });    
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

bool operator==(Fraction const& f1, Fraction const& f2) {
    simplify({f1}); 
    simplify({f2});
    if(f1.numerator==f2.numerator && f1.denominator==f2.denominator) {
        return true;
    }
    else {
        return false;
    }
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    simplify({f1}); 
    simplify({f2});
    if(f1.numerator!=f2.numerator && f1.denominator!=f2.denominator) {
        return true;
    }
    if(f1.numerator!=f2.numerator || f1.denominator!=f2.denominator) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(Fraction const& f1, Fraction const& f2) {
    simplify({
        f1.numerator * f2.denominator, f1.denominator * f2.denominator
    }); 
    simplify({
        f2.numerator * f1.denominator, f1.denominator * f2.denominator
    });
    if(f1.numerator<f2.numerator) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    simplify({
        f1.numerator * f2.denominator, f1.denominator * f2.denominator
    }); 
    simplify({
        f2.numerator * f1.denominator, f1.denominator * f2.denominator
    });
    if(f1.numerator>f2.numerator) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    simplify({
        f1.numerator * f2.denominator, f1.denominator * f2.denominator
    }); 
    simplify({
        f2.numerator * f1.denominator, f1.denominator * f2.denominator
    });
    if(f1.numerator<=f2.numerator) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    simplify({
        f1.numerator * f2.denominator, f1.denominator * f2.denominator
    }); 
    simplify({
        f2.numerator * f1.denominator, f1.denominator * f2.denominator
    });
    if(f1.numerator>=f2.numerator) {
        return true;
    }
    else {
        return false;
    }
}

Fraction operator+=(Fraction &f1, Fraction const& f2) {
    f1 = simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
    return f1; 
}

Fraction operator-=(Fraction &f1, Fraction const& f2) {
    f1 = simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
    return f1;
}

Fraction operator*=(Fraction &f1, Fraction const& f2) {
    f1 = simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
    return f1;
}

Fraction operator/=(Fraction &f1, Fraction const& f2) {
    f1 = simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
    return f1;
}

float to_float(Fraction const& f1) {
    simplify({f1});
    float num = static_cast<float>(f1.numerator);
    float den = static_cast<float>(f1.denominator);
    return static_cast<float>(num/den);
}

Fraction::operator float() const {
        return to_float(*this);
    }