#include "monitorpage.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

MonitorPage::MonitorPage(QWidget *parent)
    : QWidget(parent),
      m_titleLabel(nullptr),
      m_placeholderLabel(nullptr),
      m_backButton(nullptr)
{
    initializeUi();
}

MonitorPage::~MonitorPage() = default;

void MonitorPage::initializeUi()
{
    setObjectName("monitorPage");

    m_titleLabel = new QLabel("Environment Monitor", this);
    m_titleLabel->setAlignment(Qt::AlignCenter);
    m_titleLabel->setObjectName("titleLabel");

    m_placeholderLabel =new QLabel("Sensor module will be added later", this);
    m_placeholderLabel->setAlignment(Qt::AlignCenter);
    m_placeholderLabel->setObjectName("placeholderLabel");

    m_backButton = new QPushButton("Back", this);
    m_backButton->setFocusPolicy(Qt::NoFocus);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(60, 40, 60, 40);
    mainLayout->setSpacing(30);

    mainLayout->addWidget(m_titleLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(m_placeholderLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(m_backButton);

    connect(m_backButton,
            &QPushButton::clicked,
            this,
            &MonitorPage::backRequested);

    setStyleSheet(
        "#monitorPage {"
        "    background-color: #202733;"
        "}"
        "#titleLabel {"
        "    color: white;"
        "    font-size: 38px;"
        "    font-weight: bold;"
        "}"
        "#placeholderLabel {"
        "    color: #b8c4d6;"
        "    font-size: 25px;"
        "}"
        "QPushButton {"
        "    min-height: 80px;"
        "    color: white;"
        "    background-color: #334155;"
        "    border: 2px solid #52637a;"
        "    border-radius: 16px;"
        "    font-size: 26px;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #ef4444;"
        "    border: 4px solid white;"
        "}"
    );
}