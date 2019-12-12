//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_MENUMANAGER_H
#define MONPROJETSDL_MENUMANAGER_H


#include "../Utils/Include.h"
#include "TextureManager.h"
#include "../Classes/Text.h"
#include <sys/types.h>
#include <dirent.h>

class MenuManager {
    std::vector<std::string> mapName;
    std::vector<TextureManager*> mapTexture;
    std::vector<Text*> mapText;
    TextureManager* selectMap;
    TextureManager* quit;
    TextureManager* play;
    TextureManager* bg;
    std::string path = "../assets/map";

    SDL_Renderer *render;
    const Uint8* state = nullptr;
    SDL_Event event;
    bool isRunning = true;
    bool viewChanged = false;
    SDL_Window *win;
    int width = 800, height = 600;
    bool inMenu = true;
    int levelSelected;
    int mouseX;
    int mouseY;
    bool mouseDown = false;

public:
    MenuManager();
    
    void init();

    void update();
    
    std::vector<std::ifstream> loadMaps();
    
    void drawMenu();

    bool isInMenu() const;

    void setInMenu(bool inMenu);

    void setButtonTexture(TextureManager* texture, std::string fileNameNoExt);

    void drawMapSelection();

    void deleteMeu();

    void readDirectory();
    ~MenuManager();
};


#endif //MONPROJETSDL_MENUMANAGER_H
