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
};

#endif
