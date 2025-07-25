#include "Engine/Debug.hpp"
#include "Engine/Opts.hpp"
#include <raylib.h>
#include <string>

void Debug::draw_frame_info(bool is_debug) {
  if (is_debug) {
    Opts opts;
    DrawText(std::to_string(GetFPS()).c_str(), opts.screen.x * 0.01, opts.screen.y * 0.01, 24, GREEN);
    DrawText(std::to_string(GetFrameTime()).c_str(), opts.screen.x * 0.01, opts.screen.y * 0.04, 24, GREEN);
  }
}
