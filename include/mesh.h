// Mesh, that is, the container of all primitives (in our case, triangles)
#pragma once
#include "triangle.h"
#include "ray.h"
class Mesh {
   public:
    Mesh(std::vector<Triangle> triangles) : triangles{triangles} {};
    bool rayIntersect(Ray& ray);

   private:
    std::vector<Triangle> triangles;
};