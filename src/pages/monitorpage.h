#ifndef MONITORPAGE_H
#define MONITORPAGE_H

#include <QWidget>

class QLabel;
class QPushButton;

class MonitorPage : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorPage(QWidget *parent = nullptr);
    ~MonitorPage() override;

signals:
    void backRequested();

private:
    void initializeUi();

    QLabel *m_titleLabel;
    QLabel *m_placeholderLabel;
    QPushButton *m_backButton;
};

#endif