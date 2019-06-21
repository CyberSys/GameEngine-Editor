#include "SceneEditorGL.h"
#include <graphics\GraphicsGL.h>
using namespace Graphics;

SceneEditorGL::SceneEditorGL(QWidget *parent) : QOpenGLWidget(parent)
{

}

SceneEditorGL::~SceneEditorGL()
{
}

void SceneEditorGL::PassContainerWidget(QDockWidget * SpriteEditor)
{
	SEditor = SpriteEditor;
}


void SceneEditorGL::initializeGL()
{
	Graphics::GAPI_Init();
	Graphics::GAPI_Enable(Graphics::GLcapability::BLENDING);

	camera = std::make_shared<Camera2D>(this->width(), this->height());

	checkboard_BG = new Sprite2D("resources/EditorBG.png");
	checkboard_BG->_transform->SetScale(glm::vec3(this->width(), this->height(),1));
	checkboard_BG->_transform->SetTransformMatrix(camera->GetViewProjectionMat());
	checkboard_BG->_material->SetUVs(glm::vec2(30,15));
	checkboard_BG->_material->SetColor(glm::vec4(0.5,0.7,0.9,1));


	//////////////////////////////////////////////
	outline = new OutlineRect();
	outline->_transform->SetPosition(glm::vec3(400,150,0));
	outline->_transform->SetScale(glm::vec3(700, 500, 1));
	outline->_transform->SetTransformMatrix(camera->GetViewProjectionMat());

	//////////////////////////////////////////////
	Game_BG = new Sprite2D("resources/Game_Background_38.png");
	Game_BG->_transform->SetPosition(glm::vec3(350, 230, 0));
	Game_BG->_transform->SetScale(glm::vec3(812,456, 1));
	Game_BG->_transform->SetTransformMatrix(camera->GetViewProjectionMat());


	game_char = new Sprite2D("resources/drackola.png");
	game_char->_transform->SetPosition(glm::vec3(600, 520, 0));
	game_char->_transform->SetScale(glm::vec3(100, 100, 1));
	game_char->_transform->SetTransformMatrix(camera->GetViewProjectionMat());

	Charoutline = new OutlineRect();
	Charoutline->_transform->SetPosition(glm::vec3(600, 520, 0));
	Charoutline->_transform->SetScale(glm::vec3(100, 100, 1));
	Charoutline->_transform->SetTransformMatrix(camera->GetViewProjectionMat());
	Charoutline->_material->SetColor(glm::vec4(0.3, 0.4, 0.9, 1));

}

void SceneEditorGL::paintGL()
{

	Graphics::GAPI_ClearBuffers();
	Graphics::GAPI_SetClearColor(0, 0, 0, 1);

	checkboard_BG->Draw();
	
	//to draw game elemnts here..
	Game_BG->Draw();
	game_char->Draw();
	Charoutline->Draw();

	outline->Draw();
}

void SceneEditorGL::mousePressEvent(QMouseEvent * event)
{
}

void SceneEditorGL::mouseMoveEvent(QMouseEvent * event)
{
}
