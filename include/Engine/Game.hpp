#pragma once
#ifndef ENGINE_GAME_HPP_
#define ENGINE_GAME_HPP_

#include "Debug.hpp"
#include "Entities/Characters/Player.hpp"
#include "Flags.hpp"
#include "Opts.hpp"
#include "UI/Menu.hpp"
#include "UI/UI.hpp"
#include <memory>
#include <raylib.h>

class Game {
  public:
  Game();

  // init methods
  bool load_opts();
  bool load_assets();
  bool unload_assets();

  // Draw Methods
  void Draw();
  void DrawEntities();
  void DrawUI();
  void DrawMenus();
  void DrawLevel();

  // Update Methods
  void Update();
  void UpdateEntities();
  void UpdateUI();
  void UpdateMenus();
  void UpdateLevel();

  void change_menu_flag() {
    if (IsKeyPressed(KEY_ENTER)) {
      switch (menu->get_menu_flag()) {
        case FLAGS::MENU::NONE:
          menu->set_flag(FLAGS::MENU::PAUSE);
          return;
        case FLAGS::MENU::MAIN:
          menu->set_flag(FLAGS::MENU::NONE);
          return;
        case FLAGS::MENU::PAUSE:
          menu->set_flag(FLAGS::MENU::NONE);
          return;
      }
    }
  }

  // Entity
  std::vector<Entity*> entities;

  Debug debug;

  Color background_color = RAYWHITE;
  std::shared_ptr<Player> player;
  std::shared_ptr<UI> ui;
  std::unique_ptr<Menu> menu;
  Flag flags;

  Opts opts;
};
#endif
