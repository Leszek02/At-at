#pragma once
#ifndef MODEL_H
#include "glm/gtx/string_cast.hpp"

struct body {
	glm::vec3 translation;
	int timer;
};

struct transformations {

	float angle;
	glm::vec3 rotation;
	glm::vec3 translation;
};

struct legAnimation {

	transformations foot;
	transformations lower;
	transformations upper;
	transformations connector;
	int timer;
};

struct head {
	transformations position;
	int timer;
};

class Model {

private:

	std::vector<Mesh> meshes;
	legAnimation rightFrontLeg;
	legAnimation rightBackLeg;
	legAnimation leftFrontLeg;
	legAnimation leftBackLeg;
	body bodyTransformation;
	head headTransformation;

	glm::mat4 leftFrontLegTransform(int meshID, glm::mat4 M);
	glm::mat4 leftBackLegTransform(int meshID, glm::mat4 M);
	glm::mat4 rightFrontLegTransform(int meshID, glm::mat4 M);
	glm::mat4 rightBackLegTransform(int meshID, glm::mat4 M);
	glm::mat4 bodyTransform(glm::mat4 M);
	glm::mat4 headTransform(glm::mat4 M);
	body updateBody(body body);
	head updateHead(head head);
	legAnimation updateLegFront(legAnimation leg);
	legAnimation updateLegBack(legAnimation leg);
	void updateModel();

public:

	Model();
	void loadModel(std::string plik);
	void drawModel(glm::mat4 P, glm::mat4 V); //rysowanie meshu

};

legAnimation Model::updateLegFront(legAnimation leg) {
	//std::cout << leg.timer << std::endl;
	leg.timer += 1 * direction;
	if (leg.timer < 0) {
		leg.timer = 1999;
	}
	else if (leg.timer >= 0 && leg.timer < 250) {//
		leg.lower.angle += 0.06f * direction;
		leg.upper.angle += 0.06f * direction;
		leg.connector.angle -= 0.05f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.0017f * direction, -0.0006f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.0017f * direction, -0.0006f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.001f * direction, 0.005f * direction);
	}
	else if (leg.timer >= 500 && leg.timer < 750) {//
		leg.lower.angle += 0.06f * direction;
		leg.upper.angle += 0.06f * direction;
		leg.connector.angle -= 0.05f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.0017f * direction, -0.0006f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.0017f * direction, -0.0006f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.001f * direction, 0.005f * direction);
	}
	else if (leg.timer >= 1000 && leg.timer < 1250) {//
		leg.lower.angle += 0.04f * direction;
		leg.upper.angle += 0.04f * direction;
		leg.connector.angle += 0.02f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.0012f * direction, +0.0001f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.0012f * direction, +0.0001f * direction);
		leg.connector.translation += glm::vec3(0.0f, 0.0003f * direction, 0.0012f * direction);
	}
	else if (leg.timer >= 1500 && leg.timer < 1750) {//
		leg.lower.angle += 0.04f * direction;
		leg.upper.angle += 0.04f * direction;
		leg.connector.angle += 0.02f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.0012f * direction, +0.0001f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.0012f * direction, +0.0001f * direction);
		leg.connector.translation += glm::vec3(0.0f, 0.0003f * direction, 0.0012f * direction);
	}
	else if (leg.timer >= 1750 && leg.timer < 1775) {//
		leg.connector.angle -= 0.4f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.006f * direction, 0.004f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.006f * direction, 0.004f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.006f * direction, 0.02f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.006f * direction, 0.004f * direction);
	}
	else if (leg.timer >= 1775 && leg.timer < 1800) {//
		leg.connector.angle -= 0.4f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.006f * direction, -0.002f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.006f * direction, -0.002f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.004f * direction, 0.022f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.006f * direction, -0.002f * direction);
	}
	else if (leg.timer >= 1800 && leg.timer < 1825) {//
		leg.upper.angle -= 0.8f * direction;
		leg.upper.translation += glm::vec3(0.0f, -0.032f * direction, 0.038f * direction);
		leg.lower.translation += glm::vec3(0.0f, -0.002f * direction, 0.0212f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.002f * direction, 0.0212f * direction);
	}
	else if (leg.timer >= 1825 && leg.timer < 1850) {
		leg.upper.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.002f * direction, 0.0148f * direction);
		leg.upper.translation += glm::vec3(0.0f, -0.014f * direction, 0.034f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.002f * direction, 0.0148f * direction);
	}
	else if (leg.timer >= 1850 && leg.timer < 1875) {//
		leg.upper.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.004f * direction, 0.0152f * direction);
		leg.upper.translation += glm::vec3(0.0f, -0.004f * direction, 0.036f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.004f * direction, 0.0152f * direction);
	}
	else if (leg.timer >= 1875 && leg.timer < 1900) {///////
		leg.lower.angle -= 0.8f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.022f * direction, +0.0148f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.002f * direction, +0.0168f * direction);
	}
	else if (leg.timer >= 1900 && leg.timer < 1925) {//
		leg.lower.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.02f * direction, 0.02f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.004f * direction, 0.014f * direction);
	}
	else if (leg.timer >= 1925 && leg.timer < 1950) {//
		leg.lower.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.012f * direction, 0.022f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.006f * direction, 0.016f * direction);
	}
	else if (leg.timer >= 1950 && leg.timer < 1975) {//
		leg.connector.angle += 0.4f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.004f * direction, 0.0f);
		leg.upper.translation += glm::vec3(0.0f, -0.004f * direction, 0.0f);
		leg.connector.translation += glm::vec3(0.0f, +0.004f * direction, -0.022f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.004f * direction, 0.0f);
	}
	else if (leg.timer >= 1975 && leg.timer < 2000) {//
		leg.connector.angle += 1.0f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.016f * direction, -0.004f * direction);
		leg.upper.translation += glm::vec3(0.0f, -0.016f * direction, -0.004f * direction);
		leg.connector.translation += glm::vec3(0.0f, +0.02f * direction, -0.048f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.016f * direction, -0.004f * direction);
	}
	else if (leg.timer >= 2000) {
		//leg.foot.translation.y = 0.0f;
		//leg.lower.translation.y = -0.85f;
		//leg.upper.translation.y = -0.85f;
		//leg.connector.translation.y = 0.5f;
		//std::cout << "kat dolna" << leg.lower.angle << std::endl;
		//std::cout << "kat gorna" << leg.upper.angle << std::endl;
		//std::cout << "kat konektor" << leg.connector.angle << std::endl;
		//std::cout << "stopa: " << glm::to_string(leftFrontLeg.foot.translation) << std::endl;
		//std::cout << "dolna: " << glm::to_string(leftFrontLeg.lower.translation) << std::endl;
		//std::cout << "gorna: " << glm::to_string(leftFrontLeg.upper.translation) << std::endl;
		//std::cout << "konektor: " << glm::to_string(leftFrontLeg.connector.translation) << std::endl;
		leg.timer = 0;
	}
	return leg;
}

