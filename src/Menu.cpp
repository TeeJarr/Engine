#include "UI/Menu.hpp"
#include "Engine/Opts.hpp"
#include "raylib.h"
#include <cstdint>
#include <print>

Menu::Menu() {
  set_flag(MENU::MAIN);
  std::println("{}", menu_flag);
}

void Menu::draw() {}

void Menu::update() {
  if (IsKeyPressed(KEY_TAB)) {
    change_window_size();
  }
}

bool Menu::set_flag(uint8_t menu_flag) {
  if (menu_flag > MENU::NONE || menu_flag < MENU::MAIN) {
    std::println("Error: invalid menu flag");
    return false;
  }
  this->menu_flag = menu_flag;
  return true;
}

uint8_t Menu::get_menu_flag() { return this->menu_flag; }

void Menu::draw_main() {
  ClearBackground(RED);
  // HACK: Make proper text and Add Actual background art
  DrawText("Title Screen", opts.screen.x / 2, opts.screen.y / 2, 24, BLACK);
}

void Menu::draw_pause() {
  ClearBackground(BLACK);
  // HACK: Make proper text and Add Actual background art
  DrawText("Title Screen", opts.screen.x / 2, opts.screen.y / 2, 24, BLACK);
}

void Menu::change_window_size() {
  Opts::screen.x = 1920;
  Opts::screen.y = 1080;
  SetWindowSize(opts.screen.x, opts.screen.y);
}
