#include <QApplication>
#include <QLabel>
int main(int argc, char* argv[] ) {
   QApplication app(argc, argv);
   QLabel *label = new QLabel("select port to log data");
   label->setWindowTitle("ComPort Sniffer");
   label->resize(800,600);
   label->show();
   return app.exec();
}
