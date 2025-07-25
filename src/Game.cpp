#include "Engine/Game.hpp"
#include "Engine/Opts.hpp"
#include "Engine/Save.hpp"
#include <filesystem>
#include <fstream>
#include <memory>
#include <raylib.h>
#include <string>

Game::Game() {
  if (load_opts() && load_assets()) {
    InitWindow(opts.screen.x, opts.screen.y, "Game Window");
    //   SetTargetFPS(60);
    SetWindowFocused();
    entities.reserve(20);
    std::println("starting game loop");
    while (!WindowShouldClose()) {
      Update();
      Draw();
    }
    player->save_serial("./RPG-Directory/Save");
    unload_assets();
    CloseWindow();
  } else {
    std::println("Failed to load game");
  }
}

void Game::Update() {
  change_menu_flag();
  if (menu->get_menu_flag() == FLAGS::MENU::NONE) {
    UpdateUI();
    UpdateEntities();
    UpdateLevel();
    return;
  } else {
    UpdateMenus();
  }
}

void Game::UpdateUI() {
  if (menu->get_menu_flag() != FLAGS::MENU::NONE) {
    ui->update();
  }
}
void Game::UpdateMenus() {
  if (menu->get_menu_flag() != FLAGS::MENU::NONE) {
    menu->update();
  }
}
void Game::UpdateEntities() {
  player->update();
  for (auto& entity : entities) {
    entity->update();
  }
}
void Game::UpdateLevel() {}

void Game::Draw() {
  BeginDrawing();
  ClearBackground(background_color);
  DrawMenus();
  if (menu->get_menu_flag() != FLAGS::MENU::MAIN) {
    DrawLevel();
    DrawEntities();
    DrawUI();
  }
  debug.draw_frame_info(true);
  EndDrawing();
}

void Game::DrawUI() {
  if (menu->get_menu_flag() != FLAGS::MENU::NONE) {
    ui->draw();
  }
}
void Game::DrawMenus() {
  switch (menu->get_menu_flag()) {
    case FLAGS::MENU::MAIN:
      menu->draw_main();
      return;
    case FLAGS::MENU::PAUSE:
      menu->draw_pause();
      return;
  }
}
void Game::DrawEntities() {
  player->draw();
  for (const auto& entity : entities) {
    entity->draw();
  }
}
void Game::DrawLevel() {}

bool Game::load_assets() {
  player = std::make_shared<Player>();
  player->load(std::string("./RPG-Directory/Save"));
  std::println("player fully loaded");
  std::println("Player location: {},{}", player->get_pos().x, player->get_pos().y);
  ui = std::make_shared<UI>(player);
  menu = std::make_unique<Menu>();
  if (player == nullptr || ui == nullptr || menu == nullptr) return false;

  return true;
}

bool Game::load_opts() {
  // impl method
  std::string file_directory = "./RPG-Directory";
  if (!std::filesystem::is_directory(file_directory)) std::filesystem::create_directory(file_directory);
  std::ifstream input(file_directory + "/options.conf");
  if (!input.is_open()) {
    std::ofstream create_file(file_directory + "/options.conf");
    create_file << "Screen Size: {1280, 720}\n";
    create_file << "FPS: 60\n";
    create_file << "Text Speed: 1\n";
    create_file << "Difficulty: 1\n";
    create_file.close();
    input.open(file_directory + "/options.conf");
  }
  if (!input.is_open()) {
    std::println("Error opening options text file");
    return false;
  } else {
    std::vector<std::string> options;
    std::string line;
    while (std::getline(input, line)) {
      options.push_back(line);
    }
    input.close();
    opts.screen.x = std::stoi(options[0].substr(options[0].find("{") + 1, options[0].find(",")));
    opts.screen.y = std::stoi(options[0].substr(options[0].find(", ") + 1, options[0].find("}")));
    std::println("Screen loaded");
    opts.fps = std::stoi(options[1].substr(options[1].find(": ") + 1));
    std::println("fps loaded");
    opts.text_speed = std::stoi(options[2].substr(options[2].find(": ") + 1));
    std::println("text_speed loaded");
    // opts.difficulty = std::stoi(options[3].substr(options[3].find(": ")));
  }
  return true;
}

bool Game::unload_assets() {
  // impl method
  return false;
}
