// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include <cstdio>


// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {

  mat3 resulting_matrix(1.0f);

  float radians = glm::radians(degrees);
  float cosine = cos(radians);
  float sine = sin(radians);
  const float one_minus_cosine = 1.0f - cosine;

  const float x = axis.x;
  const float y = axis.y;
  const float z = axis.z;

  resulting_matrix[0][0] = x * x * one_minus_cosine + cosine;
  resulting_matrix[0][1] = x * y * one_minus_cosine - z * sine;
  resulting_matrix[0][2] = x * z * one_minus_cosine + y * sine;

  resulting_matrix[1][0] = x * y * one_minus_cosine + z * sine;
  resulting_matrix[1][1] = y * y * one_minus_cosine + cosine;
  resulting_matrix[1][2] = y * z * one_minus_cosine - x * sine;

  resulting_matrix[2][0] = x * z * one_minus_cosine - y * sine;
  resulting_matrix[2][1] = y * z * one_minus_cosine + x * sine;
  resulting_matrix[2][2] = z * z * one_minus_cosine + cosine;

  return resulting_matrix;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  eye = eye * rotate(degrees, glm::normalize(up));

  printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {

  vec3 w = glm::normalize(glm::cross(eye, up));
  mat3 rotation_matrix = rotate(degrees, w);
  eye = eye * rotation_matrix;
  up = up * rotation_matrix;

  printf("Up Vector Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", up.x, up.y, up.z, sqrt(pow(up.x, 2) + pow(up.y, 2) + pow(up.z, 2)));
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
