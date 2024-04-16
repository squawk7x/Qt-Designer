#ifndef WATCHUI_H
#define WATCHUI_H

#include <QWidget>
#include "lights.h"
#include "patternMaker.h"
#include "qcheckbox.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Form;
}
QT_END_NAMESPACE

class WatchUi : public QWidget
{
    Q_OBJECT

public:
    explicit WatchUi(QWidget* parent = nullptr);
    virtual ~WatchUi();

private:
    Ui::Form* ui;
    // or include private static instance:
    // Ui::Form ui;
    QCheckBox* cb_roundLight;
    QCheckBox* cb_transparency;

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

private slots:
    void updateIndicator();
    void updateRoundLight(bool checked);
    void updateTransparency(bool checked);
    void on_ui_roundLight_clicked();
};
#endif // WATCHUI_H
