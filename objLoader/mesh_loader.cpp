#include "mesh_loader.h"
#include <iostream>
#include <vector>
#include <string>
#include "tiny_obj_loader.h"

MeshData LoadModel(const std::string& inputfile) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    MeshData mesh;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, inputfile.c_str());

    if (!warn.empty()) std::cout << "WARN: " << warn << std::endl;
    if (!err.empty()) std::cerr << "ERR: " << err << std::endl;
    if (!ret) throw std::runtime_error("Failed to load OBJ file.");

    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            // Positions
            mesh.vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
            mesh.vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
            mesh.vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);

            // Normals
            if (!attrib.normals.empty() && index.normal_index >= 0) {
                mesh.normals.push_back(attrib.normals[3 * index.normal_index + 0]);
                mesh.normals.push_back(attrib.normals[3 * index.normal_index + 1]);
                mesh.normals.push_back(attrib.normals[3 * index.normal_index + 2]);
            }

            // Texture coordinates
            if (!attrib.texcoords.empty() && index.texcoord_index >= 0) {
                mesh.texcoords.push_back(attrib.texcoords[2 * index.texcoord_index + 0]);
                mesh.texcoords.push_back(attrib.texcoords[2 * index.texcoord_index + 1]);
            }

            mesh.indices.push_back(mesh.indices.size());
        }
    }

    return mesh;
}