legAnimation Model::updateLegBack(legAnimation leg) {
	//std::cout << leg.timer << std::endl;
	leg.timer += 1 * direction;
	if (leg.timer < 0) {
		leg.timer = 1999;
	}
	else if (leg.timer >= 0 && leg.timer < 250) {
		leg.lower.angle += 0.04f * direction;
		leg.upper.angle += 0.04f * direction;
		leg.connector.angle += 0.02f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.0008f * direction, +0.000f * direction);
		leg.upper.translation += glm::vec3(0.0f, -0.0008f * direction, +0.000f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.0001f * direction, 0.001f * direction);
	}
	else if (leg.timer >= 500 && leg.timer < 750) {
		leg.lower.angle += 0.04f * direction;
		leg.upper.angle += 0.04f * direction;
		leg.connector.angle += 0.02f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.0008f * direction, +0.000f * direction);
		leg.upper.translation += glm::vec3(0.0f, -0.0008f * direction, +0.000f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.0001f * direction, 0.001f * direction);
	}
	else if (leg.timer >= 1000 && leg.timer < 1250) {
		leg.lower.angle += 0.06f * direction;
		leg.upper.angle += 0.06f * direction;
		leg.connector.angle -= 0.046f * direction;
		leg.lower.translation += glm::vec3(0.00f, -0.00106f * direction, -0.0004f * direction);
		leg.upper.translation += glm::vec3(0.00f, -0.00106f * direction, -0.0004f * direction);
		leg.connector.translation += glm::vec3(0.00f, +0.0005f * direction, 0.0051f * direction);
	}
	else if (leg.timer >= 1500 && leg.timer < 1750) {
		leg.lower.angle += 0.06f * direction;
		leg.upper.angle += 0.06f * direction;
		leg.connector.angle -= 0.046f * direction;
		leg.lower.translation += glm::vec3(0.00f, -0.00106f * direction, -0.0004f * direction);
		leg.upper.translation += glm::vec3(0.00f, -0.00106f * direction, -0.0004f * direction);
		leg.connector.translation += glm::vec3(0.00f, +0.0005f * direction, 0.0051f * direction);
	}
	else if (leg.timer >= 1750 && leg.timer < 1775) {
		leg.connector.angle += 0.92f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.0152f * direction, -0.002f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.0152f * direction, -0.002f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.01f * direction, -0.046f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.0152f * direction, -0.002f * direction);
	}
	else if (leg.timer >= 1775 && leg.timer < 1800) {
		leg.connector.angle += 0.4f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.008f * direction, 0.002f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.008f * direction, 0.002f * direction);
		leg.connector.translation += glm::vec3(0.0f, 0.002f * direction, -0.02f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.008f * direction, 0.002f * direction);
	}
	else if (leg.timer >= 1800 && leg.timer < 1825) {
		leg.upper.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.004f * direction, 0.018f * direction);
		leg.upper.translation += glm::vec3(0.0f, -0.002f * direction, 0.036f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.004f * direction, 0.018f * direction);
	}
	else if (leg.timer >= 1825 && leg.timer < 1850) {
		leg.upper.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.004f * direction, 0.014f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.006f * direction, 0.032f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.004f * direction, 0.014f * direction);
	}
	else if (leg.timer >= 1850 && leg.timer < 1875) {
		leg.upper.angle -= 0.8f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.006f * direction, 0.018f * direction);
		leg.upper.translation += glm::vec3(0.0f, 0.024f * direction, 0.038f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.006f * direction, 0.018f * direction);
	}
	else if (leg.timer >= 1875 && leg.timer < 1900) {
		leg.lower.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.004f * direction, 0.02f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.0052f * direction, 0.014f * direction);
	}
	else if (leg.timer >= 1900 && leg.timer < 1925) {
		leg.lower.angle -= 0.6f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.01f * direction, 0.016f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.002f * direction, 0.014f * direction);
	}
	else if (leg.timer >= 1925 && leg.timer < 1950){
		leg.lower.angle -= 0.8f * direction;
		leg.lower.translation += glm::vec3(0.0f, 0.016f * direction, 0.02f * direction);
		leg.foot.translation += glm::vec3(0.0f, 0.0f, 0.02f * direction);
	}
	else if (leg.timer >= 1950 && leg.timer < 1975) {
		leg.connector.angle -= 0.4f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.008f * direction, -0.002f * direction);
		leg.upper.translation += glm::vec3(0.0f, -0.008f * direction, -0.002f * direction);
		leg.connector.translation += glm::vec3(0.0f, -0.002f * direction, 0.02f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.008f * direction, -0.002f * direction);
	}
	else if (leg.timer >= 1975 && leg.timer < 2000) {
		leg.connector.angle -= 0.4f * direction;
		leg.lower.translation += glm::vec3(0.0f, -0.006f * direction, -0.00f);
		leg.upper.translation += glm::vec3(0.0f, -0.006f * direction, -0.00f);
		leg.connector.translation += glm::vec3(0.0f, 0.002f * direction, 0.02f * direction);
		leg.foot.translation += glm::vec3(0.0f, -0.006f * direction, -0.00f);
	}
	else if (leg.timer >= 2000) {
		//leg.foot.translation.y = 0.0f;
		//leg.lower.translation.y = 0.4f;
		//leg.upper.translation.y = 0.4f;
		//leg.connector.translation.y = 0.05f;
		/*
		std::cout << "kat dolna" << leg.lower.angle << std::endl;
		std::cout << "kat gorna" << leg.upper.angle << std::endl;
		std::cout << "kat konektor" << leg.connector.angle << std::endl;
		std::cout << "stopa: " << glm::to_string(leg.foot.translation) << std::endl;
		std::cout << "dolna: " << glm::to_string(leg.lower.translation) << std::endl;
		std::cout << "gorna: " << glm::to_string(leg.upper.translation) << std::endl;
		std::cout << "konektor: " << glm::to_string(leg.connector.translation) << std::endl;
		*/
		leg.timer = 0;
	}
	return leg;
}

