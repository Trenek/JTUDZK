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

void mapDebug(const char *name, capd::ITimeMap &map, capd::C0HORect2Set &set, const capd::interval T) {
    map(T, set); // set changes value, set = step(T, set)
    std::cout << name << std::endl;
    COUT(map.getStep());
    COUT(capd::IVector{set});
    std::cout << std::endl;
}

int main() {
    const capd::IVector v{0, 1};
    constexpr int taylorOrder = 20;

    capd::C0HORect2Set set{v}; // Hermit Obreszkov?

    const capd::interval T{M_PI / 2}; // Czas Końcowy
    const capd::interval H{capd::interval{1} / 256};

    capd::interval curve_time = 0;

    capd::IMap f{f_node, 2, 2, 1};
    f.setParameter(0, 1);

    capd::IOdeSolver solver{f, taylorOrder};
    capd::ITimeMap map{solver};
    const auto &curve = solver.getCurve();

    map.stopAfterStep(true);

    mapDebug("1", map, set, T);
    while (curve_time <= solver.getStep()) {
        COUT(curve(curve_time));
        curve_time += H;
    }

    return 0;
}
