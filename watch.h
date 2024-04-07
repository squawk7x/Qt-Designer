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

    RoundLight* roundLight;

    Light* Hu[4];
    Light* Hl[4];
    Light* Mu[11];
    Light* Ml[4];
    Light* Su[11];
    Light* Sl[4];

    PatternMaker* patternMaker;

public:
    explicit Watch(QWidget* parent = nullptr);
    ~Watch();

private slots:
    void updateIndicator();
};
#endif // WATCH_H