body Model::updateBody(body body) {
	body.timer += 1 * direction;
	if (body.timer < 0) {
		body.timer = 1999;
	}
	else if (body.timer >= 250 && body.timer < 500) {
		body.translation += glm::vec3(0.0f, 0.0f, 0.0024f * direction);
	}
	else if (body.timer >= 750 && body.timer < 1000) {
		body.translation += glm::vec3(0.0f, 0.0f, 0.0024f * direction);
	}
	else if (body.timer >= 1250 && body.timer < 1500) {
		body.translation += glm::vec3(0.0f, 0.0f, 0.0024f * direction);
	}
	else if (body.timer >= 1750 && body.timer < 2000) {
		body.translation += glm::vec3(0.0f, 0.0f, 0.0024f * direction);
	}
	else if (body.timer >= 2000) {
		body.timer = 0;
	}
	return body;
}

head Model::updateHead(head head) {
	head.timer += 1 * headSpin;

	if (head.timer < -160) {
		head.timer = -161.0f;
	}
	else if (head.timer < -120 && head.timer >= -160) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.01f * headSpin, 0.0f, -0.0065f * headSpin);
	}
	else if (head.timer < -80 && head.timer >= -120) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.0125f * headSpin, 0.0f, -0.003f * headSpin);
	}
	else if (head.timer < -40 && head.timer >= -80) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.01125f * headSpin, 0.0f, -0.00325f * headSpin);
	}
	else if (head.timer < 0 && head.timer >= -40) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.01375f * headSpin, 0.0f, -0.00125f * headSpin);
	}
	else if (head.timer == 0) {
		head.position.translation = glm::vec3(0.0f, 0.0f, 0.0f);
		head.position.angle = 0;
	}
	else if (head.timer > 0 && head.timer <= 40) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.01375f * headSpin, 0.0f, 0.00125f * headSpin);
	}
	else if (head.timer > 40 && head.timer <= 80) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.01125f * headSpin, 0.0f, 0.00325f * headSpin);
	}
	else if (head.timer > 80 && head.timer <= 120) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.0125f * headSpin, 0.0f, 0.003f * headSpin);
	}
	else if (head.timer > 120 && head.timer <= 160) {
		head.position.angle += 0.25f * headSpin;
		head.position.translation += glm::vec3(-0.01f * headSpin, 0.0f, 0.0065f * headSpin);
	}
	else if (head.timer > 160) {
		head.timer = 161 * headSpin;
	}
	return head;
}

