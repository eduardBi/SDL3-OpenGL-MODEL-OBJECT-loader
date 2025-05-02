#ifndef MESH_LOADER_H
#define MESH_LOADER_H

#include <vector>
#include <string>

struct MeshData {
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> texcoords;
    std::vector<unsigned int> indices;
};

MeshData LoadModel(const std::string& inputfile);

#endif  // MESH_LOADER_H
