#ifndef GL_WINDOW_H
#define GL_WINDOW_H
#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "geometry.h"

            class OpenGLWindow
{
public:
    OpenGLWindow();

    void initGL();
    void render();
    bool handleEvent(SDL_Event e);
    void cleanup();

  private:
    SDL_Window* sdlWin;

    GLuint vao;
    GLuint shader;
    GLuint vertexBuffer;
    GLsizei vertex_count;
    GLuint TransformationID;
    glm::mat4 Projection;
    glm::mat4 View;
    glm::mat4 Model;
    glm::mat4 MVP;
    float r;
    float g;
    float b;
    float a;
    void changeColor(){
        r = ((double)rand() / (RAND_MAX));
        g = ((double) rand() / (RAND_MAX));
        b = ((double)rand() / (RAND_MAX));
        a = ((double)rand() / (RAND_MAX));
    }
    // position
    glm::vec3 position = glm::vec3(0, 0, 5);
    // horizontal angle : toward -Z
    float horizontalAngle = 3.14f;
    // vertical angle : 0, look at the horizon
    float verticalAngle = 0.0f;
    // Initial Field of View
    float initialFoV = 45.0f;

    float speed = 3.0f; // 3 units / second
    float mouseSpeed = 0.005f;
    int x_i, y_i, z_i;
};

#endif
