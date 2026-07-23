#include "mainwindow.h"

#include <QStackedWidget>

#include "pages/homepage.h"
#include "pages/monitorpage.h"
#include "pages/settingspage.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_pageStack(nullptr),
      m_homePage(nullptr),
      m_monitorPage(nullptr),
      m_settingsPage(nullptr)
{
    initializeUi();
}

MainWindow::~MainWindow() = default;

void MainWindow::initializeUi()
{
    setWindowTitle("IMX6ULL Vehicle Terminal");
    setFixedSize(1024, 600);

    // 创建页面容器和两个页面
    m_pageStack = new QStackedWidget(this);
    m_homePage = new HomePage(m_pageStack);
    m_monitorPage = new MonitorPage(m_pageStack);
    m_settingsPage = new SettingsPage(m_pageStack);
    // 将两个页面加入页面容器
    m_pageStack->addWidget(m_homePage);
    m_pageStack->addWidget(m_monitorPage);
    m_pageStack->addWidget(m_settingsPage);
    // 首页请求进入监控页
    connect(m_homePage,
            &HomePage::monitorRequested,
            this,
            &MainWindow::showMonitorPage);

    // 监控页请求返回首页
    connect(m_monitorPage,
            &MonitorPage::backRequested,
            this,
            &MainWindow::showHomePage);

    connect(m_homePage,
                &HomePage::settingRequested,
                this,
                &MainWindow::showSettingsPage);

    connect(m_settingsPage,
        &SettingsPage::backRequested,
        this,
        &MainWindow::showHomePage);

    

    // 程序启动时默认显示首页
    m_pageStack->setCurrentWidget(m_homePage);

    // 将页面容器设置为主窗口的中央控件
    setCentralWidget(m_pageStack);
}

void MainWindow::showHomePage()
{
    m_pageStack->setCurrentWidget(m_homePage);
}

void MainWindow::showMonitorPage()
{
    m_pageStack->setCurrentWidget(m_monitorPage);
}

void MainWindow::showSettingsPage()
{
    m_pageStack->setCurrentWidget(m_settingsPage);
}
