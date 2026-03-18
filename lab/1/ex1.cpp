#include <capd/capdlib.h>
#include <raylib.h>

// #define STRING

void f_node(
    capd::autodiff::Node &time,
    capd::autodiff::Node in[],
    int dimIn,
    capd::autodiff::Node out[],
    int dimOut,
    capd::autodiff::Node param[],
    int noParam
) {
    out[0] = - param[0] * in[1];
    out[1] = in[0];
}

int main() {
#ifndef STRING
    capd::IMap f{f_node, 2, 2, 1};
    f.setParameter(0, 3);
#else
    capd::IMap f("par:a;var:x,y;fun:-a*y,x;");
    f.setParameter("a", 3);
#endif

    capd::IVector v{1, 0};
    COUT(v);
    COUT(f(v));

    return 0;
}