Model::Model() {
	leftFrontLeg.timer = 1750;
	leftFrontLeg.upper.angle = 20.0f;
	leftFrontLeg.lower.angle = 20.0f;
	leftFrontLeg.connector.angle = 10.0f;
	leftFrontLeg.lower.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	leftFrontLeg.upper.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	leftFrontLeg.connector.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	leftFrontLeg.foot.translation = glm::vec3(0.0f, 0.0f, -1.1f);
	leftFrontLeg.upper.translation = glm::vec3(0.0f, 0.6f, -1.05f);
	leftFrontLeg.lower.translation = glm::vec3(0.0f, 0.6f, -1.05f);
	leftFrontLeg.connector.translation = glm::vec3(0.0f, 0.15f, -0.5f);

	leftBackLeg.timer = 1250;
	leftBackLeg.upper.angle = 15.0f;
	leftBackLeg.lower.angle = 15.0f;
	leftBackLeg.connector.angle = -11.5f;
	leftBackLeg.lower.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	leftBackLeg.upper.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	leftBackLeg.connector.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	leftBackLeg.foot.translation = glm::vec3(0.0f, 0.0f, -0.675f);
	leftBackLeg.upper.translation = glm::vec3(0.0f, -0.265f, -0.775f);
	leftBackLeg.lower.translation = glm::vec3(0.0f, -0.265f, -0.775f);
	leftBackLeg.connector.translation = glm::vec3(0.0f, 0.125f, 0.6f);

	rightFrontLeg.timer = 750;
	rightFrontLeg.upper.angle = 0.0f;
	rightFrontLeg.lower.angle = 0.0f;
	rightFrontLeg.connector.angle = 0.0f;
	rightFrontLeg.lower.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	rightFrontLeg.upper.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	rightFrontLeg.connector.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	rightFrontLeg.foot.translation = glm::vec3(0.0f, 0.0f, 0.0f);
	rightFrontLeg.upper.translation = glm::vec3(0.0f, 0.0f, 0.0f);
	rightFrontLeg.lower.translation = glm::vec3(0.0f, 0.0f, 0.0f);
	rightFrontLeg.connector.translation = glm::vec3(0.0f, 0.00f, 0.0f);

	rightBackLeg.timer = 250;
	rightBackLeg.upper.angle = -10.0f;
	rightBackLeg.lower.angle = -10.0f;
	rightBackLeg.connector.angle = -5.0f;
	rightBackLeg.lower.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	rightBackLeg.upper.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	rightBackLeg.connector.rotation = glm::vec3(1.0f, 0.0f, 0.0f);
	rightBackLeg.foot.translation = glm::vec3(0.0f, 0.0f, 0.45f);
	rightBackLeg.upper.translation = glm::vec3(0.0f, 0.2f, 0.45f);
	rightBackLeg.lower.translation = glm::vec3(0.0f, 0.2f, 0.45f);
	rightBackLeg.connector.translation = glm::vec3(0.0f, 0.025f, 0.2f);

	bodyTransformation.translation = glm::vec3(0.0f, 0.0f, 0.0f);
	bodyTransformation.timer = 0;

	headTransformation.position.angle = 0;
	headTransformation.position.rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	headTransformation.position.translation = glm::vec3(0.0f, 0.0f, 0.0f);
	headTransformation.timer = 0;
};

