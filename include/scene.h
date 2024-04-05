// Defines the scene that the camera is looking at
// contains the triangles (mesh), camera, viewplane, etc.
#pragma once
#include "camera.h"
#include "mesh.h"
#include "ray.h"

class Scene {
   public:
    // Does ray intersect scene?
    bool rayIntersect(Ray& ray);

   private:
    Camera camera;
    Mesh mesh;
};
