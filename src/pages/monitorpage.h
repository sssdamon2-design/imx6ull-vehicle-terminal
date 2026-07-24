#ifndef MONITORPAGE_H
#define MONITORPAGE_H

#include <QWidget>
#include "services/systeminfoservice.h"
class QLabel;
class QPushButton;
class QTimer;
class MonitorPage : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorPage(QWidget *parent = nullptr);
    ~MonitorPage() override;

signals:
    void backRequested();

private slots:
    void refreshSystemInfo();

private:
    void initializeUi();

    QLabel *m_titleLabel;
    QLabel *m_placeholderLabel;
    QLabel *m_cpuUsageLabel;
    QLabel *m_cpuTemperatureLabel;
    QLabel *m_cpuFrequencyLabel;
    QLabel *m_memoryLabel;
    QLabel *m_uptimeLabel;
    QLabel *m_Load_average;
    QLabel *m_Processes;
    QPushButton *m_backButton;
    QTimer *m_refreshTimer;
    SystemInfoservice m_systemInfoService;
};

#endif