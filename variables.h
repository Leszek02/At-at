#pragma once
#ifndef VARIABLES_H

//Camera start position
glm::vec3 cameraPosition(0.0f, 4.0f, 10.0f);
glm::vec3 cameraLook(0.0f, 6.0f, -4.0f);
glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

//Camera view angle
float yaw = -90.0f; //"left-right" rotation 
float pitch = 0.0f; //"up-down" rotation
bool firstMouse = true;

//mouse start position 
float lastX = 400, lastY = 300;


//data of loaded model
ShaderProgram* sp;
Assimp::Importer importer;
int direction = 1;
int headSpin = 0;
bool manualControl = false;
GLuint tex0; // atat
GLuint tex0spec; // atat spectral
GLuint tex1; // floor diffuse
GLuint tex2; // skybox
float floor_size = 10000.0f;
float floor_scaler = 8.0f;
const float PI = 3.14159265359;

float floorVerts[] = {
		-1.0f, 0.0f, 1.0f,1.0f,
		1.0f, 0.0f,-1.0f,1.0f,
		1.0f, 0.0f, 1.0f,1.0f,

		-1.0f, 0.0f, 1.0f,1.0f,
		-1.0f, 0.0f,-1.0f,1.0f,
		1.0f, 0.0f,-1.0f,1.0f };

float floorTexCoords[] = {
	floor_size / floor_scaler, 0.0f, 
	0.0f, floor_size / floor_scaler, 
	0.0f, 0.0f,
	floor_size / floor_scaler, 0.0f, 
	floor_size / floor_scaler, floor_size / floor_scaler, 
	0.0f, floor_size / 8 };

float floorNormals[] = {
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,

	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f,
	0.0f, 1.0f, 0.0f,0.0f };

float skyboxVertices[] = {
    // positions          
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};
#endif