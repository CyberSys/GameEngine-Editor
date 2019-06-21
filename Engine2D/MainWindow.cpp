#include "MainWindow.h"

#include <QDockwidget.h>
#include <QMenubar.h>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <qapplication.h>
#include <qdesktopwidget.h>




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	QWidget *EngineWindow = new QWidget();
	setCentralWidget(EngineWindow);
	QVBoxLayout *mainLayout = new QVBoxLayout;
	EngineWindow->setLayout(mainLayout);
	
	

	//spriteEditor action to menu bar....
	sprite_editor_menu_action = new QAction(tr("&Sprite Editor"), this);
	sprite_editor_menu_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
	sprite_editor_menu_action->setStatusTip(tr("Open Sprite Editor"));
	connect(sprite_editor_menu_action, &QAction::triggered, this, &MainWindow::SpriteEditor);

	//Inspector action to menu bar....
	Inspector_menu_action = new QAction(tr("&Inspector"), this);
	Inspector_menu_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_I));
	Inspector_menu_action->setStatusTip(tr("Open Inspector Window"));
	connect(Inspector_menu_action, &QAction::triggered, this, &MainWindow::Inspector);

	//FileSystem action to menu bar....
	FileSystem_menu_action = new QAction(tr("&Project Files"), this);
	FileSystem_menu_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_P));
	FileSystem_menu_action->setStatusTip(tr("Open Project Files Window"));
	connect(FileSystem_menu_action, &QAction::triggered, this, &MainWindow::FileSystem);

	//menubar
	fileMenu = menuBar()->addMenu(tr("&File"));
	editMenu = menuBar()->addMenu(tr("&Edit"));

	assetsMenu = menuBar()->addMenu(tr("&Assets"));
	//load asset into asset manager and file path tree

	windowMenu = menuBar()->addMenu(tr("&Window"));
	windowMenu->addAction(sprite_editor_menu_action);
	windowMenu->addAction(Inspector_menu_action);
	windowMenu->addAction(FileSystem_menu_action);



	//init all layouts..
	Inspector();
	SpriteEditor();
	Scene(EngineWindow);
	FileSystem();

	QRect rec = QApplication::desktop()->screenGeometry();
	this->setMinimumSize(rec.width(), rec.height());
	this->showMaximized();
	
	
}

void MainWindow::SpriteEditor()
{
	//sprite editor..
	QDockWidget *SpriteEditor = new QDockWidget(tr("Sprite Editor"), this);
	SpriteEditorGL *SE = new SpriteEditorGL(SpriteEditor);
	SE->PassContainerWidget(SpriteEditor);
	SpriteEditor->setWidget(SE);
	addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, SpriteEditor);
}

