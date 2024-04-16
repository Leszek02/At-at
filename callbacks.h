#pragma once
#ifndef CALLBACKS_H

//moving camera 
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	const float speed = 0.5f;
	if (key == GLFW_KEY_UNKNOWN)
		return;
	if (action != GLFW_RELEASE) {
		if (key == GLFW_KEY_UP) cameraPosition += cameraLook * speed;
		if (key == GLFW_KEY_DOWN) cameraPosition -= cameraLook * speed;
		if (key == GLFW_KEY_RIGHT) cameraPosition += glm::cross(cameraLook, cameraUp) * speed;
		if (key == GLFW_KEY_LEFT) cameraPosition -= glm::cross(cameraLook, cameraUp) * speed;
		if (key == GLFW_KEY_G) {
			manualControl = !manualControl;
			if (direction == 0)
				direction = 1;
			else
				direction = 0;
		}

		if (key == GLFW_KEY_S && manualControl) direction = -1;
		if (key == GLFW_KEY_A && manualControl) headSpin = 1;
		if (key == GLFW_KEY_D && manualControl) headSpin = -1;

	}
	if (key == GLFW_KEY_W && manualControl && action == GLFW_PRESS) direction = 1;
	if (manualControl && action == GLFW_RELEASE) {
		direction = 0;
		headSpin = 0;
	}
}

//Rotating camera
void cameraRotation(GLFWwindow* window, double xpos, double ypos) {
	//Reaing mouse position when opening program
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	//callculeting mouse movement
	float offsetX = xpos - lastX;
	float offsetY = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	const float sensitivity = 0.1f;
	offsetX *= sensitivity;
	offsetY *= sensitivity;

	yaw += offsetX;
	pitch += offsetY;

	//if pitch < -90 or > 90 then cameraLook will flip and we don't want that
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraLook = glm::normalize(direction);
}
#endif