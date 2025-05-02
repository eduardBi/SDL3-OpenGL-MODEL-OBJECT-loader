#include "loaderObj.h"
#include <iostream>

MeshData LoadAndDisplayModel(const std::string& modelPath) {
    try {
        // Load the model from the given path
        MeshData mesh = LoadModel(modelPath);  // Make sure car.obj exists in your directory
        
        // Print the overall information about the mesh
        std::cout << "Loaded model: " << modelPath << std::endl;
        std::cout << "Total vertices: " << mesh.vertices.size() / 3 << std::endl;  // Dividing by 3 assuming 3 components per vertex
        std::cout << "Total normals: " << mesh.normals.size() / 3 << std::endl;   // Dividing by 3 assuming 3 components per normal
        std::cout << "Total texture coordinates: " << mesh.texcoords.size() / 2 << std::endl;  // Dividing by 2 assuming 2 components per texcoord
        
        // Check if indices exist and print them
        if (!mesh.indices.empty()) {
            std::cout << "Total indices (faces): " << mesh.indices.size() / 3 << std::endl;  // Dividing by 3 for triangle faces
        } else {
            std::cout << "No indices found." << std::endl;
        }
        
        // Return the loaded mesh
        return mesh;
        
    } catch (const std::exception& e) {
        std::cerr << "Failed to load model: " << e.what() << std::endl;
        throw;  // Rethrow the exception if loading failed
    }
}