void Model::loadModel(std::string plik) {
	const aiScene* scene = importer.ReadFile(plik,
		aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals); //³adowanie pliku do programu
	std::cout << importer.GetErrorString() << std::endl;
	for (int i = 0; i < scene->mNumMeshes; i++) { //przejœcie po wszystkich meshach w pliku
		aiMesh* mesh = scene->mMeshes[i];
		std::cout << "Laduje mesh: " << meshes.size() << std::endl;
		Mesh newMesh;
		newMesh.loadMesh(mesh); //za³adowanie meshu
		meshes.push_back(newMesh); //dodanie mesha do wektora meshów
	}
}

void Model::drawModel(glm::mat4 P, glm::mat4 V) { //rysowanie meshu
	updateModel();
	for (int i = 0; i < meshes.size(); i++) { 
		glm::mat4 M = glm::mat4(1.0f);
		M = glm::translate(M, glm::vec3(0.0f, 0.06f, 0.0f));
		M = glm::rotate(M, glm::radians(180.0f), glm::vec3(0, 1, 0));
		if (i < 7) {
			M = bodyTransform(M);
			M = headTransform(M);
		}
		else if (i == 7 || i == 9 || (i >= 19 && i <= 30)) {
			M = leftFrontLegTransform(i, M);
		}
		else if ((i >= 11 && i <= 12) || (i >= 31 && i <= 42)) {
			M = leftBackLegTransform(i, M);
		}
		else if (i == 17 || i == 18 || (i >= 44 && i <= 55)) {
			M = rightFrontLegTransform(i, M);
		}
		else if (i == 15 || i == 16 || (i >= 56 && i <= 67)) {
			M = rightBackLegTransform(i, M);
		}
		else {
			M = bodyTransform(M);
		}
		spLambertTextured->use(); //Aktywuj program cieniuj¹cy
		glUniformMatrix4fv(spLambertTextured->u("P"), 1, false, glm::value_ptr(P)); //Za³aduj do programu cieniuj¹cego macierz rzutowania
		glUniformMatrix4fv(spLambertTextured->u("V"), 1, false, glm::value_ptr(V)); //Za³aduj do programu cieniuj¹cego macierz widoku
		glUniformMatrix4fv(spLambertTextured->u("M"), 1, false, glm::value_ptr(M)); //Za³aduj do programu cieniuj¹cego macierz modelu
		meshes[i].drawMesh();
		glDisableVertexAttribArray(spLambertTextured->a("vertex"));
		glDisableVertexAttribArray(spLambertTextured->a("texCoord"));
		glDisableVertexAttribArray(spLambertTextured->a("normal"));
	}
}

void Model::updateModel() {
	if (direction != 0) {
		rightFrontLeg = updateLegFront(rightFrontLeg);
		rightBackLeg = updateLegBack(rightBackLeg);
		leftFrontLeg = updateLegFront(leftFrontLeg);
		leftBackLeg = updateLegBack(leftBackLeg);
		bodyTransformation = updateBody(bodyTransformation);
	}
	if (headSpin != 0)
		headTransformation = updateHead(headTransformation);
}

glm::mat4 Model::headTransform(glm::mat4 M) {
	M = glm::translate(M, headTransformation.position.translation);
	M = glm::rotate(M, glm::radians(headTransformation.position.angle), headTransformation.position.rotation);
	return M;
}

glm::mat4 Model::bodyTransform(glm::mat4 M) {
	M = glm::translate(M, bodyTransformation.translation);
	return M;
}

