// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp
// See FAQ for more details or if you're having problems.

#include "Transform.h"

// Helper rotation function.  Please implement this.  
mat3 Transform::rotate(const float degrees, const vec3& axis) 
{
	mat3 resulting_matrix(1.0f);

	float radians = glm::radians(degrees);
	float cosine = cos(radians);
	float sine = sin(radians);
	const float one_minus_cosine = 1.0f - cosine;

	const float x = axis.x;
	const float y = axis.y;
	const float z = axis.z;

	resulting_matrix[0][0] = x * x * one_minus_cosine + cosine;
	resulting_matrix[1][0] = x * y * one_minus_cosine - z * sine;
	resulting_matrix[2][0] = x * z * one_minus_cosine + y * sine;

	resulting_matrix[0][1] = x * y * one_minus_cosine + z * sine;
	resulting_matrix[1][1] = y * y * one_minus_cosine + cosine;
	resulting_matrix[2][1] = y * z * one_minus_cosine - x * sine;

	resulting_matrix[0][2] = x * z * one_minus_cosine - y * sine;
	resulting_matrix[1][2] = y * z * one_minus_cosine + x * sine;
	resulting_matrix[2][2] = z * z * one_minus_cosine + cosine;

	return resulting_matrix;
}

void Transform::left(float degrees, vec3& eye, vec3& up) 
{
	eye = eye * rotate(-degrees, glm::normalize(up));
}

void Transform::up(float degrees, vec3& eye, vec3& up) 
{
	vec3 w = glm::normalize(glm::cross(eye, up));
	mat3 rotation_matrix = rotate(-degrees, w);
	eye = eye * rotation_matrix;
	up = up * rotation_matrix;
}

mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) 
{
	mat4 resulting_matrix(1.0f);

	vec3 w = glm::normalize(eye);
	vec3 u = glm::normalize(glm::cross(up, w));
	vec3 v = glm::cross(w, u);

	resulting_matrix[0][0] = u.x;
	resulting_matrix[1][0] = u.y;
	resulting_matrix[2][0] = u.z;

	resulting_matrix[0][1] = v.x;
	resulting_matrix[1][1] = v.y;
	resulting_matrix[2][1] = v.z;

	resulting_matrix[0][2] = w.x;
	resulting_matrix[1][2] = w.y;
	resulting_matrix[2][2] = w.z;

	resulting_matrix[3][0] = glm::dot(u, -eye);
	resulting_matrix[3][1] = glm::dot(v, -eye);
	resulting_matrix[3][2] = glm::dot(w, -eye);

	return resulting_matrix;
}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // New, to implement the perspective transform as well.  
  return ret;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) 
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement scaling 
  return ret;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) 
{
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement translation 
  return ret;
}

// To normalize the up direction and construct a coordinate frame.  
// As discussed in the lecture.  May be relevant to create a properly 
// orthogonal and normalized up. 
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  

vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) 
{
  vec3 x = glm::cross(up,zvec); 
  vec3 y = glm::cross(zvec,x); 
  vec3 ret = glm::normalize(y); 
  return ret; 
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
