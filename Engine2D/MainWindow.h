#pragma once
#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <qabstractitemview.h>

#include <SpriteEditorGL.h>
#include <SceneEditorGL.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

	

private slots:
	void SpriteEditor();
	void Inspector();
	void FileSystem();
	void FileSystem_SelectItem(QTreeView *qTreeView, QFileSystemModel *qFSModel);
	void Scene(QWidget *w);

private:
	QMenu* fileMenu;
	QMenu* editMenu;
	QMenu* assetsMenu;
	QMenu* windowMenu;

	QAction *sprite_editor_menu_action;
	QAction *Inspector_menu_action;
	QAction *FileSystem_menu_action;
};
