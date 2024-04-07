#ifndef WATCH_H
#define WATCH_H

#include <QWidget>
#include "lights.h"
#include "patternMaker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Form;
}
QT_END_NAMESPACE

class Watch : public QWidget
{
    Q_OBJECT

private:
    Ui::Form* ui;

private:
    int m_base = 5;
    Lights* Hu[4];
    Lights* Hl[4];
    Lights* Mu[11];
    Lights* Ml[4];
    Lights* Su[11];
    Lights* Sl[4];

    PatternMaker* patternMaker = new PatternMaker(m_base);

public:
    Watch(QWidget *parent = nullptr);
    ~Watch();

private slots:
    void updateIndicator();
};
#endif // WATCH_H
