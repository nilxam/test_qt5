#include <QtGui>
#include <QtWidgets>

extern "C"

int runUI(int argc, char *argv[])
{
	QApplication a(argc,argv);

	QWidget *window = new QWidget;

	QPushButton *btn1 = new QPushButton("Hello World");
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(btn1);

	window->setLayout(layout);
	window->show();
	window->update();
	//QTime t;
	//t.start();
	//while(t.elapsed()<1000)
	//	QCoreApplication::processEvents();

	window->close();

	//return a.exec();
	return 0;
}
