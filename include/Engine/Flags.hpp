#pragma once

#include <cstdint>
#include <sys/types.h>
struct Flag {
  uint8_t id;
};

struct GameFlag : public Flag {
  static uint8_t game_flag;
};

struct StateFlag : public Flag {
  bool state_flag;
};

namespace FLAGS {
  namespace MENU {
    enum MENU_FLAGS {
      MAIN,
      PAUSE,
      OPTIONS,
      INVENTORY,
      GRAPHICS,
      SOUND,
      KEYBINDS,
      GAME,
      SAVE,
      MAP,
      NONE,
    };
  }
  enum STORY_FLAGS {
    INTRO,
  };
} // namespace FLAGS
