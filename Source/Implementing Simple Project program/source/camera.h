#include <windows.h>
#include <strstream>
#include <math.h>
#include <gl\freeglut.h>

class Point3 
{
public:
	double x, y, z;
	void set(double dx, double dy, double dz)
	{ 
		x = dx; y = dy; z = dz;
	}
	void set(Point3& p)
	{ 
		x = p.x; y = p.y; z = p.z;
	}
	Point3(double xx, double yy, double zz)
	{
		x = xx; y = yy; z = zz;
	}
	Point3() 
	{ 
		x = y = z = 0; 
	}
};
class Vector3 {
public:
	double x, y, z;

	void set(Vector3 const& v)
	{
		x = v.x; y = v.y; z = v.z;
	}
	void set(float dx, float dy, float dz) 
	{
		x = dx; y = dy; z = dz; 
	}
	void flip() 
	{
		x = -x; y = -y; z = -z;
	}
	void setDiff(Point3& a, Point3& b)
	{
		x = a.x - b.x; 
		y = a.y - b.y; 
		z = a.z - b.z;
	}
	void normalize();
	Vector3(float xx, float yy, float zz)
	{
		this->x = xx; 
		this->y = yy; 
		this->z = zz;
	}
	Vector3(Vector3& v) 
	{ 
		x = v.x; y = v.y; z = v.z;
	}
	Vector3()
	{
		x = y = z = 0.0;
	}
	Vector3 cross(Vector3 b);
	float dot(Vector3 b);
};
class Camera 
{
public:
	Point3 eye;
	Vector3 u, v, n;
	float aspect, nearDist, farDist, viewAngle;
	void setModelViewMatrix();
	Camera(void);

	void roll(float angle);
	void pitch(float angle);
	void yaw(float angle);
	void slide(double du, double dv, double dn);

	void set(Point3 Eye, Point3 look, Vector3 up);
	void set(float eyeX, float eyeY, float eyeZ, float lookX, float lookY, float lookZ, float upX, float upY, float upZ);

	void setShape(float viewAngle, float aspect, float Near, float Far);
	void setAspect(float asp);
	void getShape(float& viewAngle, float& aspect, float& Near, float& Far);
	void rotAxes(Vector3& a, Vector3& b, float angle);
	void setDefaultCamera();
};
