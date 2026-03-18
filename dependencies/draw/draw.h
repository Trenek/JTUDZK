#include <stdlib.h>
#include <vector>

#include <raylib.h>

struct Vec2 {
    float x, y;
};

class Animation {
    std::vector<Vec2> points;
    std::vector<Vec2> sizes;
    std::vector<int> frame_ends;
    std::vector<float> times;
    int cur_frame_end = 0;

public:
    void push(Vec2 point, Vec2 size, float time) {
        points.push_back(point);
        sizes.push_back(size);
        times.push_back(time);
    }

    void push(Vec2 point, float time) {
        push(point, {0, 0}, time);
    }
    
    void end_frame() {
        frame_ends.push_back(points.size() - 1);
    }

    void draw(double x_min, double x_max, double y_min, double y_max,
              int width = 800, int height = 600) {
        InitWindow(width, height, "capd");
        SetTargetFPS(30);

        while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for(int i = 0; i < points.size(); ++i) {
                if(frame_ends.size() > 0) {
                    if(i >= frame_ends[cur_frame_end]) {
                        cur_frame_end = (cur_frame_end + 1) % frame_ends.size();
                        constexpr int digits = 3;
                        char buf[digits + 1]{};
                        gcvt(times[i], digits, buf);
                        DrawText(buf, 10, 50, 30, BLACK);
                        break;
                    }
                }
                auto p = points[i];
                auto q = sizes[i];
                auto lc = p;
                lc.x -= q.x / 2;
                lc.y -= q.y / 2;
                float px = (p.x - x_min) / (x_max - x_min) * width;
                float py = (p.y - y_min) / (y_max - y_min) * height;
                float lcx = (lc.x - x_min) / (x_max - x_min) * width;
                float lcy = (lc.y - y_min) / (y_max - y_min) * height;
                float qx = (q.x) / (x_max - x_min) * width;
                float qy = (q.y) / (y_max - y_min) * height;
                DrawRectangle(lcx, lcy, qx, qy, RED);
                DrawCircle(px, py, 3, BLUE);
            }
        EndDrawing();
        }
        CloseWindow();
    }
};
