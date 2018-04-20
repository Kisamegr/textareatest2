#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QFile htmlFile(":/test.html");
  QString data;
  if (htmlFile.open(QFile::ReadOnly | QFile::Text)) {
    QTextStream in(&htmlFile);
    data = in.readAll();
  }

  QQmlApplicationEngine engine;

  engine.rootContext()->setContextProperty("textData", data);
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}
