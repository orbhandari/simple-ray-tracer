// A 3D vector to define coordinates, color (RGB), etc.
// Possibly parent class of Point3f, Color3f, etc
// Supports basic vector operations: addition, scalar mult, scalar div, dot product, cross product

class Vec3 {
   public:
    Vec3(float val);

    Vec3(float x, float y, float z);

    float x();

    float y();

    float z();

    Vec3 normalized();

    // Then use the cross product formula to get n (unit normal) of the triangle plane.
    // Vec3 n = Vec3(a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(), a.x() * b.y() - a.y() * b.x()).normalized();
    Vec3 cross(const Vec3& b);

    float dot(const Vec3& b);

    Vec3 operator+(const Vec3& vector);

    Vec3 operator-(const Vec3& vector);

    Vec3 operator*(const float& scalar);

    Vec3 operator/(const float& scalar);

    friend Vec3 operator*(const float& scalar, const Vec3& vector);

    // For both access and setting new value
    float& operator[](const int& index);

   private:
    float _x{0};
    float _y{0};
    float _z{0};
};
