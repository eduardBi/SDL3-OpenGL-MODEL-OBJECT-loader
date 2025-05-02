#include <iostream>
#include <vector>
#include <string>
#include <SDL3/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "objLoader/loaderObj.h" // Your custom loader

struct Vertex {
    GLfloat x, y, z;
    GLfloat r, g, b;
};

std::vector<Vertex> vertices;
std::vector<unsigned int> triangleIndices;

MeshData getObject() {
    std::string modelPath = "car.obj";
    return LoadAndDisplayModel(modelPath);
}

void getVertices(const MeshData& mesh) {
    vertices.clear();
    for (size_t i = 0; i < mesh.vertices.size(); i += 3) {
        Vertex v;
        v.x = mesh.vertices[i] / 15.0f;
        v.y = mesh.vertices[i + 1] / 15.0f;
        v.z = mesh.vertices[i + 2] / 15.0f;
        v.r = 1.0f;
        v.g = 1.0f;
        v.b = 1.0f;
        vertices.push_back(v);
    }
}

void getTriangles(const MeshData& mesh) {
    triangleIndices = mesh.indices;
}

bool initOpenGL(SDL_Window*& window, SDL_GLContext& context) {
    window = SDL_CreateWindow("3D Viewer", 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "SDL window error: " << SDL_GetError() << std::endl;
        return false;
    }

    context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cerr << "OpenGL context error: " << SDL_GetError() << std::endl;
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    return true;
}

void setupProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.0f);
}

void renderModel(float angleX, float angleY) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    
    glScalef(0.1f, 0.1f, 0.1f); // Reduce to 20% size


    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < triangleIndices.size(); i += 3) {
        for (int j = 0; j < 3; ++j) {
            const Vertex& v = vertices[triangleIndices[i + j]];
            glColor3f(v.r, v.g, v.b);
            glVertex3f(v.x, v.y, v.z);
        }
    }
    glEnd();
}

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_GLContext glContext;

    if (SDL_Init(SDL_INIT_VIDEO) < 0 || !initOpenGL(window, glContext)) {
        return -1;
    }

    MeshData mesh = getObject();
    getVertices(mesh);
    getTriangles(mesh);

    setupProjection();

    bool quit = false;
    SDL_Event event;
    float angleX = 0.0f, angleY = 0.0f;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                quit = true;
        }

        angleX += 0.3f;
        angleY += 0.4f;

        renderModel(angleX, angleY);
        SDL_GL_SwapWindow(window);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
