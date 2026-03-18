#include <iomanip>
#include <capd/capdlib.h>

#include "draw.h"

Vec2 to_vec2(const capd::IVector &v) {
    return {
        (float)v[0].mid().leftBound(), 
        (float)v[1].mid().leftBound()
    };
}

Vec2 diams(const capd::IVector &v) {
    return {
        (float)diam(v[0]).leftBound(),
        (float)diam(v[1]).leftBound()
    };
}

int main() {
    Animation a;

    const capd::IVector v{0, 1};
    capd::C0HORect2Set set{v};

    const capd::interval T = M_PI / 2;
    const capd::interval H = capd::interval{1} / 256;

    capd::interval cur_time = 0;

    capd::IMap f{"par:a;var:x,y;fun:-a*y,x;"};
    f.setParameter(0, 1);

    capd::IOdeSolver solver{f, 20};
    capd::ITimeMap map{solver};
    const auto &curve = solver.getCurve();

    map.stopAfterStep(true);
    std::cout << std::setprecision(20);
    do {
        map(4 * T, set);
        COUT(solver.getStep());
        COUT(capd::IVector{set});

        for (capd::interval curve_time = 0; curve_time <= solver.getStep(); curve_time += H) {
            COUT(curve(curve_time));
            a.push(to_vec2(curve(curve_time)), cur_time.leftBound());
            a.end_frame();

            cur_time += H;
        }
    } while(!map.completed());
    
    a.draw(-2, 2, -2, 2);
}
