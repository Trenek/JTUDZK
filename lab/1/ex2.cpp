#include <capd/capdlib.h>
#include <raylib.h>

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
    const capd::IVector v{0, 1};
    capd::C0HORect2Set set{v}; // Hermit Obreszkov?
    
    constexpr int taylorOrder = 20;

    const capd::interval T{M_PI / 2}; // czas końcowy

    capd::IMap f{f_node, 2, 2, 1};
    f.setParameter(0, 1);

    capd::IOdeSolver solver{f, taylorOrder};
    capd::ITimeMap map{solver};

    map(T, set); // set changes value, set = step(T, set)
    COUT(capd::IVector {set});

    return 0;
}
