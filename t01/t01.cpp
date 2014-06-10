#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argv, char **args)
{
	QApplication app(argv, args);

	QLabel *label = new QLabel("Hello, World!");
	QPushButton *quitButton = new QPushButton("&OK");
	quitButton->setDefault(true);

	QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
	layout->addWidget(quitButton);

	QWidget window;
	window.setLayout(layout);

	window.show();
	window.update();
	
	window.close();

}
