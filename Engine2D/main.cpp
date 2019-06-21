#include "MainWindow.h"
#include <QtWidgets/QApplication>

#include <QApplication>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QTextStream>

int main(int argc, char *argv[])
{


	QApplication a(argc, argv);

	QFile f("qdarkstyle/style.qss");
	if (!f.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}

	MainWindow w;


	w.show();
	return a.exec();
}