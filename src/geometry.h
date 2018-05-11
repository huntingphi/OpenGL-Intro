#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

struct FaceData
{
    int vertexIndex[3];
    int texCoordIndex[3];
    int normalIndex[3];
};

class GeometryData
{
public:
    void loadFromOBJFile(std::string filename);

    int vertexCount();

    void* vertexData();
    void* textureCoordData();
    void* normalData();
    void* tangentData();
    void* bitangentData();
    void* set_translate(glm::mat4 m);
    void* set_scale(glm::mat4 m);
    void* set_rotate(float angle,glm::vec3 v);
    glm::mat4 get_translate();
    glm::mat4 get_scale();
    glm::mat4 get_rotate();

    void* transform();
private:
    std::vector<float> vertices;
    std::vector<float> textureCoords;
    std::vector<float> normals;
    std::vector<float> tangents;
    std::vector<float> bitangents;
    std::vector<FaceData> faces;

    glm::mat4 translation;
    glm::mat4 rotation;
    glm::mat4 scaling;
};

#endif
