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
    capd::C0HORect2Set set{v}; // Hermit Obreszkov?

    constexpr int taylorOrder = 20;

    const capd::interval T{M_PI / 2}; // Czas Końcowy

    capd::IMap f{f_node, 2, 2, 1};
    f.setParameter(0, 1);

    capd::IOdeSolver solver{f, taylorOrder};
    capd::ITimeMap map{solver};
    map.stopAfterStep(true);

    mapDebug("1", map, set, T);
    mapDebug("2", map, set, T);
    mapDebug("3", map, set, T); // Nic nie robi, osiągneliśmy już kres
    mapDebug("4", map, set, 2 * T);
    mapDebug("5", map, set, 2 * T);
    mapDebug("6", map, set, 2 * T); // Nic nie robi, osiągneliśmy już kres
    mapDebug("7", map, set, T); // Nic nie robi, nie cofamy się w czasie

    return 0;
}
