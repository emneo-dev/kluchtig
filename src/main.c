#include <raylib.h>

constexpr static int SCREEN_WIDTH = 1920;
constexpr static int SCREEN_HEIGHT = 1080;
constexpr static int MAX_DEGREES = 360;

static float calc_rotations_per_seconds(float seconds, float rps)
{
    return seconds * 360 * rps;
}

int main(void)
{
    SetTraceLogLevel(LOG_WARNING);
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "kluchtig");

    Texture2D pp = LoadTexture("image.png");

    int frame_width = pp.width;
    int frame_height = pp.height;

    // Source rectangle (part of the texture to use for drawing)
    Rectangle source_rec = {
        0.0f,
        0.0f,
        (float) frame_width,
        (float) frame_height,
    };

    // Destination rectangle (screen rectangle where drawing part of texture)
    Rectangle dest_rec = {
        SCREEN_WIDTH / 2.0f,
        SCREEN_HEIGHT / 2.0f,
        (float) frame_width / 1.0f,
        (float) frame_height / 1.0f,
    };

    // Origin of the texture (rotation/scale point), it's relative to
    // destination rectangle size
    Vector2 origin = { dest_rec.width / 2.0f, dest_rec.height / 2.0f };

    float rotation = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(
            "Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY
        );
        DrawTexturePro(pp, source_rec, dest_rec, origin, rotation, WHITE);
        rotation += calc_rotations_per_seconds(GetFrameTime(), 0.5f);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
