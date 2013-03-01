#ifdef  X_COMPLEX_H
#ifndef X_COMPLEX_CPP
#define X_COMPLEX_CPP



X::complexf operator+(X::complexf& a, X::complexf& b) {
    X::complexf c = {a[0]+b[0],a[1]+b[1]};
    return c;
}

X::complexf operator-(X::complexf& a,X::complexf& b) {
    X::complexf c = {a[0]-b[0],a[1]-b[1]};
    return c;
}

X::complexf operator*(X::complexf& a,X::complexf& b) {
    X::complexf c = {a[0]*b[0] - a[1]*b[1],a[0]*b[1] + a[1]*b[0]};
    return c;
}

X::complexf operator/(X::complexf& a,X::complexf& b) {
    float d = b[0]*b[0] + b[1]*b[1];
    X::complexf c = {(a[0]*b[0] + a[1]*b[1]) / d , (a[1]*b[0] - a[0]*b[1] ) / d };
    return c;
}


#endif
#endif
