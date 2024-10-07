#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>

void printHello() {
    QMessageBox::information(nullptr, "Message", "Hello World");
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Olá Mundo");
    window.resize(200, 200);

    QPushButton *button = new QPushButton("Hello World", &window);
    QObject::connect(button, &QPushButton::clicked, &printHello);
    QObject::connect(button, &QPushButton::clicked, &window, &QWidget::close);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);

    window.setLayout(layout);
    window.show();

    return app.exec();
}
