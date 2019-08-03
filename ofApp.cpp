#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);

	auto radius = 500;
	for (int i = 0; i < 150; i++) {

		auto deg_speed = ofRandom(2, 4);
		auto deg_param = ofRandom(360) + ofGetFrameNum() * deg_speed;
		auto z_speed = ofRandom(2, 10);
		auto z_param = ofRandom(600) + ofGetFrameNum() * z_speed;

		glm::vec3 prev_location;
		for (int k = 0; k < 10; k++) {

			auto deg = deg_param + k * deg_speed;
			auto z = (int)(z_param + k * z_speed) % 600 - 300;

			auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);

			auto alpha = 255;
			if (location.y > 0) {

				alpha = ofMap(location.y, 0, 500, 255, 64);
			}

			ofSetColor(39, alpha);
			if (prev_location != glm::vec3() && glm::distance(prev_location, location) < 300) {

				ofDrawLine(prev_location, location);
			}

			prev_location = location;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}