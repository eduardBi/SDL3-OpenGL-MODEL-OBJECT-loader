#ifndef LOADER_APP_H
#define LOADER_APP_H

#include <iostream>
#include "mesh_loader.h"  // Include the header for mesh_loader
#include "tiny_obj_loader.h"  // Correct the path if needed

MeshData LoadAndDisplayModel(const std::string& modelPath);

#endif  // LOADER_APP_H
