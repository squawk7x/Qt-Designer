#include "watch.h"
#include <QTimer>
#include "ui_form.h" //include user interface

Watch::Watch(QWidget *parent)
    : QWidget(parent)  // subclass a standard Qt widget
    , ui(new Ui::Form) // include private instance of ui
{
    ui->setupUi(this);
    // ui->retranslateUi(this); // for language changes

    // setAttribute(Qt::WA_TranslucentBackground);

    roundLight = new RoundLight(findChild<RoundLight *>("blinker"));

    roundLight->setStyleSheet("QPushButton { border-radius: 70px; background-color: #808000; }");

    patternMaker = new PatternMaker(5);

    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Hu%1").arg(i);
        Hu[i] = findChild<Light *>(buttonName);
        Hu[i]->setWidth(Light::Width::Large);
    }
    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Hl%1").arg(i);
        Hl[i] = findChild<Light *>(buttonName);
        Hl[i]->setWidth(Light::Width::Large);
    }
    for (int i = 0; i < 11; ++i) {
        QString buttonName = QString("Mu%1").arg(i);
        Mu[i] = findChild<Light *>(buttonName);
    }
    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Ml%1").arg(i);
        Ml[i] = findChild<Light *>(buttonName);
        Ml[i]->setWidth(Light::Width::Large);
    }
    for (int i = 0; i < 11; ++i) {
        QString buttonName = QString("Su%1").arg(i);
        Su[i] = findChild<Light *>(buttonName);
    }
    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Sl%1").arg(i);
        Sl[i] = findChild<Light *>(buttonName);
        Sl[i]->setWidth(Light::Width::Large);
    }

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Watch::updateIndicator);
    timer->start(1000);
}

void Watch::updateIndicator()
{
    patternMaker->makePatterns();

    static bool isDarkYellow = true; // Variable to toggle color state
    if (isDarkYellow) {
        roundLight->setStyleSheet(
            "QPushButton { border-radius: 70px; background-color: #808000; }");
    } else {
        roundLight->setStyleSheet(
            "QPushButton { border-radius: 70px; background-color: #FFFF00; }");
    }
    isDarkYellow = !isDarkYellow;

    for (int i = 0; i < 4; ++i) {
        Hu[i]->setColor((patternMaker->m_Hu[i] == 1) ? Light::Bright_Red : Light::Dark_Red);
        Hl[i]->setColor((patternMaker->m_Hl[i] == 1) ? Light::Bright_Red : Light::Dark_Red);
        Ml[i]->setColor((patternMaker->m_Ml[i] == 1) ? Light::Bright_Yellow : Light::Dark_Yellow);
        Sl[i]->setColor((patternMaker->m_Sl[i] == 1) ? Light::Bright_Yellow : Light::Dark_Yellow);
    }
    for (int i = 0; i < 11; ++i) {
        Mu[i]->setColor((patternMaker->m_Mu[i] == 1)
                            ? (((i + 1) % 3 == 0) ? Light::Bright_Red : Light::Bright_Yellow)
                            : (((i + 1) % 3 == 0) ? Light::Dark_Red : Light::Dark_Yellow));

        Su[i]->setColor((patternMaker->m_Su[i] == 1)
                            ? (((i + 1) % 3 == 0) ? Light::Bright_Red : Light::Bright_Yellow)
                            : (((i + 1) % 3 == 0) ? Light::Dark_Red : Light::Dark_Yellow));
    }
}

Watch::~Watch()
{
    delete patternMaker;
    delete roundLight;
    delete ui;
}
