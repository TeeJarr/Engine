#pragma once
#include "Engine/Opts.hpp"

#include <cstdint>

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

class Menu {
  public:
  Menu();
  bool set_flag(uint8_t flag);
  void draw();
  void update();
  uint8_t get_menu_flag();
  void change_window_size();

  // draw functions
  void draw_main();
  void draw_pause();
  void draw_options();
  void draw_inventory();
  void draw_graphics();
  void draw_sound();
  void draw_keys();
  void draw_game();
  void draw_save();
  void draw_map();

  private:
  uint8_t menu_flag;
  Opts opts;
};
