//
// Created by ssohy on 12/10/2019.
//

#include "Camera.h"

void Camera::moveCam(Player *player, int viewType) {
    
    switch (viewType) {
        case 1:
            camPos.x = player->getPos().x - distance * cos(player->getRotation() * (M_PI / 180));
            camPos.z = player->getPos().z + distance * sin(player->getRotation() * (M_PI / 180));
            
            gluLookAt(camPos.x, camPos.y, camPos.z, player->getPos().x,
                    0, player->getPos().z, 0, 1, 0);
            break;
        case 2:
            float tempX;
            float tempY;

            camPos.x = player->getPos().x - 2 * cos((player->getRotation() + player->getCanonRotation()) * (M_PI / 180));
            camPos.z = player->getPos().z + 2 * sin((player->getRotation() + player->getCanonRotation()) * (M_PI / 180));
            tempX = player->getPos().x + 1 * cos((player->getRotation() + player->getCanonRotation()) * (M_PI / 180));
            tempY = player->getPos().z - 1 * sin((player->getRotation() + player->getCanonRotation()) * (M_PI / 180));
            gluLookAt(camPos.x, player->getPos().y + 1 , camPos.z, tempX, 0.9, tempY, 0, 1, 0);
            
            //VIewport for minimap ******
            

            break;
        default:
            break;
    }
}


Camera::Camera(Player *player) {
    
    camPos = glm::vec3((player->getPos().x), 4, (player->getPos().z));
    rotAngle = player->getRotation();
    distance = 10;
    lastX = 0;
    lastY = 0;
    
    
}

void Camera::setDistance(float distance) {
    if (this->distance + distance > 0 && this->distance + distance <= 10) {
        Camera::distance += distance;
    }
}
