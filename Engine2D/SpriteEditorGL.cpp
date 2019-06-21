#include "SpriteEditorGL.h"
#include <graphics\GraphicsGL.h>
using namespace Graphics;

SpriteEditorGL::SpriteEditorGL(QWidget *parent) : QOpenGLWidget(parent)
{

}

SpriteEditorGL::~SpriteEditorGL()
{
	delete checkboard_BG; delete sp; delete outline;
}

void SpriteEditorGL::PassContainerWidget(QDockWidget * SpriteEditor)
{
	SEditor = SpriteEditor;
}


void SpriteEditorGL::initializeGL()
{
	Graphics::GAPI_Init();
	Graphics::GAPI_Enable(Graphics::GLcapability::BLENDING);

	camera = std::make_shared<Camera2D>(this->width(), this->height());

	checkboard_BG = new Sprite2D("resources/EditorBG.png");
	checkboard_BG->_transform->SetScale(glm::vec3(this->width(), this->height(),1));
	checkboard_BG->_transform->SetTransformMatrix(camera->GetViewProjectionMat());
	checkboard_BG->_material->SetUVs(glm::vec2(12));

	//////////////////////////////////////////////
	sp = new Sprite2D("resources/sprite.png");
	sp->_transform->SetScale(glm::vec3(this->width(), this->height(), 1));
	sp->_transform->SetTransformMatrix(camera->GetViewProjectionMat());

	//////////////////////////////////////////////
	outline = new OutlineRect();
	outline->_transform->SetScale(glm::vec3(this->width() - 100, this->height() - 100, 1));
	outline->_transform->SetTransformMatrix(camera->GetViewProjectionMat());


	/////////////////////////////////////////////
	SEditor->setMinimumSize(sp->_texture->GetDimensions().x, sp->_texture->GetDimensions().y);
	SEditor->setMaximumSize(sp->_texture->GetDimensions().x, sp->_texture->GetDimensions().y);
}

void SpriteEditorGL::paintGL()
{

	Graphics::GAPI_ClearBuffers();
	Graphics::GAPI_SetClearColor(0, 0, 0, 1);

	checkboard_BG->Draw();
	sp->Draw();
//	outline->Draw();
}

void SpriteEditorGL::mousePressEvent(QMouseEvent * event)
{
}

void SpriteEditorGL::mouseMoveEvent(QMouseEvent * event)
{
}