glm::mat4 Model::leftFrontLegTransform(int meshID, glm::mat4 M) {
	if (meshID == 24) { //foot
		M = glm::translate(M, leftFrontLeg.foot.translation);
	}
	else if ((meshID >= 19 && meshID <= 23) || (meshID >= 25 && meshID <= 27)) {//lower part of the leg
		M = glm::translate(M, leftFrontLeg.lower.translation);
		M = glm::rotate(M, glm::radians(leftFrontLeg.lower.angle), leftFrontLeg.lower.rotation);
	}
	else if ((meshID >= 28 && meshID <= 30) || meshID == 7) { //Upper part of the leg
		M = glm::translate(M, leftFrontLeg.upper.translation);
		M = glm::rotate(M, glm::radians(leftFrontLeg.upper.angle), leftFrontLeg.upper.rotation);
	}

	else if (meshID == 9) {
		M = glm::translate(M, leftFrontLeg.connector.translation); //leg and body connector
		M = glm::rotate(M, glm::radians(leftFrontLeg.connector.angle), leftFrontLeg.connector.rotation);
	}
	return M;
}

glm::mat4 Model::leftBackLegTransform(int meshID, glm::mat4 M) {
	if (meshID == 36) { //foot
		M = glm::translate(M, leftBackLeg.foot.translation);
	}
	else if ((meshID >= 31 && meshID <= 35) || (meshID >= 37 && meshID <= 39)) {//lower part of the leg
		M = glm::translate(M, leftBackLeg.lower.translation);
		M = glm::rotate(M, glm::radians(leftBackLeg.lower.angle), leftBackLeg.lower.rotation);
	}
	else if ((meshID >= 40 && meshID <= 42) || meshID == 11) { //Upper part of the leg
		M = glm::translate(M, leftBackLeg.upper.translation);
		M = glm::rotate(M, glm::radians(leftBackLeg.upper.angle), leftBackLeg.upper.rotation);
	}
	else if (meshID == 12) {
		M = glm::translate(M, leftBackLeg.connector.translation); //leg and body connector
		M = glm::rotate(M, glm::radians(leftBackLeg.connector.angle), leftBackLeg.connector.rotation);
	}
	return M;
}

glm::mat4 Model::rightFrontLegTransform(int meshID, glm::mat4 M) {
	if (meshID == 49) { //foot
		M = glm::translate(M, rightFrontLeg.foot.translation);
	}
	else if ((meshID >= 44 && meshID <= 48) || (meshID >= 50 && meshID <= 52)) {//lower part of the leg
		M = glm::translate(M, rightFrontLeg.lower.translation);
		M = glm::rotate(M, glm::radians(rightFrontLeg.lower.angle), rightFrontLeg.lower.rotation);
	}
	else if ((meshID >= 53 && meshID <= 55) || meshID == 18) { //Upper part of the leg
		M = glm::translate(M, rightFrontLeg.upper.translation);
		M = glm::rotate(M, glm::radians(rightFrontLeg.upper.angle), rightFrontLeg.upper.rotation);
	}

	else if (meshID == 17) {
		M = glm::translate(M, rightFrontLeg.connector.translation); //leg and body connector
		M = glm::rotate(M, glm::radians(rightFrontLeg.connector.angle), rightFrontLeg.connector.rotation);
	}
	return M;
}

glm::mat4 Model::rightBackLegTransform(int meshID, glm::mat4 M) {
	if (meshID == 61) { //foot
		M = glm::translate(M, rightBackLeg.foot.translation);
	}
	else if ((meshID >= 56 && meshID <= 60) || (meshID >= 62 && meshID <= 64)) {//lower part of the leg
		M = glm::translate(M, rightBackLeg.lower.translation);
		M = glm::rotate(M, glm::radians(rightBackLeg.lower.angle), rightBackLeg.lower.rotation);
	}
	else if ((meshID >= 65 && meshID <= 67) || meshID == 16) { //Upper part of the leg
		M = glm::translate(M, rightBackLeg.upper.translation);
		M = glm::rotate(M, glm::radians(rightBackLeg.upper.angle), rightBackLeg.upper.rotation);
	}
	else if (meshID == 15) {
		M = glm::translate(M, rightBackLeg.connector.translation); //leg and body connector
		M = glm::rotate(M, glm::radians(rightBackLeg.connector.angle), rightBackLeg.connector.rotation);
	}
	return M;
}
#endif
