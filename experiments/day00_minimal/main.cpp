#include <QApplication>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "app_info.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setObjectName("mainWindow");
    window.setWindowTitle(QString::fromUtf8(app_name()));
    window.resize(1024, 600);

    QLabel *titleLabel = new QLabel(&window);

    titleLabel->setText(
        QString("%1\nVersion: %2")
            .arg(QString::fromUtf8(app_name()))
            .arg(QString::fromUtf8(app_version()))
    );

    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "font-size: 36px;"
        "color: white;"
    );

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(titleLabel);

    window.setStyleSheet(
        "#mainWindow {"
        "background-color: #202733;"
        "}"
    );

    window.showFullScreen();

    return app.exec();
}