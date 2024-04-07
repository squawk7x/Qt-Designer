#include "watch.h"
#include <QTimer>
#include "./ui_form.h"

Watch::Watch(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);

    patternMaker = new PatternMaker(5);

    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Hu%1").arg(i);
        Hu[i] = findChild<Lights *>(buttonName);
        Hu[i]->setWidth(Lights::Width::Large);
    }
    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Hl%1").arg(i);
        Hl[i] = findChild<Lights *>(buttonName);
        Hl[i]->setWidth(Lights::Width::Large);
    }
    for (int i = 0; i < 11; ++i) {
        QString buttonName = QString("Mu%1").arg(i);
        Mu[i] = findChild<Lights *>(buttonName);
    }
    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Ml%1").arg(i);
        Ml[i] = findChild<Lights *>(buttonName);
        Ml[i]->setWidth(Lights::Width::Large);
    }
    for (int i = 0; i < 11; ++i) {
        QString buttonName = QString("Su%1").arg(i);
        Su[i] = findChild<Lights *>(buttonName);
    }
    for (int i = 0; i < 4; ++i) {
        QString buttonName = QString("Sl%1").arg(i);
        Sl[i] = findChild<Lights *>(buttonName);
        Sl[i]->setWidth(Lights::Width::Large);
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Watch::updateIndicator);
    timer->start(1000);
}

void Watch::updateIndicator()
{
    patternMaker->makePatterns();
    for (int i = 0; i < 4; ++i) {
        Hu[i]->setColor((patternMaker->m_Hu[i] == 1) ? Lights::Bright_Red : Lights::Dark_Red);
        Hl[i]->setColor((patternMaker->m_Hl[i] == 1) ? Lights::Bright_Red : Lights::Dark_Red);
        Ml[i]->setColor((patternMaker->m_Ml[i] == 1) ? Lights::Bright_Yellow : Lights::Dark_Yellow);
        Sl[i]->setColor((patternMaker->m_Sl[i] == 1) ? Lights::Bright_Yellow : Lights::Dark_Yellow);
    }
    for (int i = 0; i < 11; ++i) {
        Mu[i]->setColor((patternMaker->m_Mu[i] == 1)
                            ? (((i + 1) % 3 == 0) ? Lights::Bright_Red : Lights::Bright_Yellow)
                            : (((i + 1) % 3 == 0) ? Lights::Dark_Red : Lights::Dark_Yellow));

        Su[i]->setColor((patternMaker->m_Su[i] == 1)
                            ? (((i + 1) % 3 == 0) ? Lights::Bright_Red : Lights::Bright_Yellow)
                            : (((i + 1) % 3 == 0) ? Lights::Dark_Red : Lights::Dark_Yellow));
    }
}

Watch::~Watch()
{
    delete ui;
}
