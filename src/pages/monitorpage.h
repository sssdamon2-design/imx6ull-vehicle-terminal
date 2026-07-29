#ifndef MONITORPAGE_H
#define MONITORPAGE_H

#include <QWidget>
#include "services/systeminfoservice.h"
#include "services/dht11service.h"
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
    void refreshDht11Data();
public slots:
    void startDht11Monitoring();
    void stopDht11Monitoring();


private:
    void initializeUi();

    QLabel *m_titleLabel;
    //QLabel *m_placeholderLabel;
    QLabel *m_cpuUsageLabel;
    QLabel *m_cpuTemperatureLabel;
    QLabel *m_cpuFrequencyLabel;
    QLabel *m_memoryLabel;
    QLabel *m_uptimeLabel;
    QLabel *m_Load_average;
    QLabel *m_Processes;
    QPushButton *m_backButton;
    QTimer *m_refreshTimer;
    QTimer *m_dht11Timer;
    SystemInfoservice m_systemInfoService;
    QLabel *m_temperatureLabel;
    QLabel *m_humidityLabel;
    QLabel *m_dht11StatusLabel;
    DHT11Service *m_dht11Service;  //这里是创建一个指向DHT11Service类的指针
};

#endif