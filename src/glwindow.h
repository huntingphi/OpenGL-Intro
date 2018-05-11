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
    enum state{view,rotate_x,rotate_y,rotate_z, scale,translate};
    
    void initGL();
    void initGL2();
    void render();
    bool handleEvent(SDL_Event e);
    void cleanup();

  private:
    SDL_Window* sdlWin;

    GLuint vao;
    GLuint vao_2;
    GLuint shader;
    GLuint vertexBuffer;
    GLuint vertexBuffer_2;
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
    int x_i, y_i, z_i;
    void translation(int x_f, int y_f, state mode)
    {
        float diff_x, diff_y, diff_z;
        diff_x = 0.0f;
        if (x_f > x_i)
            diff_x = 0.01f;
        if (x_f < x_i)
            diff_x = -0.01f;
        if (y_f > y_i)
            diff_y = -0.01f;
        if (y_f < y_i)
            diff_y = 0.01f;
        x_i = x_f;
        y_i = y_f;
        glm::mat4 model_matrix;

        switch (mode)
        {
        case translate:
            model_matrix = glm::translate(glm::mat4(), glm::vec3(diff_x, diff_y, diff_z)); //glm::mat4(1.0f);
            break;
        case rotate_x:
            model_matrix = glm::rotate(glm::mat4(), diff_x, glm::vec3(0, 1, 0)); //glm::mat4(1.0f);
            break;
        case rotate_y:
            model_matrix = glm::rotate(glm::mat4(), diff_y, glm::vec3(1, 0, 0)); //glm::mat4(1.0f);
            break;
        case rotate_z:
            // glm::mat4 model_matrix = glm::rotate(glm::mat4(), diff_y*0.5+diff_x*0.5, glm::vec3(1, 0, 0)); //glm::mat4(1.0f);
            break;
        case scale:
            model_matrix = glm::scale(glm::mat4(), glm::vec3(1 + diff_x, 1 + diff_y, 1 + diff_z)); //glm::mat4(1.0f);
            break;
        }
        MVP *= model_matrix;
    }

    void translation(float x_f, float y_f, state mode)
    {
        float diff_x, diff_y, diff_z;
        diff_x = x_f;
        diff_y = y_f;
        glm::mat4 model_matrix;

        switch (mode)
        {
        case translate:
            model_matrix = glm::translate(glm::mat4(), glm::vec3(diff_x, diff_y, diff_z)); //glm::mat4(1.0f);
            break;
        case rotate_x:
            model_matrix = glm::rotate(glm::mat4(), diff_x, glm::vec3(0, 1, 0)); //glm::mat4(1.0f);
            break;
        case rotate_y:
            model_matrix = glm::rotate(glm::mat4(), diff_y, glm::vec3(1, 0, 0)); //glm::mat4(1.0f);
            break;
        case rotate_z:
            // glm::mat4 model_matrix = glm::rotate(glm::mat4(), diff_y*0.5+diff_x*0.5, glm::vec3(1, 0, 0)); //glm::mat4(1.0f);
            break;
        case scale:
            model_matrix = glm::scale(glm::mat4(), glm::vec3(1 + diff_x, 1 + diff_y, 1 + diff_z)); //glm::mat4(1.0f);
            break;
        }
        MVP *= model_matrix;
    }
};

#endif
