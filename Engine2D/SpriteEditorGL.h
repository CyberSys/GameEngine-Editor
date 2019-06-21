#pragma once

#include <QOpenGLWidget>
#include <QDockwidget.h>

#include <renderer\Sprite2D.h>
#include <renderer\OutlineRect.h>
#include <renderer\SpriteMaterial.h>
#include <renderer\Rectangle2D.h>
#include <renderer\MeshFilter.h>
#include <renderer\Camera2D.h>


using namespace Renderer;
class SpriteEditorGL : public QOpenGLWidget
{
	Q_OBJECT

public:
	SpriteEditorGL(QWidget *parent);
	~SpriteEditorGL();

	void PassContainerWidget(QDockWidget *SpriteEditor);



protected:
	void initializeGL() override;
	void paintGL() override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;

private:
	QDockWidget *SEditor;

	std::shared_ptr<SpriteMaterial> mat;
	Mesh* mesh;

	Sprite2D* checkboard_BG;
	Sprite2D* sp;
	OutlineRect* outline;
	std::shared_ptr<Camera2D> camera;
};