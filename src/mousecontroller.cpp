#include "../include/mousecontroller.h"
#include "../include/event.h"
#include "../include/nsinputmanagercontroller.h"

#include "../lib/glfw.h"

CMouseController::CMouseController() {
}

uint8 CMouseController::Init() {
	uint8 ret = 0;
	if (!glfwInit()) {
		ret = 1;
	}
	return ret;
}

CMouseController::~CMouseController() {
	glfwTerminate();
}

void CMouseController::Update() {
	glfwGetMousePos(&m_mouseX, &m_mouseY);
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		SendEvent(EME_LMB_PRESS);
	}
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		SendEvent(EME_LMB_RELEASE);
	}
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		SendEvent(EME_RMB_PRESS);
	}
	if (glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE) {
		SendEvent(EME_RMB_RELEASE);
	}
}

void CMouseController::SendEvent(const uint32 id) {
	CEvent * ev = new CEvent(EEC_MOUSE, id, m_mouseX, m_mouseY);
	IInputManagerController::AddEvent(ev);
}