void MainWindow::Inspector()
{
	//main layout features..
	QWidget *inspectorWindow = new QWidget();
	QVBoxLayout *mainLayout = new QVBoxLayout;
	inspectorWindow->setLayout(mainLayout);


	QGroupBox *gridGroupBox = new QGroupBox(tr("Transformation"));
	gridGroupBox->setCheckable(true);
	gridGroupBox->setStyleSheet("QGroupBox::indicator {   margin-left: 6px; width: 17px; height: 17px; } QGroupBox::indicator { image: url(Resources/TransformationIcon.png); }");
	QGridLayout *layout = new QGridLayout;

	QLabel *labels[12];
	QLineEdit *lineEdits[9];

	//for Position
	labels[0] = new QLabel("Position");
	labels[1] = new QLabel("X");
	labels[2] = new QLabel("Y");
	labels[3] = new QLabel("Z");
	lineEdits[0] = new QLineEdit;
	lineEdits[1] = new QLineEdit;
	lineEdits[2] = new QLineEdit;
	layout->addWidget(labels[0],0, 0);
	layout->addWidget(labels[1], 0, 1);
	layout->addWidget(labels[2], 0, 3);
	layout->addWidget(labels[3], 0, 5);
	layout->addWidget(lineEdits[0], 0, 2);
	layout->addWidget(lineEdits[1], 0, 4);
	layout->addWidget(lineEdits[2], 0, 6);

	//for Rotation
	labels[4] = new QLabel("Rotation");
	labels[5] = new QLabel("X");
	labels[6] = new QLabel("Y");
	labels[7] = new QLabel("Z");
	lineEdits[3] = new QLineEdit;
	lineEdits[4] = new QLineEdit;
	lineEdits[5] = new QLineEdit;
	layout->addWidget(labels[4], 1, 0);
	layout->addWidget(labels[5], 1, 1);
	layout->addWidget(labels[6], 1, 3);
	layout->addWidget(labels[7], 1, 5);
	layout->addWidget(lineEdits[3], 1, 2);
	layout->addWidget(lineEdits[4], 1, 4);
	layout->addWidget(lineEdits[5], 1, 6);

	//for Scale
	labels[8] = new QLabel("Scale");
	labels[9] = new QLabel("X");
	labels[10] = new QLabel("Y");
	labels[11] = new QLabel("Z");
	lineEdits[6] = new QLineEdit;
	lineEdits[7] = new QLineEdit;
	lineEdits[8] = new QLineEdit;
	layout->addWidget(labels[8], 2, 0);
	layout->addWidget(labels[9], 2, 1);
	layout->addWidget(labels[10], 2, 3);
	layout->addWidget(labels[11], 2, 5);
	layout->addWidget(lineEdits[6], 2, 2);
	layout->addWidget(lineEdits[7], 2, 4);
	layout->addWidget(lineEdits[8], 2, 6);
	layout->setColumnStretch(0, 10);
	gridGroupBox->setMaximumHeight(200);
	gridGroupBox->setLayout(layout);
	mainLayout->addWidget(gridGroupBox);

	////////////////////////////////////////////////////////////////////////////////////////////////////////


	//docking..
	QDockWidget *_Inspector = new QDockWidget(tr("Inspector"), this);
	_Inspector->setWidget(inspectorWindow);
	addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, _Inspector,Qt::Orientation::Vertical);
	//_Inspector->setFloating(true);
	_Inspector->setMinimumSize(200,300);
	_Inspector->setMaximumSize(400, 300);
}




void MainWindow::FileSystem()
{
	QDockWidget *qDock = new QDockWidget(tr("File Browser"),this);
	qDock->setAllowedAreas(Qt::AllDockWidgetAreas);

	QTreeView *qTreeView = new QTreeView();

	QString path = QDir::currentPath();
	QFileSystemModel *qFSModel = new QFileSystemModel();
	qFSModel->setRootPath(path);
	qTreeView->setModel(qFSModel);

	QModelIndex indexPath = qFSModel->index(path);
	qTreeView->scrollTo(indexPath);


	// Demonstrating look and feel features
	qTreeView->setAnimated(false);
	qTreeView->setIndentation(20);
	qTreeView->setSortingEnabled(true);
	const QSize availableSize = QApplication::desktop()->availableGeometry(qTreeView).size();
	qTreeView->resize(availableSize / 2);
	qTreeView->setColumnWidth(0, qTreeView->width() / 3);

	qTreeView->setWindowTitle(QObject::tr("Dir View"));
	qTreeView->show();

	qDock->setWidget(qTreeView);

    this->addDockWidget(Qt::BottomDockWidgetArea, qDock);


	//FileSystem_SelectItem
	//capture list lambda function cannot capture local variable 
	//you must make it buy refrence..
	connect(qTreeView, &QTreeView::clicked, this, [&,qTreeView, qFSModel]{ FileSystem_SelectItem(qTreeView, qFSModel); });
}

void MainWindow::FileSystem_SelectItem(QTreeView *qTreeView, QFileSystemModel *qFSModel)
{
	auto indx = qTreeView->selectionModel()->selectedIndexes();
	QString filepath =  qFSModel->filePath(indx[0]);
}

void MainWindow::Scene(QWidget *w)
{
	//sprite editor..
	QDockWidget *SceneEditor = new QDockWidget(tr("Scene Editor"), this);
	SceneEditorGL *SE = new SceneEditorGL(SceneEditor);
	SE->PassContainerWidget(SceneEditor);
	SceneEditor->setWidget(SE);
	SceneEditor->setMinimumSize(1500, height());
	addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, SceneEditor);
}