#pragma once
#include "DataStructs.hpp"
#include "raylib.h"

struct Opts {
  static Vec2 screen;
  static int fps;
  static int text_speed;
  static float difficulty;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(screen, fps, text_speed, difficulty);
  }
};

inline Vec2 Opts::screen;
inline int Opts::fps;
inline int Opts::text_speed;
inline float Opts::difficulty;

namespace DIFFICULTY {
  enum DIFFICULTY {
    EASY,
    NORMAL,
    HARD,
    LEGENDARY,
  };
};

namespace FPS {
  enum FPS {
    _30 = 30,
    _60 = 60,
    _120 = 120,
    _144 = 144,
    _240 = 240,
    _360 = 360,
    UNCAPPED = 0,
  };
}

inline Vec2 res_720p = {1280, 720};
inline Vec2 res_1080p = {1920, 1080};
inline Vec2 res_1440p = {2560, 1440};
inline Vec2 res_2160p = {3840, 2160};

namespace RESOLUTION {
  enum RESOLUTION {
    res_720p,
    res_1080p,
    res_1440p,
    res_2160p,
  };
}

namespace TEXT {
  enum TEXT_SPEED {
    SLOW,
    NORMAL,
    FAST,
    INSTANT,
  };
};

void save_opts();
